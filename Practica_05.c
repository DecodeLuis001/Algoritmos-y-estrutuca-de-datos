#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int NUA;
	char *Nombre;
}
Alumnado;

Alumnado *Usuario; //Vector dinamico.

void Registro();
void Liberar_Memoria(char Auxiliar[]);
void Contenido(char Auxiliar[], int i);


int main()
{
	Registro();

	return 0;
}

void Registro()
{
	int i, j, Contador=0;
	char Auxiliar[50];
	char Temporal;
	FILE *Archivo;

	Archivo=fopen("Registro.txt", "r"); //w+rb+
	if(Archivo==NULL)
	{
		printf("No se ha podido habrir el archivo.\n");
		exit(1);
	}

	while(!feof(Archivo))
	{	//Lee toda la linea de texto, hasta llegar al salto de linea.
		fgets(Auxiliar, 50, Archivo); //Almacena en un string temporal. "Auxiliar"
		Contador++; //Cada que se lee una linea se incrementa hasta llegar al final del archivo.
	}
	rewind(Archivo); //Pone el cursor al inicio del fichero.

	//Crea el espacio de memoria de forma dinamica.
	Usuario=(Alumnado *)malloc(Contador* sizeof(Alumnado));

	/*
	printf("Ingrese el nombre del usuario.\n");
	fgets(Auxiliar, 50, stdin);
	while(!feof(Archivo)) //Expresa que se llego al final del fichero.
	{
		fgets(Auxiliar, 50, Archivo);
		printf("La frase introducida es: %s\n",Auxiliar);	
	}
	fprintf(Archivo, "La frase introducida es: %s\n",Auxiliar);
	printf("\n");*/

	if(Usuario==NULL)
	{
		printf("No se ha podido crear el listado.\n");
		exit(1);
	}

	for(i=0; !feof(Archivo); i++) //Lee el fichero, la condición de en medio indica que se llego al final del fichero.
	{
		Liberar_Memoria(Auxiliar); //Elimina datos basura del fichero.
		Temporal='0';
		for(j=0; Temporal!=','; j++) //Establece que se continua leyendo hasta la coma en el fichero.
		{
			Temporal=fgetc(Archivo); //Toma uno a uno los elementos del fichero hasta llegar al guión.
			if(Temporal!=',')
			{
				Auxiliar[j]=Temporal; //Copia los elementos alamcenados en el auxiliar. (Solo el nombre)
			}
		}
		Contenido(Auxiliar, i); //El cursor se encuentra despues de la coma.

		//El 10 es los caracteres maximos que puede tomar.
		fgets(Auxiliar, 10, Archivo); //Toma datos de la coma en adelante.
		Usuario[i].NUA=atoi(Auxiliar); //Gracias al 10 se toma los caracteres de salto de linea y espacio.
		//atoi: pasa numeros de cadenas de caracteres a enteros.
		printf("Alumno: %s; \t\t N.U.A: %d\n", Usuario[i].Nombre, Usuario[i].NUA);
	}
	fclose(Archivo);
}

void Liberar_Memoria(char Auxiliar[])
{
	int i;

	for(i=0; i<50; i++)
	{
		Auxiliar[i]='\0'; //Elimina la cadena de caracteres contenida.
	}
}

void Contenido(char Auxiliar[], int i) //Mete el contenido del auxiliar dentro del string dinamico.
{	//Reserva memoria para el string dinamico.
	int Lectura = strlen(Auxiliar)+1; //El uno es para que no sume el salto de linea o espacio.
	//cuenta la cantidad de carcateres dentro de auxiliar pero no el carcater de final de linea.
	Usuario[i].Nombre=(char *)malloc(Lectura*sizeof(char));

	if(Usuario[i].Nombre==NULL)
	{
		printf("No se ha podido crear el listado.\n");
		exit(1);
	}
	//Copia los strings en la variable auxiliar 
	strcpy(Usuario[i].Nombre, Auxiliar);
	//El primer termino es el destino.
	//El segundo termino es la fuente.
	//La i identifica el usuario en el vector. 
}
