#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Registro_Nombre();
void Ordenar_Nombres(char Nombres[][20], int sujetos);

int main()
{
    Registro_Nombre();
    return 0;
}

void Registro_Nombre()
{
    int sujetos;

    printf("¿Cuantos nombres desea ordenar?\n");
    scanf("%d", &sujetos);

    int i;
    char Nombres[sujetos-1][20];

    for(i=0; i<sujetos; i++)
    {                 //al ser aregglo de dipo char el amperson no es necesrio para la lectura del arreglo.
        printf("Ingrese el nombre del usuario: \n");
        scanf("%s", Nombres[i]);
    }

    Ordenar_Nombres(Nombres, sujetos);

    //return 0;
}

void Ordenar_Nombres(char Nombres[][20], int sujetos)
{
    FILE* Archivo;
    int i, j;
    float Comparador; //sirve como medio de almacenamiento para la comparacion entre palabras (dado que cada letra recibe un valor númerico dependiendo su posición en el abecedario, esto para saber que eltra va despues de otra)
    char Auxiliar[20]; //proporcionara una variable en donde se depositan los nombre para después compararlos.

    for(i=0; i<sujetos; i++)//Ciclo que realiza el proceso de ordenamiento, explora las letras de cada palabra dentro del arreglo.
    {
    	for(j=0; j<sujetos-1; j++) 
    	{
            //el comando "strmcp" busca realizar la comparación de las palabras dentro del arreglo.
    		Comparador = strcmp(Nombres[j], Nombres[j+1]);
        	if(Comparador>0)
            {
                //el comando "strcpy" copia el contenido de la cadena que se seleccione y la deposita en una variable destino, la función de la coma dentro del comando tiene una similitud al simbolo de igual.
                strcpy(Auxiliar,Nombres[j]);
            	strcpy(Nombres[j],Nombres[j+1]);
            	strcpy(Nombres[j+1],Auxiliar);
            }
        }
    }
    printf("\n");

    printf("Los nombres ordenados del arrelgo son: \n");
    for(i=0; i<sujetos; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
    {
        printf("%d.- %s\n",i+1, Nombres[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
    }
    
    Archivo=fopen("Nombres_Ordenados.txt", "a+rb+");
    if(Archivo==NULL)
    {
        printf("No se ha podido habrir el archivo.\n");
        exit(0);
    }
    else
    {
        fprintf(Archivo, "Los usuario ordenados por nombre son: \n");
        for(i=0; i<sujetos; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
        {   
            fprintf(Archivo, "Usuario[%d].- %s\n",i+1, Nombres[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
        }
    }
    fclose(Archivo);
}
