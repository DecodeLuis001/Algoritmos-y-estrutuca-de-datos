/*
Los algoritmos de búsqueda consisten en encontrar la ubiciación de un dato o registro dentro de un conjunto
de información organizada.

El algoritmo de búsqueda secuencial es uno de los más básicos. Consiste en realizar un recorrido por todos
los datos hasta encontrar el dato buscado o en su caso llegar hasta el final de los datos.
*/

#include<stdio.h>

int main()
{
	int i, flag=0, dato; //datos[15]={3, 11, 5, -6, 7, 3, 63, 32, 19, -50, -7, -81, 15, 18};
	int j, elementos, datos[100];

	printf("¿Cuantos datos desea ingresar?: \n");
	scanf("%d", &elementos);

	for(j=0; j<elementos; j++)
	{
		printf("Ingrese el dato: \n");
		scanf("%d", &datos[j]);
	}

	printf("Los elementos ingresados son: \n");
	for(j=0; j<elementos; j++)
	{
		printf("Dato: %d\n", datos[j]);
	}
	printf("\n");
	printf("Dato a buscar: ");
	scanf("%d", &dato);

	for(i=0; i<15; i++)
	{
		if(dato==datos[i])
		{
			flag=1;
			break;
		}
	}

	if(flag)
	{
		printf("El dato se encuentra en la posición: %d .\n", i+1);
	}
	else
	{
		printf("El dato no se encuentra en el arreglo.\n");
	}

	return 0;
}