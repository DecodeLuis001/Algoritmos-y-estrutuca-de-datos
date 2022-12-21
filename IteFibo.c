//Calcular la serie de sucesión de fibonacci.
//Forma iterativa.

#include<stdio.h>

int digito1=0;
int digito2=1;
int Resultado=0;

int main()
{
	int i, digito;

	printf("Ingrese el número de posición de la serie de fibonacci\n");
	printf("Ingrese el número: \n");
	scanf("%d", &digito);

	if(digito<0)
	{
		printf("La serie de fibonacci no trabaja números negativos\n");
	}
	if(digito==0)
	{
		printf("0\n");
	}
	for(i=0; i<digito; i++)
	{
		digito1=digito2;
		digito2=Resultado;
		Resultado=digito1+digito2;
	}
	printf("La serie es: %d\n", Resultado);

	return 0;
}