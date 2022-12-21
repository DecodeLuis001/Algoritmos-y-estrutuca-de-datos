#include<stdio.h>

int main()
{
	int i, posicion; //Posicion:Almacena la posición, Auxiliar: Medio por el cual se cambian los números. 
	float auxiliar, Elementos, Indice[100];

	printf("El máximo de elementos a ingresar es 100.\n");
	printf("¿Cuantos numeros desea ingresar?: \n");
	scanf("%f", &Elementos);
	if(Elementos<=0)
	{
		printf("No puede introducir numeros menores o iguales a cero para crer un arreglo.\n");
	}

	for(i=0; i<Elementos; i++)
	{
		printf("Ingrese el dato: \n");
		scanf("%f", &Indice[i]);

		posicion=i; //Recorre el bucle para comparar la posición.
		auxiliar=Indice[i]; //Compara el valor numerico de la posición.

		//La primer condición establece que se compare la posición mientras no llegue a ser cero, llega al final del bucle.
		//La segunda condición establece que si el número a la izquierda es mayor al número de la posición actual, este se intercambie.
		//El auxiliar almacena los datos para que se intercambie la posición si es necesario.
		while(posicion>0 && Indice[posicion-1]>auxiliar) 
		{
			Indice[posicion]=Indice[posicion-1]; //Hace el cambio del número a la izquierda con el número actual.
			posicion--; //Comprueba si el número es menor, por lo tanto hace que las iteraciones del bucle disminuyan.
		}
		Indice[posicion]=auxiliar; //Actualiza la posición del bucle para saber en que número esta actualmente.
	}

	printf("Los numeros de menor a mayor son: \n");
	for(i=0; i<Elementos; i++)
	{
		printf("Dato[%.2f]\n",Indice[i]);
	}
	printf("\n");

	printf("Los numeros de mayor a menor son: \n");
	for(i=Elementos; i>0; i--)
	{
		printf("Dato[%.2f]\n",Indice[i-1]);
	}
	printf("\n");

	return 0;
}