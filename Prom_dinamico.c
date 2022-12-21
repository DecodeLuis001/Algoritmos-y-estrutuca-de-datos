/*
Tema: asignación dinámica de memoria
Cuando se declaran las variables a utilizar en un programa, el compilador les reserva la memoria necesaria para alamcenar desde un inicio.
Esta memoria existe hasta que el programa termina. Dicha memoria corresponde con una asignación estatica de memoria y se realiza en el tiempo de compilación.

por otra parte cuando no se tiene conocimiento de cuanta memoria será necesaria para ña operación de un programa, se tiene que solicitar al SO la asignación de memoria una vez que el program esta en ejecución;
a esta operación se le conoce como asignacion dinámica de memoria y se realiza en el tiempo de ejecución.
El programador puede liberar dicha memoria en el momento que la deje de utilizar.

Ejercicio 1: Capturar n numeros y sacar su promedio
Ejercicio 1.1: Agregar una función que regrese el valor menor de todos.
Ejercicio 1.2: agregar una función que regrese el valor mayor de todos.
Ejercicio 1.3: Agregar una función que imprima todos los datos de forma inversa.
Ejercicio 2: Capturar una matriz de MxN y sacar promedio de filas y columnas.

*/

#include<stdio.h>
#include<stdlib.h> //para usar comandos como malloc y exit.

float Promedio(int *almacenamiento, unsigned int datos);
int Menor(int *almacenamiento, unsigned int datos);
int Mayor(int *almacenamiento, unsigned int datos);
void Orden_Inverso(int *almacenamiento, unsigned int datos);

int main()
{
	unsigned int datos;
	int i, *dato; //Apuntadores: especificar el tipo de información.
	float promedio;
    int Minus, Max;

	printf("¿Cuántos datos desea ingresar?:\n");
	fpurge(stdin);
	scanf("%u", &datos);
				//Malloc es un comando generico (regresa una dirección generica); se necesita un cast.
	dato=(int *)malloc(sizeof(int)*datos); //Gestiona la memoria con el sistema operativo.
	//Se necesita saber el tamaño del tipo de dato que se esta usando.
	//sizeof: "comprime" hasta el tipo de dato con el que se quiere trabajar.
	if(dato==NULL) //En caso de que no haya memoria.
	{
		printf("Error de reservado de memoria\n");
		exit(0); //Termina el programa.
	}
	for(i=0; i<datos; i++)
	{
		printf("\n Ingrese el dato: [%i]= ", i);
		//Usa la aritmetica de apuntadores.
		scanf("%i", dato+i); //dirección del siguiente dato
	}
	printf("\n");
	printf("Los datos ingresados son: \n");
	for(i=0; i<datos; i++)
	{
		//El segundo %i imprime el contenido, meidante el uso de apuntadores.
		//El apuntador obtiene y lee las direcciones de los datos almacenados.
		printf("datos[%i]=%i\n", i, *(dato+i));
	}

	promedio=Promedio(dato, datos);
	
    Minus=Menor(dato, datos);
    Max=Mayor(dato, datos);
	printf("El promedio es: %.2f \n",promedio);
	printf("El dato de menor valor ingresado es: %d\n", Max);
    printf("El dato de mayor valor ingresado es: %d\n", Minus);
    printf("Loas datos ingresados en orden inverso son\n");
    Orden_Inverso(dato, datos);
	printf("\n");
	free(dato); //Libera la memoria mediante el uso del apuntador donde se esta almacenando.
	return 0;
}

float Promedio(int *almacenamiento, unsigned int datos)
{
	int suma=0;
	unsigned int i;
	float resultado;

	for(i=0; i<datos; i++)
	{
		suma+=*(almacenamiento+i);
	}
	resultado=(float)suma/datos;
	return(resultado);
}

int Menor(int *almacenamiento, unsigned int datos)
{
    int i, menor;
    
    menor=*almacenamiento;
    for(i=0; i<datos; i++)
    {
        if(menor<*(almacenamiento+i))
        {
            menor=*(almacenamiento+i);
        }
    }
    return(menor);
}

int Mayor(int *almacenamiento, unsigned int datos)
{
    int i, mayor;
    
    mayor=*almacenamiento;
    for(i=0; i<datos; i++)
    {
        if(mayor>*(almacenamiento+i))
        {
            mayor=*(almacenamiento+i);
        }
    }
    return(mayor);
}

void Orden_Inverso(int *almacenamiento,  unsigned int datos)
{
    int i, *dato;
    
    for(i=datos; i>0; i--)
    {
        printf("datos[%i]=%i\n", i, *(almacenamiento+(i-41)));
    }
}

