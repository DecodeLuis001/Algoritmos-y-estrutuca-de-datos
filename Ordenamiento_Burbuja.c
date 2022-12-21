/*
Los algoritmos de ordenamiento, modifican las posiciones de los elementos de un conjunto de datos dados, con el fin de establecer una secuencia en los datos dependiendo de un criterio definido.

Para llevar a cabo este ordenamiento se tiene algoritmos ya previamente establecidos y estudiados tales como:

Ordenamiento por intercambio directo: Método de burbuja.
Ordenamiento por inserción directa: Método de la baraja.
Ordenamiento por selección directa.
Ordenamiento por método de quicksort.
*/

#include<stdio.h>

void Ordenamiento();

int main()
{    
    Ordenamiento();       

	return 0;
}

void Ordenamiento()
{
	int i,j, valor=0, aux, elementos;
    int index[100];

	printf("Numero de elementos a capturar: \n");
    scanf("%i", &valor);
    //fpurge(stdin);

    for(i=0; i<valor; i++)
    {
        printf("\n index[%i]=",i);
        scanf("%i", &index[i]);
    }
     
    elementos=valor;       
    for(i=0; i<(elementos-1); i++)
    {
        for(j=(i+1); j<elementos; j++)
        {
            if(index[j]>index[i])
            {
                aux=index[i];
                index[i]=index[j];
                index[j]=aux;
            }
        }
    }
    printf("\n");

    printf("Los datos que ha introducido de mayor a menor son: \n");
    for(i=0; i<valor; i++)
    {
        printf("%d\n", index[i]);
    }
    printf("\n");  

    printf("Los datos que ha introducido de menor a mayor son: \n");
    for(i=valor; i>0; i--)
    {
        printf("%d\n", index[i-1]);
    }
    printf("\n");  
}