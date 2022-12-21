//Calcular la sumatoria de los primeros n números naturales, donde n es dado por el usuario.

#include<stdio.h>

int main()
{
	int i, plus=0, numeros, terminos;

	printf("¿Cuantos números desea ingresar\n");
	scanf("%d", &terminos);

	for(i=0; i<terminos; i++)
	{
		printf("Ingrese el número: \n");
		scanf("%d",&numeros);

		plus+=numeros;
	}
	printf("La suma es: %d \n", plus);
	return 0;
}
