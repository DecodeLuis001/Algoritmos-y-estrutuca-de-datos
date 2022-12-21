//Calcular la serie de sucesión de fibonacci.
//Forma recursiva.

#include<stdio.h>

//Variables globales
int digito1=0;
int digito2=1;
int Resultado=0;
//Actuan como counters globales que se deben inicializar de forma binaria.

int serie_fibonacci()
{
	digito1=digito2;
	digito2=Resultado;
	Resultado=digito1+digito2;
	return Resultado;
}

int main()
{
	int i, digito;
	printf("Recuerde el numero que ingrese, será la posición que quiere calcular en la serie de fibonacci\n");
	printf("Ingrese un numero: \n");
	scanf("%i", &digito);
	printf("Serie de Fibonacci, hasta la posición %i\n", digito);
	if(digito<0)
	{
		printf("No se puede usar una serie de fibonacci con valores negativos\n");
	}
	if(digito==0)
	{
		printf("0\n");
	}
	for(i=0; i<digito; i++)
	{
		printf("%d\n", serie_fibonacci());
	}
	return 0;
}