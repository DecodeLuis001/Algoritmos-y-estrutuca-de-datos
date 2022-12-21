/*
Una lista enlazada es una estrutura de datos abstracta, dinámica y lineal. Consta de un elemento base llamado "NODO", el cual consta de un dato y un apuntador en el siguiente NODO.

Se dice que es dinámica porque no tiene un tamaño fijo, crece conforme se agregan elementos a la lista.
Se dice que es lineal dado que todos los elementos están enalzados de manera consecutiva, es decir un NODO solo puede apuntar al NODO siguiente.

De manera gráfica la podemos representar de la siguiente manera:

NODO 1				
[dato][next]---->[NULL] el dato siguinte debe apuntar a NULL,
indica que existe un ultimo dato de la lista.

NODO 1			Nodo 2				
[dato][next]---->[dato][next]---->[NULL]
Se genera un nodo nuevo de manera dinámica y NULL se recorre.

Opción 1: para generar la lista.
lista 			NODO 1			Nodo 2				
[dato][next]---->[dato][next]---->[dato][next]---->[NULL]
Debe apuntar al nodo 1

Opción 2: para generar la lista.
Apuntador				NODO 1			Nodo 2				
*lista de datos---->[dato][next]---->[dato][next]---->[NULL]

lista enlazada se basa en la definición del nodo.
*/


#include<stdio.h>
#include<stdlib.h>

//Estructura para un nodo.
typedef struct NODO //Soluciona el problema de que el apuntador, apunta a la misma estrcutura.
{
	int dato;
	//Se antepone struct para poder usar una estructura para si misma.
	struct NODO* siguiente_dato; //Apuntador a la misma estrcutura.
}
NODO; //Contiene un dato y un apuntador.
//La lista será un apuntador.
//Crea un nodo de forma dinámica.
NODO* Crear_Nodo(int dato);
void Insertar_Nodo(NODO *Lista, int dato); //Referencia.
void Borrar_Nodo(NODO *Lista);
void Imprimir_Lista(NODO *Lista);

//Tarea.
//void Insertar_Nodos(NODO *Lista);
//void Borrar_Nodo(NODO *Lista, int dato);

int main()
{
	//Opción 1
	NODO Lista;
	Lista.dato=0;
	Lista.siguiente_dato=NULL;

	printf("\n El inicio de la lista es: \n");
	Imprimir_Lista(&Lista);
	printf("\n");

	Insertar_Nodo(&Lista, 5);
	Imprimir_Lista(&Lista);

	Borrar_Nodo(&Lista);
	printf("\n La nueva lista es, despues del borrado: \n");
	//Imprimir_Lista(&Lista);

	return 0;
}

//Se reserva la memoria para crear un nodo.
NODO* Crear_Nodo(int dato)
{
	NODO* apuntador; //Crear dinamiacamente la memoria necesaria.

	apuntador=(NODO*)malloc(sizeof(NODO)); //Memoria reservada para el nodo.
	apuntador->dato=dato;
	apuntador->siguiente_dato=NULL;

	return(apuntador);	
}


void Insertar_Nodo(NODO *Lista, int dato)
{
	NODO *Nuevo_Nodo;
	NODO *Nodo_Auxiliar;

	//Almacena la direccion para el nuevo nodo
	Nuevo_Nodo=Crear_Nodo(dato);
	//Insertar un nodo al final de la lista.
	if(Lista->siguiente_dato==NULL) //Verifica que la lista esta vacia.
	{
		Lista->siguiente_dato=Nuevo_Nodo; //La lista apunta al primer elemento.
	}	
	else
	{
		Nodo_Auxiliar=Lista->siguiente_dato;
		while(Nodo_Auxiliar->siguiente_dato!=NULL)
		{
			//Toma la dirección que se ingresa y se salta al siguiente dato.
			//Por ello el auxiliar apunta al siguiente elemento.
			Nodo_Auxiliar=Nodo_Auxiliar->siguiente_dato;
		}
		Nodo_Auxiliar->siguiente_dato=Nuevo_Nodo;
	}
}

void Imprimir_Lista(NODO *Lista)
{
	NODO *Nodo_Auxiliar;

	if(Lista->siguiente_dato==NULL) //Verifica que la lista esta vacia.
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		printf("\n");
		printf("\n Ha introducido los siguiente datos\n");
		Nodo_Auxiliar=Lista->siguiente_dato; //Almacena el primero de los elemtnos
		do 
		{
			printf("Dato ingresado: [%i]\n" ,Nodo_Auxiliar->dato);
			Nodo_Auxiliar=Nodo_Auxiliar->siguiente_dato;
		}
		while(Nodo_Auxiliar!=NULL); //Con el ciclo regresa a preguntar si hay más nodos.
		//Parte recursiva del código.
	}
}

void Borrar_Nodo(NODO *Lista)
{
	//Estos apuntadores son auxiliares.
	NODO *Ultimo;
	NODO *Penultimo;

	//Insertar un nodo al final de la lista.
	if(Lista->siguiente_dato==NULL) //Verifica que la lista esta vacia.
	{
		printf("La lista esta vacia.\n"); 
	}	
	else
	{
		Penultimo=Lista;
		Ultimo=Lista->siguiente_dato;
		//Recorremos ambos apuntadores.
		while(Ultimo->siguiente_dato!=NULL) //Verificamos si hay un adicional despues del ultimo.
		{
			Penultimo=Ultimo; //Ultimo sera el siguiente en ser recorrido.
			Ultimo=Ultimo->siguiente_dato;
		}
		Penultimo->siguiente_dato=NULL;
		free(Ultimo); //Libera la memoria del ultimo eslavon.
	}
}
