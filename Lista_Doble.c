//Listas enlazadas.

/*

Lista->Nodo1---------------->Nodo2------------------->Nodo3
	[Prev][Dato][next]		[Prev][Dato][next]		[Prev][Dato][next]->NULL
	|		|						|						|
	|		|<---------------------||<----------------------|
	NULL
*/

#include<stdio.h>
#include<stdlib.h>

//Estructura para un nodo.
typedef struct NODO //Soluciona el problema de que el apuntador, apunta a la misma estrcutura.
{
	int dato;
	//Se antepone struct para poder usar una estructura para si misma.
	//Estos apuntadores permiten recorrer toda la estructura.
	struct NODO* siguiente_dato; 
	struct NODO* dato_anterior;
}
NODO; //Contiene un dato y un apuntador.

NODO* Crear_Nodo(int dato);
void Insertar_Nodo_Final(NODO *Lista, int dato); //Referencia.
void Insertar_Nodo_Inicio(NODO *Lista, int dato);
void Imprimir_Lista_Siguiente_Dato(NODO *Lista);
void Imprimir_Lista_Dato_Anterior(NODO *Lista);

//Tarea
//void Borrar_Nodo(NODO *Lista);
//Void Insertar nodo en orden(NODO *Lista);

int main()
{
	NODO Lista;
	Lista.dato=0;
	Lista.siguiente_dato=NULL;
	Lista.dato_anterior=NULL;

	printf("\n Si la lista no tiene elementos, entonces: \n");
	Imprimir_Lista_Siguiente_Dato(&Lista);

	printf("\n El inicio de la lista es: ");
	printf("\n");
	Insertar_Nodo_Final(&Lista, 5);
	Insertar_Nodo_Final(&Lista, 10);
	Insertar_Nodo_Final(&Lista, 51);
	Insertar_Nodo_Final(&Lista, 25);
	Insertar_Nodo_Inicio(&Lista, 0);
	printf("La lista en orden ascendente es:\n");
	Imprimir_Lista_Siguiente_Dato(&Lista);

	printf("La lista en orden desendente es:\n");
	Imprimir_Lista_Dato_Anterior(&Lista);

	/*
	Borrar_Nodo(&Lista);
	printf("\n La nueva lista es, despues del borrado: \n");
	Imprimir_Lista_Siguiente_Dato(&Lista);
	*/

	return 0;
}

//Se reserva la memoria para crear un nodo.
NODO* Crear_Nodo(int dato)
{
	NODO* apuntador; //Crear dinamiacamente la memoria necesaria.

	apuntador=(NODO*)malloc(sizeof(NODO)); //Memoria reservada para el nodo.
	apuntador->dato=dato;
	apuntador->siguiente_dato=NULL;
	apuntador->dato_anterior=NULL;

	return(apuntador);	
}

void Insertar_Nodo_Inicio(NODO *Lista, int dato)
{
	NODO *Nuevo_Nodo;
	NODO *Nodo_Auxiliar;

	//Almacena la direccion para el nuevo nodo
	Nuevo_Nodo=Crear_Nodo(dato);
	//Insertar un nodo al final de la lista.
	if(Lista->siguiente_dato==NULL) //Verifica que la lista esta vacia.
	{
		Lista->siguiente_dato=Nuevo_Nodo; //La lista apunta al primer elemento.
		Lista->dato_anterior=Nuevo_Nodo;
	}	
	else
	{	Nodo_Auxiliar=Lista->siguiente_dato;
		//El nuevo nodo pasa a ser el elemento siguiente al cual apuntar.
		Nuevo_Nodo->siguiente_dato=Lista->siguiente_dato; //Indica el primer elemento.
		Lista->siguiente_dato=Nuevo_Nodo;
		Nodo_Auxiliar->dato_anterior=Nuevo_Nodo;
	}
}

void Insertar_Nodo_Final(NODO *Lista, int dato)
{
	NODO *Nuevo_Nodo;
	NODO *Nodo_Auxiliar;

	//Almacena la direccion para el nuevo nodo
	Nuevo_Nodo=Crear_Nodo(dato);
	//Insertar un nodo al final de la lista.
	if(Lista->siguiente_dato==NULL) //Verifica que la lista esta vacia.
	{
		Lista->siguiente_dato=Nuevo_Nodo; //La lista apunta al primer elemento.
		Lista->dato_anterior=Nuevo_Nodo;
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
		Nuevo_Nodo->dato_anterior=Nodo_Auxiliar; //Dado que auxiliar tiene almacenado el nodo.
		Lista->dato_anterior=Nuevo_Nodo;
	}
}

void Imprimir_Lista_Dato_Anterior(NODO *Lista)
{
	NODO *Nodo_Auxiliar;

	if(Lista->dato_anterior==NULL) //Verifica que la lista esta vacia.
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		printf("\n");
		printf("\n Ha introducido los siguiente datos\n");
		Nodo_Auxiliar=Lista->dato_anterior; //Almacena el primer nodo
		do 
		{
			printf("Dato ingresado: [%i]\n" ,Nodo_Auxiliar->dato);
			Nodo_Auxiliar=Nodo_Auxiliar->dato_anterior;
		}
		while(Nodo_Auxiliar!=NULL); //Con el ciclo regresa a preguntar si hay más nodos.
		//Parte recursiva del código.
	}
}

void Imprimir_Lista_Siguiente_Dato(NODO *Lista)
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
		Nodo_Auxiliar=Lista->siguiente_dato; //Almacena el primer nodo
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
