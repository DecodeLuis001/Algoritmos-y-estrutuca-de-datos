#include<stdio.h>
//Mandar un arreglo a una función
//No debe llevar una cantidad de datos, y enviar la cantidad de elementos.
float promedio(int Vector[], unsigned int Ne);

int main()
{
	unsigned int N, i;
	int V[100];
	float prom;

	printf("\n Numero de datos a capturar: ");
	scanf("%ui", &N);

	for(i=0; i<N; i++)
	{
		printf("\n V[%ui]= ", i);
		scanf("%i", &V[i]);
	}
	prom=promedio(V, N);
	printf("\n Los datos son: ");
	for(i=0; i<N; i++)
	{
		printf("\n V[%ui]=%i", i, V[i]);
	}
	printf("\n El promedio es: %.02f", prom);
	printf("\n");
	return 0;
}

float promedio(int Vector[], unsigned int Ne)
{	//R es el promedio.
	float r;
	unsigned int i;
	int suma=0;

	for(i=0; i<Ne; i++)
	{
		suma+=Vector[i];
	}
	//Cast: modificar el tipo de variable.
	r=(float)suma/Ne;
	return(r);
}