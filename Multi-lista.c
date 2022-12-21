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

typedef struct Registros
{
    int NUA;
    int Dato;
    struct Registros *Siguiente_NUA; 
}
Registros;

Registros* Primero=NULL;
Registros* Ultimo=NULL;
Nodo *Usuario; //Crea un vector dinámico. 
int Nodo_Encontrado=0, Busqueda_Nodo=0; //Sirven de bandera para poder ejecutar condición de verdad o falso si es que se encontro un nua al momento de buscar.

void Registro(char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos);
void Ordenar_Nombres(char Nombre[][20], Nodo *Sujetos);
void Ordenar_ApellidoP(char ApellidoP[][20], Nodo *Sujetos);
void Ordenar_ApellidoM(char ApellidoM[][20], Nodo *Sujetos);
void Crear_NUA();
void Mostrar_Registro(int i, char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos);
void Eliminar_NUA();
void NUA_Ordenando(int i, char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos);
void Registro_Nua_Orden(int i, char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos);

/*int main()
{
	Nodo* Sujetos=(Nodo *)malloc(sizeof(Nodo));
	char Nombre[Sujetos->data-1][20];
	char ApellidoP[Sujetos->data-1][20];
	char ApellidoM[Sujetos->data-1][20];

	Registro(Nombre, ApellidoP, ApellidoM,Sujetos);
	Ordenar_Nombres(Nombre, Sujetos);
	Ordenar_ApellidoP(ApellidoP, Sujetos);
	Ordenar_ApellidoM(ApellidoM, Sujetos);

    Mostrar_NUA();

	return 0;
}*/

int main()
{
    Nodo* Sujetos=(Nodo *)malloc(sizeof(Nodo));
    int i, Opciones=0;
    char Nombre[Sujetos->data-1][20];
    char ApellidoP[Sujetos->data-1][20];
    char ApellidoM[Sujetos->data-1][20];

    do
    {
        //inicio:
        printf("--->Eliga la opción que deseé.\n");
        printf("1) Ingresar un nuevo estudiante al registro.\n");
        printf("2) Mostrar la base de datos (NUAs).\n");
        printf("3) Mostar la base de datos dependiente a: \n");
        printf("4) Borrar un estudiante del registro.\n");
        printf("5) Salir del programa.\n");
        scanf("%d", &Opciones);
        if(Opciones<=0 || Opciones>=6)
        {
            printf("Se ha salido del rango de opciones intentelo nuevamente.\n");
        }

        switch(Opciones)
        {
            case 1:
            {
                Registro(Nombre, ApellidoP, ApellidoM, Sujetos);
            }
            break;
            case 2:
            {
                printf("Estos son los NUA ingresados hasta el momento.\n");
                Mostrar_Registro(i, Nombre, ApellidoP, ApellidoM, Sujetos);
            }
            break;
            case 3:
            {
                int back=1;

                do
                {
                    int Casos=0;

                    do
                    {
                        printf("Eliga la opción que deseé:\n");
                        printf("1). Mostar la lista ordenada por N.U.A\n");     
                        printf("2). Mostrar la lista ordenda por nombre del alumno.\n");
                        printf("3). Mostrar la lista ordenada por apellido paterno.\n");
                        printf("4). Mostrar la lista ordenada por apellido paterno.\n");
                        printf("5). Volver al menú original.\n");
                        printf("6). Salir del programa.\n");
                        scanf("%d", &Casos);
                        if(Casos<=0 || Casos>=7)
                        {
                            printf("La opción es invalida, por favor intentelo de nuevo.\n");
                        }

                        switch(Casos)
                        {
                            case 1:
                            {
                                printf("--->Lista ordenada por NUA.\n");
                                NUA_Ordenando(i, Nombre, ApellidoP, ApellidoM, Sujetos);
                                printf("Se ha generado un archivo con los NUA´s en orden.\n");
                                Registro_Nua_Orden(i, Nombre, ApellidoP, ApellidoM, Sujetos);
                            }
                            break;
                            case 2:
                            {
                                printf("--->Lista ordenada por nombre.\n");
                                Ordenar_Nombres(Nombre, Sujetos);
                            }
                            break;
                            case 3:
                            {
                                printf("--->Lista ordenada por apellido paterno.\n");
                                Ordenar_ApellidoP(ApellidoP, Sujetos);
                            }
                            break;
                            case 4:
                            {
                                printf("--->Lista ordenada por apellido materno.\n");
                                Ordenar_ApellidoM(ApellidoM, Sujetos);
                            }
                            break;
                            case 5: 
                            {
                                printf("Regreso al menú principal.\n");
                                //goto inicio; 
                            }
                            break;
                            case 6:
                            {
                                printf("Ha salido del programa.\n");
                                exit(0);
                            }
                            break;
                        }
                    }
                    while(Casos<=5);
                }
                while(back==1);
            }
            break;
            case 4:
            {   
                printf("Digíte el valor del NUA a eliminar.\n");
                Eliminar_NUA();
                //No pude hacer que se eliminaran las cadenas de caracteres una disculpa :""v
            }
            break;              
            case 5:
            {
                printf("Ha salido del programa.\n");
                exit(0);
            }
            break;
        }
    }
    while(Opciones<=5);
}

