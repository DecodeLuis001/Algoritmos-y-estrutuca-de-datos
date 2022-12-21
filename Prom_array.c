//Arreglos en C: definición y uso de arreglos uni y bidimencionales.
//Ejercicio 1: capturar una cantidad n de numeros enteros y calcular su promedio.
//Ejercico 2: Capturar una matriz de MxN numeros enteros y calcular el promedio de las filas y las columnas.
#include<stdio.h>

int main()
{
	int i, valores, numeros, datos[valores];
	float plus=0, promedio;

	printf("¿Cúantos números desea ingresar?:\n");
	scanf("%d", &numeros);

	for(i=0; i<numeros; i++)
	{
		printf("Valor: \n");
		scanf("%d", &valores);
		plus+=valores;
	}
	promedio=plus/numeros;

	printf("El promedio de los %d números que ha ingresado es: %.02f\n", numeros, promedio);
	return 0;
}

/*
Ejercicio de capulin:

#include<stdio.h>
//Mandar un arreglo a una función
//No debe llevar una cantidad de datos, y enviar la cantidad de elementos.
float promedio(int V[], unsigned int Ne)

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
	prom=Promedio(V, N);
	printf("\n Los datos son: ");
	for(i=0; i<N; i++)
	{
		printf("\n V[%ui]=%i", i, V[i])
	}
	printf("\El promedio es: %f", prom);
	printf("\n");
	return 0;
}

float promedio(int V[], unsigned int Ne)
{	//R es el promedio.
	float r;
	unsigned int i;
	int suma=0;

	for(i=0; i<Ne; i++)
	{
		suma+=Vector[i];
	}
	r=suma/Ne;
	return(r);
}
*/
