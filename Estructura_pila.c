//Estructuras de datos abstractas: 


/*
Pila: es un tipo de dato abstracto se le puede conocer como "LIFO" (ULTIMO DATO EN ENTRAR ES EL PRIMERO EN SALIR)

Operaciones basicas con las estructuras de pila:
1.) Insertar elemento a la Pila:		push();
2.) Sacar un elemento de la fila:		pop();
3.) Pila vacia:							isEmpty();
4.) Pila llena: 						isFull();
	Solo se implementa cuando la pila es de un tamaña especifico (arreglo).

*/


#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	unsigned int dimension; //Tamaño de los datos.
	int id; //tendra la función de un indice.
	int *datos;		//Necesario para implementar de manera dinamica.

}
PILA;

PILA* Crear_Pila(unsigned int Elementos); //Regresa la direccion a donde apunta la pila.
void Eliminar_Pila(PILA *p);
char Push(PILA *p, int dato); //Se utiliza a modo de tipo logico 0 o 1 para saber si la operación se realizo correctamente.
char IsFull(PILA *p);
char Pop(PILA *p, int* dato); //referencia al dato 
char IsEmpty(PILA *p);

int main()
{
	PILA *pila01;
	int dato;

	pila01=Crear_Pila(3);
	printf("\n");
	if(!Push(pila01, 3))
	{
		printf("El dato no fue ingresado, la pila esta llena.\n");
	}
	if(!Push(pila01, 5))
	{
		printf("El dato no fue ingresado, la pila esta llena.\n");
	}
	if(!Push(pila01, 9))
	{
		printf("El dato no fue ingresado, la pila esta llena.\n");
	}
	printf("\n");

	if(Pop(pila01, &dato))
	{
		printf("\n %i", dato);
	}
	else
	{
		printf("La pila esta vacia.\n");
	}
	if(Pop(pila01, &dato))
	{
		printf("\n %i", dato);
	}
	else
	{
		printf("La pila esta vacia.\n");
	}
	if(Pop(pila01, &dato))
	{
		printf("\n %i", dato);
	}
	else
	{
		printf("La pila esta vacia.\n");
	}
	printf("\n");

	Eliminar_Pila(pila01); //Parametro para eliminar la pila01.

	printf("\n");
	return 0;
}

PILA* Crear_Pila(unsigned int Elementos)
{
	PILA* apuntador;
	//Hacer la reserva dinamica.
	apuntador=(PILA *)malloc(sizeof(PILA));
	//Inicializar miembros.
	apuntador->id=-1;
	apuntador->dimension=Elementos;
	apuntador->datos=(int *)malloc(sizeof(int) *Elementos);

	//dirección donde esta la pila.
	return(apuntador);
}

//Recibe los datos del apuntador.
void Eliminar_Pila(PILA *p) //p almacena los datos introducidos.
{
	free(p->datos);
	free(p);
}

char Push(PILA *p, int dato)
{
	if(IsFull(p))
	{
		return 0; //Indica que no funciono.
	}
	else
	{
		p->id++;
		p->datos[p->id]=dato; //Se puede ingresar el dato.	
	}
	return 1; //Indica que no funciono.
}

char IsFull(PILA *p)
{
	if(p->id==p->dimension) //Indica que la pila esta llena.
	{
		return 1; //Regresa uno cuando esta llena.
	}
	else
	{
		return 0; //Indica que la pila aun no esta llena.
	}
}

char Pop(PILA *p, int* dato)
{
	if(IsEmpty(p))
	{
		return 0; //El pop no ha funcionado.
	}
	else
	{
		//Forma alterna: *dato=p->datos[p->id];
		*dato=*(p->datos+p->id); 
		p->id--; //Indica que elemento es el ultimo.  
		return 1;
	}
}

char IsEmpty(PILA *p)
{
	if(p->id==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}