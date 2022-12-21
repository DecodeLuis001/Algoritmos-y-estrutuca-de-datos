//TAREA PRACTICA 1: implementar un programa en el lenguaje C para la captura 
//de un vector de numeros complejos que contenga las siguientes funciones.
/*
Funcion para crear vector, capturar el vector, imprimir el vector, calcular la suma del vector, funciones adicionales para manejar números complejos.
utilice apuntadores y asignación dinamica de memoria.
typedef struct 
{
	float real;
	float imaginario;
}
COMPLEJO;

typedef struct 
{
	COMPLEJO *pdatos;
	unsigned int Ne;
}
VECTOR;


*/
#include<stdio.h>
#include<stdlib.h> //para usar comandos como malloc y exit.

typedef struct 
{
	int *A_datos;
	unsigned int Elementos;
}
VECTOR;

VECTOR* Crea_vector(unsigned int Dato);
void Capturar(VECTOR *x);
void Imprimir(VECTOR *p);
void Eliminar(VECTOR *p);
float Promedio(VECTOR *v);

int main()
{
	VECTOR *v;
	unsigned int datos;

	printf("¿Cuántos datos desea ingresar?:\n");
	fpurge(stdin);
	scanf("%u", &datos);
	printf("\n");
	v=Crea_vector(datos);
	printf("Ingrese los datos para capturar su vector: \n");
	Capturar(v);
	printf("El vector capturado es: \n");
	Imprimir(v);
	printf("Su promedio del vector ingresado es: %.2f\n", Promedio(v));
	printf("\n");
	Eliminar(v);
	
	printf("\n");
	return 0;
}

//Asignacion de memoria necesaria.
//Generar memoria para generara viarable de esa estrucutra, luego agrgar una cantidad N de dados a esa estructura usando malloc.
VECTOR* Crea_vector(unsigned int Dato)
{
	VECTOR *ptr;
				//Malloc es un comando generico (regresa una dirección generica); se necesita un cast.
	ptr=(VECTOR *)malloc(sizeof(VECTOR)); //Gestiona la memoria con el sistema operativo.
	//Se necesita saber el tamaño del tipo de dato que se esta usando.
	//sizeof: "comprime" hasta el tipo de dato con el que se quiere trabajar.
	if(ptr==NULL) //En caso de que no haya memoria.
	{
		printf("Error de reservado de memoria\n");
		exit(0); //Termina el programa.
	}
	//Operador flecha: apuntador y miembro al que se quiera referir 
	ptr->Elementos=Dato;
	//Forma de reservar la memoria necesaria mediante cast.
	ptr->A_datos=(int *)malloc(sizeof(int) *Dato);

	return(ptr); //Regresa la dirección que contiene y llega a V.
}

void Capturar(VECTOR *x)
{
	unsigned int i;

	for(i=0; i<x->Elementos; i++)
	{
		printf("\n Ingrese el dato: Posición[%i]= ", i);
		//Usa la aritmetica de apuntadores.
		scanf("%i", x->A_datos+i); //El indice i modifica la dirección de los elementos ingresados.
	}
	printf("\n");
}

void Imprimir(VECTOR *p)
{
	unsigned int i;

	for(i=0; i<p->Elementos; i++)
	{
		//El segundo %i imprime el contenido, meidante el uso de apuntadores.
		//El apuntador obtiene y lee las direcciones de los datos almacenados.
		printf("Posición[%i]=%i\n", i, *(p->A_datos+i));
	}
}

//Libera memoria a tráves de malloc-free.
void Eliminar(VECTOR *p)
{
	free(p->A_datos); //Corespondiente al segundo malloc.
	free(p); //Correspondiente al primer malloc.
}

float Promedio(VECTOR *v)
{
	int suma=0;
	unsigned int i;
	float resultado;

	for(i=0; i<v->Elementos; i++)
	{
		//Accedemos al dato de memoria, mientras se acumula en suma.
		suma+=*(v->A_datos+i);
	}
	resultado=(float)suma/v->Elementos;
	return(resultado);
}
