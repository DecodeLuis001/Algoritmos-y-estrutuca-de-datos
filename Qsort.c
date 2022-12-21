/*
Programa que utliza el ordenamiento quick sort.

void qsort(void *base, //Apuntador al primer dato elemento del arreglo.
	size_t numero_miembros, //Recibe el número de elementos del arreglo.
	size_t tamanio, //Número de bytes por elemento
	int (*funcion)(const void *, const void *), ); //Apuntador a una función que recibe dos parámetros que son a su vez
	//dos apuntadores de tipo void.

int Nombre_Funcion(*funcion)(const void *, const void *); //Se esta delcarando un apuntador a una función.
//A través de este apuntador se puede llamar una función especifica dentro del programa.
//Se puede mandar como parámetro en otra función. 
//El usuario puede mandar un apuntador a otra función para llamarla.
*/

#include<stdio.h>
#include<stdlib.h>

int Comparar(const void *parametro1, const void *parametro2) //Requerida para saber como se van a ordenar los datos.
{//Se hace el casteo dado que los apuntadores son genericos por los que pueden ordenar cualquier tipo de dato.
	//Ahora se pueden ordenar los datos porque se sabe que tipo de dato son
							//> imprimir en orden inverso.
	if( *((double *)parametro1) < *((double *)parametro2) ) //Compara los valores a los que apuntan.
	{
		return 1;
	}
	else
	{								//< imprimir en orden inverso.
		if( *((double *)parametro1) > *((double *)parametro2) )
		{
			return -1;
		}
		else
		{
			return 0; //expresa que los parámetros son iguales
		}
	}
}

int main()
{ //int
	double Datos[100];
	//char Datos[100];
	int k, Elementos; //Datos[100];

	printf("¿Cuántos datos desea ingresar?: \n");
	scanf("%d", &Elementos);

	for(k=0; k<Elementos; k++)
	{
		printf("Ingrese el dato: \n");
		scanf("%lg", &Datos[k]);		//%d, %s
	}
	qsort(Datos, Elementos, sizeof(double), Comparar);

	for(k=0; k<Elementos; k++)
	{
		printf("Dato: [%g]\n", Datos[k]);
	}
	printf("\n");

	return 0;
}