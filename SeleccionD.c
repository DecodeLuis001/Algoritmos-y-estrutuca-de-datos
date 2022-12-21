//Ordenamiento por selección directa.

#include<stdio.h>

void Ordenar(int *Datos, int Elementos);

int main()
{
	int k, j,  Menor, Auxiliar, Elementos, Datos[100];

	printf("¿Cuántos datos desea ingresar?: \n");
	scanf("%d", &Elementos);

	for(k=0; k<Elementos; k++)
	{
		printf("Ingrese el dato: \n");
		scanf("%d", &Datos[k]);
	}
	Ordenar(Datos, Elementos);

	for(k=0; k<Elementos; k++)
	{
		printf("Dato: [%i]\n", Datos[k]);
	}

	return 0;
}

void Ordenar(int *Datos, int Elementos)
{
	int j, k, Menor, Auxiliar;

	for(j=0; j<Elementos-1; j++)
	{	Menor=j;
		for(k=j+1; k<Elementos; k++)
		{
			if(Datos[k]<Datos[Menor])
			{
				Menor=k;
			}
		}//El intercambio va comparando la posición y compara el valor de dicha posición.
		Auxiliar=Datos[j];
		Datos[j]=Datos[Menor];
		Datos[Menor]=Auxiliar;
	}
}