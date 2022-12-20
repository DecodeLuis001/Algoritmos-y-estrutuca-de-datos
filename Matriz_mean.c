//Ejercico 2: Capturar una matriz de MxN numeros enteros y calcular el promedio de las filas y las columnas.

#include<stdio.h>

void promediofilas(int Matriz[][100], unsigned int M, unsigned int N, float promedio_filas[]);
void promediocolumnas(int Matriz[][100], unsigned int M, unsigned int N, float promedio_columnas[]);

int main()
{ //M=número de filas, N=número de columnas
	unsigned int M, N, i, j;
						//Los dos indices i, j recorren la matriz.
	int Mat[100][100];
	//Arreglos de una dimensión donde se alamcenan los promedios.
	float promedio_filas[100];
	float promedio_columnas[100];
	printf("\n Número de filas a capturar: ");
	scanf("%ui", &M);
	printf("\n Número de columnas a capturar: ");
	scanf("%ui", &N);

	//
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
	{
		printf("\n M[%u][%u]= ",i,j);
		scanf("%i", &Mat[i][j]);
	}
	printf("\n Los datos son: ");
	for(i=0; i<M; i++)
	{
		printf("\n");
		for(j=0; j<N; j++)
		{
			printf(" %i ", Mat[i][j]);
		}
	}

	promediofilas(Mat, M, N, promedio_filas);
	promediocolumnas(Mat, M, N, promedio_columnas);

	printf("\n Los promedios de las filas son: ");
	for(i=0; i<M; i++)
	{
		printf("\n promedio_filas[%i]=%f", i, promedio_filas[i]);
	}
	printf("\n");
	printf("\n Los promedios de las columnas son: ");
	for(j=0; j<N; j++)
	{
		printf("\n promedio_columnas[%i]=%f", j, promedio_columnas[j]);
	}
	printf("\n");
	return 0;
}

void promediofilas(int Matriz[][100], unsigned int M, unsigned int N, float promedio_filas[])
{
	//Los indices son necesarios para recorrer la matriz.
	unsigned int i, j;
	int suma;

	//Recorre la matriz de izquierda a derecha.
	for(i=0; i<M; i++)
	{
		suma=0;
		for(j=0; j<N; j++)
		{
			suma+=Matriz[i][j];
			promedio_filas[i]=(float)suma/N;
		}
	}
}

void promediocolumnas(int Matriz[][100], unsigned int M, unsigned int N, float promedio_columnas[])
{
	//Los indices son necesarios para recorrer la matriz.
	unsigned int i, j;
	int suma;

	//Recorre la matriz de izquierda a derecha.
	for(j=0; j<N; j++)
	{
		suma=0;
		for(i=0; i<M; i++)
		{
			suma+=Matriz[i][j];
			promedio_columnas[j]=(float)suma/N;
		}
	}
}
