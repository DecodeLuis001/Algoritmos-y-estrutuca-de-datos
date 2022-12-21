//Calcular el factorial de un número entero positivo N.

#include<stdio.h>

unsigned int Factorial(unsigned int N)
{
	if(N==1) return 1;
	return N*Factorial(N-1);
}

int main()
{
	int N, r;

	printf("Escribe el valor de N: 	\n");
	scanf("%d", &N);
	r=Factorial(N);
	printf("El factorial de %d es: %d\n",N,r);
	return 0;
}