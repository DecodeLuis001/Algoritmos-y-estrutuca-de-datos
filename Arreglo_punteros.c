//Mostrar la posición de un dato en un arreglo.

#include<stdio.h>

int main()
{
	int i, datos[]={1,2,3,4,5,6,7,8,9,10}, *posicion;

	posicion=datos;

	for(i=0; i<10; i++)
	{
		printf("Elemento: %d\n", *posicion++);
	}
	return 0;
}