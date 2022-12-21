#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nodo 
{
	int NUA;
	int data;
	char *Nombre;
	char *ApellidoPaterno; 
	char *ApellidoMaterno; 
}
Nodo;

Nodo *Usuario; //Crea un vector dinámico. 

void Registro(char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos);
void Ordenar_Nombres(char Nombre[][20], Nodo *Sujetos);
void Ordenar_ApellidoP(char ApellidoP[][20], Nodo *Sujetos);
void Ordenar_ApellidoM(char ApellidoM[][20], Nodo *Sujetos);

int main(void)
{
	Nodo* Sujetos=(Nodo *)malloc(sizeof(Nodo));
	char Nombre[Sujetos->data-1][20];
	char ApellidoP[Sujetos->data-1][20];
	char ApellidoM[Sujetos->data-1][20];

	Registro(Nombre, ApellidoP, ApellidoM,Sujetos);
	Ordenar_Nombres(Nombre, Sujetos);
	Ordenar_ApellidoP(ApellidoP, Sujetos);
	Ordenar_ApellidoM(ApellidoM, Sujetos);

	return 0;
}

void Registro(char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos)
{	 
	FILE *Archivo; 

	printf("¿Cuantós nombres desea registrar?.\n");
	scanf("%d", &Sujetos->data);

	if(Sujetos->data>=1)
	{
		Archivo=fopen("Usuarios.txt", "a+rb+");
		if(Archivo==NULL)
		{
			printf("No se ha podido habrir el archivo.\n");
			exit(0);
		}
		else
		{
			int i,j, Contador=0;
			//char Nombre[Sujetos->data-1][20];
			//char ApellidoP[Sujetos->data-1][20];
			//char ApellidoM[Sujetos->data-1][20];
			char Temporal;

			for(i=0; i<Sujetos->data; i++)
			{	
				Usuario=(Nodo *)malloc(Contador* sizeof(Nodo));

				printf("Ingrese el nombre del usuario: \n");
				scanf("%s", Nombre[i]);
				printf("Ingrese el apellido paterno del usuario.\n");
				scanf("%s", ApellidoP[i]);
				printf("Ingrese el apellido materno del usuario.\n");
				scanf("%s", ApellidoM[i]);

				if(Usuario==NULL)
				{
					printf("No se ha podido crear el listado.\n");
					exit(1);
				}

				do 
				{
					fgets(Nombre[i], 20, Archivo);
					fgets(ApellidoP[i], 20, Archivo);
					fgets(ApellidoM[i], 20, Archivo);
					printf("El usuario: %s; %s; %s; fue registrado.\n",Nombre[i], ApellidoP[i], ApellidoM[i]);
				}
				while(!feof(Archivo)); //Expresa que se llego al final del fichero.
				fprintf(Archivo, "Nombre: %s; \t Apellido paterno: %s; \t Apellido Materno: %s; \t \n",Nombre[i], ApellidoP[i], ApellidoM[i]);
			}
		}
		fclose(Archivo);
	}
	else
	{
		printf("La lista esta vacia.\n");
		exit(0);
	}	
}

