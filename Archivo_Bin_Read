#include<stdio.h>

/*
size_t fread(void *apuntador, //Apunta a donde se alamcenaran los datos.
size_t dimension, //Tamaño del registro.
size_t cantidad, //Cantidad de registros.
FILE* Archivo); //Apuntador al archivo de escritura.
*/

int main()
{
	FILE* ptrArchivo1;

	int k, datos[100];

	ptrArchivo1=fopen("test.bin", "rb");
	if(ptrArchivo1==NULL)
	{
		printf("No se pudo crear el archivo.\n");
	}

	fread(datos, sizeof(int), 10, ptrArchivo1);

	fclose(ptrArchivo1);

	for(k=0; k<10; k++)
	{
		printf("%i\n",datos[k]);
	}
	printf("\n");
	return 0;
}
