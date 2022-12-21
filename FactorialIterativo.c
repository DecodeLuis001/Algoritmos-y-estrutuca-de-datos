//Haga un factorial de forma iterativa.

#include<stdio.h>

int main()
{
	int i, f, factorial;

	printf("¿De que número quiere calcular el factorial?: \n");
	scanf("%d", &factorial);

	for(i=0; i<factorial; i++)
	{
		if(factorial<0)
		{
			printf("No se puede calcular el factorial de números negativos.\n");
		}
		if(factorial==0 || factorial==1)
		{
			factorial=1;
		}
		else
		{
			f=factorial*i;
		}
	}
	printf("El factorial de %d es: %d\n",factorial,f);

	return 0;
}