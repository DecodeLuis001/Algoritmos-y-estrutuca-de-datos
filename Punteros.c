//Punteros
//Un puntero es una variable donde se va a almacenar la direccion de memoria de otra variable.

#include<stdio.h>

int main()
{
	int num=20;
	int * dir_num = &num;

	printf("Número: %i \n",num);

	*dir_num=30;

	printf("Valor de var1: %i \n",num);

	return 0;
} 