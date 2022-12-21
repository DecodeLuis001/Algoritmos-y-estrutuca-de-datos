//Calcular la sumatoria de los primeros n números naturales, donde n es dado por el usuario.
//Recursividad: a traves de funciones.
//Siempre debe haber algo que detenga el algoritmo.

#include<stdio.h>

unsigned int funcionRecursiva (unsigned int terminos);

int main(void)
{
	unsigned int terminos,r;
	printf("¿Cuantos números quieres sumar?: \n");
	scanf("%u",&terminos);
	r=funcionRecursiva(terminos);

	printf ("el resultado de la sumatoria de %i numeros es %i\n",terminos,r); 

	return 0;
}

unsigned int funcionRecursiva (unsigned int terminos)
{

	unsigned int r;
	if (terminos==1)
	{
		return 1;
	}
	else
	{
		r=terminos+funcionRecursiva(terminos-1);
		return r;
	}
}