//Rellenar un array de 10 numeros, indicar cuales son pares e impares, indicar la psoición de memoria.

#include<stdio.h>

int main()
{
	int i, digito, datos[digito], *posicion;


	printf("¿Cuántos datos desea ingresar en el arreglo?: \n");
	scanf("%d",&digito);

	posicion=datos;

	for(i=0; i<digito; i++)
	{
		printf("Ingrese el dato: \n");
		scanf("%d", &datos[digito]);
		if(datos[digito]%2==0)
		{
			printf("El valor ingresado es par.\n");
			printf("La dirección de memoria es: %p\n", posicion);
		}
		else
		{
			printf("El valor ingresado es impar.\n");
			printf("La dirección de memoria es: %p\n", posicion);
		}
	}
	posicion++;

	return 0;
}