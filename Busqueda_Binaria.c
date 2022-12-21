/*
El algoritmo de busqueda binaria, realiza su busqueda dividiendo el 
espacio de los datos de entrada en dos partes. 
Posteriormente selecciona el dato al centro y verifica si ese dato es el dato búscado.

Si no es, entonces debe decidir de que lado del espacio debería de encontrarse el dato. 
Una vez lo define, vuelve a dividir ese nuevo espacio en dos partes, seleccionando el el 
dato del centro y verificando si es el dato buscado, en caso de que lo sea, el algoritmo termina.
*/

//Evitar que se cicle.
//Que encuentre los extremos.
#include<stdio.h>
#include<stdlib.h>

void Ordenamiento(int *index, int elementos);

int main()
{
	int datos[14]={3,0,12,5,-1,9,23,32,1,-5,-7,11,15,8};
	int i, inicio, centro=0, final, dato;
	//El centro se inicializa en cero pués actua como un contador; esto debido a que si el arreglo es de
	//números pares de esta manera se puede usar arreglo de elementos pares o impares.

	//Aumento el rango del arreglo más no las dimensiones que ya tiene.
	//No se le puede poner el número directo como tal 1 y 15 pues tomaría erroneamente...
	//donde comienza y termina el arreglo.
	inicio=0;
	final=13+1; 

	printf("Dato a buscar: ");
	scanf("%d", &dato);

	printf("Los datos desordenados del arreglo son: \n");
	for(i=0; i<14; i++)
	{
		printf("Posición: %d; \t Dato: [%i]\n",i,datos[i]);
	}
	printf("\n");
	Ordenamiento(datos, 14);
	printf("Los datos ordenados del arreglo son: \n");
	for(i=0; i<14; i++)
	{
		printf("Posición: %d; \t Dato: [%i]\n",i,datos[i]);
	}

	do
	{
		if(dato==datos[centro])
		{
			printf("El dato se encuentra en la posición: %d.\n",centro);
			return 1;
			break;
		}
		else
		{
			//Separo este caso en dos ramificaciones tomando de referencia el dato central.
			if(dato>datos[centro]) //En caso de que el número se encuentre después del dato central.
			{
				inicio=centro;
				centro=(inicio+final)/2;
			}
			if(dato<datos[centro]) //En caso de que el número se encuentre antes del dato central.
			{
				final=centro;
				centro=(inicio+final)/2;
			}
		}
	}
	while(inicio+1!=final); //Saltamos la posición 0 pero en el principio del problema...
	//Se compensa pues por ello sumamos una posición "extra"; sin embargo esta actua como compensación
	//a la posición que se salta al final.

	//Compara los tres casos en donde puede estar el número en el arreglo
	//Si dicho numero no esta en el arreglo, salta el mensaje y termina el programa.
	if(datos[13]!=inicio || datos[13]!=centro || datos[13]!=final)
	{
		printf("El dato no se encuentra en el arreglo.\n");
		exit(0);
	}
	printf("\n");
	return 0;
}

void Ordenamiento(int *index, int elementos)
{
	int i,j,aux;

    for(i=0; i<elementos; i++)
    {
        for(j=0; j<elementos-1; j++)
        {
            if(index[j]>index[j+1])
            {
                aux=index[j];
                index[j]=index[j+1];
                index[j+1]=aux;
            }
        }
    }
    printf("\n");
}