void Ordenar_Nombres(char Nombre[][20], Nodo *Sujetos)
{
    FILE* Archivo;
    int i, j;
    float Comparador; //sirve como medio de almacenamiento para la comparacion entre palabras (dado que cada letra recibe un valor númerico dependiendo su posición en el abecedario, esto para saber que eltra va despues de otra)
    char Auxiliar[20]; //proporcionara una variable en donde se depositan los nombre para después compararlos.
    for(i=0; i<Sujetos->data; i++)//Ciclo que realiza el proceso de ordenamiento, explora las letras de cada palabra dentro del arreglo.
    {
    	for(j=0; j<Sujetos->data-1; j++) 
    	{
            //el comando "strmcp" busca realizar la comparación de las palabras dentro del arreglo.
    		Comparador = strcmp(Nombre[j], Nombre[j+1]);
        	if(Comparador>0)
            {
                //el comando "strcpy" copia el contenido de la cadena que se seleccione y la deposita en una variable destino, la función de la coma dentro del comando tiene una similitud al simbolo de igual.
                strcpy(Auxiliar,Nombre[j]);
            	strcpy(Nombre[j],Nombre[j+1]);
            	strcpy(Nombre[j+1],Auxiliar);
            }
        }
    }
    printf("\n");

    printf("Los nombres ordenados del arrelgo son: \n");
    for(i=0; i<Sujetos->data; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
    {
        printf("%d.- %s\n",i+1, Nombre[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
    }
    
    Archivo=fopen("Usuarios_Ordenados.txt", "a+rb+");
    if(Archivo==NULL)
    {
        printf("No se ha podido habrir el archivo.\n");
        exit(0);
    }
    else
    {
        fprintf(Archivo, "Los usuario ordenados por nombre son: \n");
        for(i=0; i<Sujetos->data; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
        {   
            fprintf(Archivo, "Usuario[%d].- %s\n",i+1, Nombre[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
        }
    }
    fclose(Archivo);
}

void Ordenar_ApellidoP(char ApellidoP[][20], Nodo *Sujetos)
{
    FILE* Archivo;
    int i, j;
    float Comparador; //sirve como medio de almacenamiento para la comparacion entre palabras (dado que cada letra recibe un valor númerico dependiendo su posición en el abecedario, esto para saber que eltra va despues de otra)
    char Auxiliar[20]; //proporcionara una variable en donde se depositan los nombre para después compararlos.
    for(i=0; i<Sujetos->data; i++)//Ciclo que realiza el proceso de ordenamiento, explora las letras de cada palabra dentro del arreglo.
    {
    	for(j=0; j<Sujetos->data-1; j++) 
    	{
            //el comando "strmcp" busca realizar la comparación de las palabras dentro del arreglo.
    		Comparador = strcmp(ApellidoP[j], ApellidoP[j+1]);
        	if(Comparador>0)
            {
                //el comando "strcpy" copia el contenido de la cadena que se seleccione y la deposita en una variable destino, la función de la coma dentro del comando tiene una similitud al simbolo de igual.
                strcpy(Auxiliar,ApellidoP[j]);
            	strcpy(ApellidoP[j],ApellidoP[j+1]);
            	strcpy(ApellidoP[j+1],Auxiliar);
            }
        }
    }
    printf("\n");

    printf("Los apellidos paternos ordenados del arrelgo son: \n");
    for(i=0; i<Sujetos->data; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
    {
        printf("%d.- %s\n",i+1, ApellidoP[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
    }
    
    Archivo=fopen("Usuarios_Ordenados.txt", "a+rb+");
    if(Archivo==NULL)
    {
        printf("No se ha podido habrir el archivo.\n");
        exit(0);
    }
    else
    {
        fprintf(Archivo, "Los usuario ordenados por apellido paterno son: \n");
        for(i=0; i<Sujetos->data; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
        {   
            fprintf(Archivo, "Usuario[%d].- %s\n",i+1, ApellidoP[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
        }
    }
    fclose(Archivo);
}

void Ordenar_ApellidoM(char ApellidoM[][20], Nodo *Sujetos)
{
    FILE* Archivo;
    int i, j;
    float Comparador; //sirve como medio de almacenamiento para la comparacion entre palabras (dado que cada letra recibe un valor númerico dependiendo su posición en el abecedario, esto para saber que eltra va despues de otra)
    char Auxiliar[20]; //proporcionara una variable en donde se depositan los nombre para después compararlos.
    for(i=0; i<Sujetos->data; i++)//Ciclo que realiza el proceso de ordenamiento, explora las letras de cada palabra dentro del arreglo.
    {
    	for(j=0; j<Sujetos->data-1; j++) 
    	{
            //el comando "strmcp" busca realizar la comparación de las palabras dentro del arreglo.
    		Comparador = strcmp(ApellidoM[j], ApellidoM[j+1]);
        	if(Comparador>0)
            {
                //el comando "strcpy" copia el contenido de la cadena que se seleccione y la deposita en una variable destino, la función de la coma dentro del comando tiene una similitud al simbolo de igual.
                strcpy(Auxiliar,ApellidoM[j]);
            	strcpy(ApellidoM[j],ApellidoM[j+1]);
            	strcpy(ApellidoM[j+1],Auxiliar);
            }
        }
    }
    printf("\n");

    printf("Los apellidos maternos ordenados del arrelgo son: \n");
    for(i=0; i<Sujetos->data; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
    {
        printf("%d.- %s\n",i+1, ApellidoM[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
    }
    
    Archivo=fopen("Usuarios_Ordenados.txt", "a+rb+");
    if(Archivo==NULL)
    {
        printf("No se ha podido habrir el archivo.\n");
        exit(0);
    }
    else
    {
        fprintf(Archivo, "Los usuario ordenados por Apellidos Maternos son: \n");
        for(i=0; i<Sujetos->data; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
        {   
            fprintf(Archivo, "Usuario[%d].- %s\n",i+1, ApellidoM[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
        }
    }
    fclose(Archivo);
}