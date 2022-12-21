//Saber si un número es entero o par.

#include<stdio.h>

int main()
{
	int dato, *direccion_dato;

	printf("Dígite un número: \n");
	scanf("%d", &dato);

	direccion_dato=&dato;

	if(*direccion_dato%2==0)
	{
		printf("El número es par\n");
		printf("La posición es: %p \n", direccion_dato);
	}
	else 
	{
		printf("El número es impar\n");
		printf("La posición es: %p \n", direccion_dato);
	}
	return 0;
}