void Registro(char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos)
{	 
	FILE *Archivo; 

	printf("¿Cuantós usuarios desea registrar?.\n");
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
			char Temporal;

			for(i=0; i<Sujetos->data; i++)
			{	
				Usuario=(Nodo *)malloc(Contador* sizeof(Nodo));

                Crear_NUA();
                printf("\n");
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


void Crear_NUA()
{
    FILE* Archivo;
    Registros* Nuevo_Nua=(Registros *)malloc(sizeof(Registros));

    printf("Ingrese el nuevo N.U.A a registrar.\n");
    scanf("%d", &Nuevo_Nua->Dato);

    if(Primero==NULL) //Establece la condición para crear el nodo y posteriormente la lista.
    {   //Se establece una condición de pila circular.
        Primero=Nuevo_Nua;
        Primero->Siguiente_NUA=NULL; //En caso de que el siguiente dato a ingresar sea el ultimo.
        Ultimo=Nuevo_Nua;
    } 
    else //Para que se pueda agregar un nodo centrico.
    { //Forma el cuerpo de la lista.
        Ultimo->Siguiente_NUA=Nuevo_Nua;
        Nuevo_Nua->Siguiente_NUA=NULL;
        Ultimo=Nuevo_Nua;
    }
    printf("El dato: %d fue ingresado.\n",Nuevo_Nua->Dato);
    //fprintf(Archivo, "N.U.A: [%d]\n",Nuevo_Nua->data);
}

void Mostrar_Registro(int i, char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos)
{
    Registros* Nodo_Actual=(Registros *)malloc(sizeof(Registros)); //Permite recorrer la lista.
    Nodo_Actual = Primero;  //Establece que existe un pirmer valor en la lista.

    if(Primero!=NULL) //Indica que la cola no existe.
    {  
        do
        {   
            for(i=0; i<Sujetos->data; i++)
            {
                printf("El usuario: %s; \t %s; \t %s; \t con el N.U.A: [%d] fue registrado.\n",Nombre[i], ApellidoP[i], ApellidoM[i], Nodo_Actual->Dato);
            } 
            Nodo_Actual=Nodo_Actual->Siguiente_NUA; //Actualiza el apuntador.
        }
        while(Nodo_Actual!=NULL); //Recorre la lista e imprime los valores ingresados.
    } 
    else
    {
        printf("No hay elementos en la lista.\n");
    }
    printf("\n");
}

void Eliminar_NUA() 
{
    Registros* Nodo_Actual=(Registros *)malloc(sizeof(Registros)); //Permite recorrer la lista
    Nodo_Actual = Primero; //Establece que existe un pirmer valor en la lista.
    
    Registros* Nodo_anterior=(Registros *)malloc(sizeof(Registros)); //Guarda el valor del apuntador actual.
    Nodo_anterior=NULL; 

    printf("Ingrese el valor del Nodo a Buscar para Eliminar: ");
    scanf("%d", &Busqueda_Nodo);

    if(Primero!=NULL) 
    {
        while(Nodo_Actual!=NULL && Nodo_Encontrado!=1)
        {
            if(Nodo_Actual->Dato==Busqueda_Nodo) 
            {   
                //Existen tres casos cuando se quiere eliminar un elemento
                if(Nodo_Actual==Primero) //Primer caso: El primer elemento es el que sale.
                {
                    Primero=Primero->Siguiente_NUA; //El primer dato pasa a apuntar al siguiente.
                    //Hace que la lista se recorra.
                }       
                else //Establece que hay condiciones adicionales.
                    if(Nodo_Actual==Ultimo) //El ultimo elemento es el que sale.
                    {
                        Nodo_anterior->Siguiente_NUA=NULL; //Establece que ya no hay mas datos que ingresar.
                        Ultimo=Nodo_anterior; //Si no hay datos que ingresar, el ultimo dato es el que sale.
                        //Si el ultimo dato es que sale, entonces el antepenultimo dato se vuelve el ultimo.
                    } 
                else //En caso de que el dato este en el medio de la lista.
                {   //El Nodo_anterior alamcena los datos del centro de la lista.
                    //como anterior alamcena el centro, cuando avance alsiguiente dato, el anterior se vuelve el elemento actual
                    //El elemento actual es el que sale.
                    Nodo_anterior->Siguiente_NUA=Nodo_Actual->Siguiente_NUA;
                }
                printf("El elemento ha sido eliminado con exito.\n");
                Nodo_Encontrado=1; //Cuando existe un nodo al cual modificar.
            }
            Nodo_anterior=Nodo_Actual;  
            Nodo_Actual=Nodo_Actual->Siguiente_NUA; //Actualiza el apuntador.
        }
        if(Nodo_Encontrado==0) //En caso de que el usuario se equivoque al digitar el numero.
        {
            printf("El elemento no se ha encontrado.\n");
        }
        else
        {
            free(Nodo_anterior); //Borra el espacio de memoria asignado.
        }
    } 
    else
    {
        printf("La lista no existe, no tiene elementos\n");
    }
}

void NUA_Ordenando(int i, char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos)
{
    Registros* Nodo_Actual=(Registros *)malloc(sizeof(Registros));
    Nodo_Actual=Primero; //Establece que se comparen los elementos.
    //Al ordenar mediante burbuja evita que cause el segmentation fault.
    Registros* Pivote=(Registros *)malloc(sizeof(Registros));

    int auxiliar=0; //Alamcena el dato a comparar.

    if(Primero!=NULL)
    {
        printf("Los N.U.A´s ordenados de menor a mayor son: \n");
        printf("\n");
        Pivote=Primero; //Modifica el valor del pivote.
        //Hace que el nodo se compare meidante saltos.
        while(Nodo_Actual!=NULL) //Establece un ciclo for con un indice abstrato i.
        {
            //Recorre el arreglo de modo que el valor del nodo se modifique.
            Pivote=Nodo_Actual->Siguiente_NUA; 
            
            while(Pivote!=NULL) //Establece un ciclo for con un indice abstrato j.
            {
                if(Nodo_Actual->Dato > Pivote->Dato)
                {
                    //Equivale a un orden de burbuja con indices.
                    /*
                    siendo auxiliar el alamcen de datos
                    Nodo actual que apunta al dato es el indice i.
                    Nodo pivote que apunta al mismo dato es el indice j.
                    */
                    auxiliar=Nodo_Actual->Dato;         
                    Nodo_Actual->Dato=Pivote->Dato;
                    Pivote->Dato=auxiliar;
                }
                Pivote=Pivote->Siguiente_NUA; //Hace que el pivote se recorra si el dato siguiente es mayor.    
            }
            printf("N.U.A: [%d]; %s \t %s \t %s \t\n", Nodo_Actual->Dato, Nombre[i], ApellidoP[i], ApellidoM[i]);
            Nodo_Actual=Nodo_Actual->Siguiente_NUA; //Actualiza el apuntador.
        }   
    }
    else
    {
        printf("No tiene elementos en la lista.\n");
    }
    printf("\n");   
}

void Registro_Nua_Orden(int i, char Nombre[][20], char ApellidoP[][20], char ApellidoM[][20], Nodo *Sujetos)
{
    FILE* Archivo;
    Registros* Nodo_Actual=(Registros *)malloc(sizeof(Registros));
    Nodo_Actual=Primero; //Establece que se comparen los elementos.
    //Al ordenar mediante burbuja evita que cause el segmentation fault.
    Registros* Pivote=(Registros *)malloc(sizeof(Registros));

    int auxiliar=0; //Alamcena el dato a comparar.

    Archivo=fopen("NUA_Ordenos.txt", "a+rb+");
    if(Archivo==NULL)
    {
        printf("No se ha podido habrir el archivo.\n");
        exit(0);
    }
    else
    {
        if(Primero!=NULL)
        {
            fprintf(Archivo, "Los N.U.A´s ordenados de menor a mayor son: \n");
            printf("\n");
            Pivote=Primero; //Modifica el valor del pivote.
            //Hace que el nodo se compare meidante saltos.
            while(Nodo_Actual!=NULL) //Establece un ciclo for con un indice abstrato i. 
            {
                //Recorre el arreglo de modo que el valor del nodo se modifique.
                Pivote=Nodo_Actual->Siguiente_NUA; 
            
                while(Pivote!=NULL) //Establece un ciclo for con un indice abstrato j.
                {
                    if(Nodo_Actual->Dato > Pivote->Dato)
                    {
                        //Equivale a un orden de burbuja con indices.
                        /*
                        siendo auxiliar el alamcen de datos
                        Nodo actual que apunta al dato es el indice i.
                        Nodo pivote que apunta al mismo dato es el indice j.
                        */
                        auxiliar=Nodo_Actual->Dato;         
                        Nodo_Actual->Dato=Pivote->Dato;
                        Pivote->Dato=auxiliar;
                    }
                    Pivote=Pivote->Siguiente_NUA; //Hace que el pivote se recorra si el dato siguiente es mayor.
                }
                fprintf(Archivo, "N.U.A: [%d]; %s \t %s \t %s \t\n", Nodo_Actual->Dato, Nombre[i], ApellidoP[i], ApellidoM[i]);
                Nodo_Actual=Nodo_Actual->Siguiente_NUA; //Actualiza el apuntador.
            }
        }
        else
        {
            printf("No tiene elementos en la lista.\n");
        }
    }
    fclose(Archivo);
}