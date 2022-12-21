//Escribir en un fichero de texto.

#include<stdio.h>
#include<stdlib.h>

void Cambio(char auxiliar[]);

int main()
{
	FILE* Archivo;
	int numero;
	char auxiliar[50];

	Archivo=fopen("NUA.txt", "w");
	if(Archivo==NULL)
	{
		printf("No se ha podido abrir el archivo.\n");
		exit(1);
	}
	//Registrara el dato para mandarlo al fichero.
	//printf("Introduce un numero.\n");
	//scanf("%d", &numero);

	//Escribe en el fichero
	//fprintf(Archivo, "%d\n",numero); //Manda el numero al fichero.
	//fprintf(Archivo, "El dato introducido es: %d\n",numero);

	//Registrar una cadena de caracteres:
	printf("Introduzca una frase: \n");
	fgets(auxiliar, 50, stdin); //captura la frase.
	Cambio(auxiliar);
	fprintf(Archivo, "La frase introducida es: %s\n",auxiliar);

	fclose(Archivo);

	return 0;
}

void Cambio(char auxiliar[]) //Hace que en txt el cursor termine al final de la linea y no al principio de una nueva linea.
{
	int i;

	for(i=0; i<50; i++)
	{
		if(auxiliar[i]=='\n')
		{
			auxiliar[i]='\0';
		}
	}
}