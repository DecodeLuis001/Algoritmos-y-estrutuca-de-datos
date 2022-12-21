//Ficheros: guardan información en el disco duro.
//Abrir ficheros y leerlos.
#include<stdio.h>

int main()
{	//Declara el fichero.
	char auxiliar;
	char linea[100];
	FILE* Archivo;

	Archivo=fopen("Registro.txt", "r");
	if(Archivo==NULL)
	{
		printf("No se ha podido crear el archivo.\n");
	}

	while(auxiliar!=EOF)
	{ //Lee todos los caracteres y los muestra en pantalla.
		auxiliar=fgetc(Archivo);
		printf("%c\n",auxiliar);
	}
	printf("\n");

	//Despues de leer el fichero se debe liberar el archivo.
	fclose(Archivo);

	Archivo=fopen("Registro.txt", "r");
	if(Archivo==NULL)
	{
		printf("No se ha podido crear el archivo.\n");
	}

	while(!feof(Archivo)) //Expresa que se llego al final del fichero.
	{
		fgets(linea, 100, Archivo);
		printf("%s\n",linea);
	}
	printf("\n");

	fclose(Archivo);
	return 0; 
}