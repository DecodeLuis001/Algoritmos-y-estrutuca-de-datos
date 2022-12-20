#include<stdio.h>

int main()
{
	FILE* ptrArchivo1;

	int datos[10]={10, 5, 1, 2, 6, 9, 0, -1, -5, -11};

	ptrArchivo1=fopen("test.bin", "w+rb+");
	if(ptrArchivo1==NULL)
	{
		printf("No se pudo crear el archivo.\n");
	}
	fwrite(datos, sizeof(datos), 1, ptrArchivo1);

	fclose(ptrArchivo1);
	printf("\n");
	return 0;
}
