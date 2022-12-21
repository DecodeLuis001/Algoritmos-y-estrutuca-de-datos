#include<stdio.h>
#include<stdlib.h>

typedef struct NODO 
{
	int dato;
	struct NODO* siguiente_dato;
} 
NODO;

//Apuntadores auxiliares para construir la estructura de la lista.
NODO* Primer_Nodo=NULL;
NODO* Ultimo_Nodo=NULL;
//Fueron declarados globales con motivos de obtimización.

//Actuan como auxiliares para modificar el valor solicitado.
int Busqueda_Nodo=0, Nodo_Encontrado=0;
//Se inicializan en 0 debido a que son contadores,
//Al ser contadores será posible modificar el arreglo.
//Fueron declarados globales con motivos de obtimización.

void Crear_Nodo(NODO *Lista);
void Insertar_Elemento(NODO *Lista);
void Buscar_Elemento(NODO *Lista);
void Modificar_Lista(NODO *Lista);
void Eliminar_Elemento(NODO *Lista);
void Desplegar_Lista(NODO *Lista);
void Lista_Ordenanda(NODO *Lista);
void Orden(NODO *Lista);
void Multi_Nodo(NODO *Lista);

int main() 
{
	int Casos=1;
	int Opciones=0;

	NODO Lista;
	Lista.dato=0;
	Lista.siguiente_dato=NULL;

	do
	{
		printf("1). Insertar y ordenar elementos a la lista.\n");
		printf("2). Insertar nuevo elemento a la lista.\n");
		printf("3). Desplegar la lista.\n");
		printf("4). Desplegar lista ordenada.\n");
		printf("5). Buscar elemento en la lista.\n");
		printf("6). Modificar elemento en la lista.\n");
		printf("7). Eliminar elemento de la lista.\n");
		printf("8). Salir del programa.\n");
		printf("\n");
		scanf("%d", &Opciones);
		if(Opciones<=0 || Opciones>=9)
		{
			printf("La opción es invalida intentelo de nuevo.\n");
			exit(0);
		}
		printf("Opción elegida: [%d].\n", Opciones);

		switch(Opciones) 
		{
			case 1:
			{
				printf("\nEn esta opcion se te permite ingresar los datos y ordenarlos al mismo tiempo que se ingresan.\n");
				printf("\nIngrese los datos a ordenar.\n");
				Multi_Nodo(&Lista);
			}
			break;
			case 2:
			{
				printf("\nInserte el nuevo elemento a la lista\n");
				Insertar_Elemento(&Lista);
			}
			break;
			case 3:
			{
				printf("\nDesplegue de lista.\n");
				Desplegar_Lista(&Lista);
			}	
			break;
			case 4:
			{
				printf("La lista es: \n");
				Lista_Ordenanda(&Lista);
			}
			break;
			case 5:
			{
				printf("\nBusque el elemento que deseé.\n");
				Buscar_Elemento(&Lista);
			}
			break;	
			case 6:
			{
				printf("ADVERTENCIA: DEBE DE HABER USADO PRIMERO LA OPCION DE BUSCAR EL ELEMENTO.\n");
				printf("DE OTRO MODO ESTA OPCIÓN NO FUNCIONARA CORRECTAMENTE.\n");
				printf("\nModifique un elemento de la lista.\n");
				Modificar_Lista(&Lista);
			}
			break;
			case 7:
			{
				printf("ADVERTENCIA: DEBE DE HABER USADO PRIMERO LA OPCION DE BUSCAR EL ELEMENTO.\n");
				printf("DE OTRO MODO ESTA OPCIÓN NO FUNCIONARA CORRECTAMENTE.\n");
				printf("\n Elimine el elemento que deseé.\n");
				Eliminar_Elemento(&Lista);
			}
			break;
			case 8:
			{
				printf("Ha salido del programa.\n" );
				exit(0);	
			}
		}
		Casos++;
	} 
	while(Opciones<=8);
}

void Crear_Nodo(NODO *Lista)
{
	NODO* Nuevo_Nodo=(NODO *)malloc(sizeof(NODO));
	
	printf("Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d",&Nuevo_Nodo->dato);

		if(Primer_Nodo==NULL) //Establece la condición para crear el nodo y posteriormente la lista.
		{	//Se establece una condición de pila circular.
			Primer_Nodo=Nuevo_Nodo;
			Primer_Nodo->siguiente_dato=NULL; //En caso de que el siguiente dato a ingresar sea el ultimo.
			Ultimo_Nodo=Nuevo_Nodo;
		} 
		else //Para que se pueda agregar un nodo centrico.
		{ //Forma el cuerpo de la lista.
			Ultimo_Nodo->siguiente_dato=Nuevo_Nodo;
			Nuevo_Nodo->siguiente_dato=NULL;
			Ultimo_Nodo=Nuevo_Nodo;
		}
		printf("El elemento ha sido registrado.\n");
		printf("\n");
}

void Insertar_Elemento(NODO *Lista) 
{
	int i, recopilados;

	printf("¿Cúantos números desea ingresar?: \n");
	scanf("%d", &recopilados);

	for(i=0; i<recopilados; i++)
	{
		Crear_Nodo(Lista);
	}
}

void Desplegar_Lista(NODO *Lista) 
{	
	NODO* Nodo_Actual=(NODO *)malloc(sizeof(NODO)); //Permite recorrer la lista.
	Nodo_Actual = Primer_Nodo;  //Establece que existe un pirmer valor en la lista.

	if(Primer_Nodo!=NULL) //Indica que la cola no existe.
	{	
		do
		{ 
			printf("%d\n",Nodo_Actual->dato);
			Nodo_Actual=Nodo_Actual->siguiente_dato; //Actualiza el apuntador.
		}
		while(Nodo_Actual!=NULL); //Recorre la lista e imprime los valores ingresados.
	} 
	else
	{
		printf("No hay elementos en la lista.\n");
	}
	printf("\n");
	
}

void Lista_Ordenanda(NODO *Lista)
{
	NODO* Nodo_Actual=(NODO *)malloc(sizeof(NODO));
	Nodo_Actual=Primer_Nodo; //Establece que se comparen los elementos.
	//Al ordenar mediante burbuja evita que cause el segmentation fault.
	NODO* Pivote=(NODO *)malloc(sizeof(NODO));

	int auxiliar=0; //Alamcena el dato a comarar.

	if(Primer_Nodo!=NULL)
	{
		printf("Los datos ordenados de menor a mayor son: \n");
		printf("\n");
		Pivote=Primer_Nodo; //Modifica el valor del pivote.
		//Hace que el nodo se compare meidante saltos.
		while(Nodo_Actual!=NULL) //Establece un ciclo for con un indice abstrato i.
		{
			//Recorre el arreglo de modo que el valor del nodo se modifique.
			Pivote=Nodo_Actual->siguiente_dato; 
			
			while(Pivote!=NULL) //Establece un ciclo for con un indice abstrato j.
			{
				if(Nodo_Actual->dato > Pivote->dato)
				{
					//Equivale a un orden de burbuja con indices.
					/*
					siendo auxiliar el alamcen de datos
					Nodo actual que apunta al dato es el indice i.
					Nodo pivote que apunta al mismo dato es el indice j.
					*/
					auxiliar=Nodo_Actual->dato;			
					Nodo_Actual->dato=Pivote->dato;
					Pivote->dato=auxiliar;
				}
				Pivote=Pivote->siguiente_dato; //Hace que el pivote se recorra si el dato siguiente es mayor.
			}
			printf("%d\n", Nodo_Actual->dato);
			Nodo_Actual=Nodo_Actual->siguiente_dato; //Actualiza el apuntador.
		}	
	}
	else
	{
		printf("No tiene elementos en la lista.\n");
	}
	printf("\n");	
}

void Buscar_Elemento(NODO *Lista) 
{
	NODO* Nodo_Actual=(NODO *)malloc(sizeof(NODO)); //Permite recorrer la lista
	Nodo_Actual=Primer_Nodo; //Establece que existe un pirmer valor en la lista.

	printf("Ingrese el valor del elemento a buscar: \n");
	scanf("%d" ,&Busqueda_Nodo);

	if(Primer_Nodo!=NULL) 
	{								//Se estable para que la condicion funcione
		while(Nodo_Actual!=NULL && Nodo_Encontrado!=1) 
		{	
			if(Nodo_Actual->dato==Busqueda_Nodo) //Evita que todos los datos sean desplegados.
			{
				printf("\n El elemento (%d) ha sido encontrado \n" ,Busqueda_Nodo);
				Nodo_Encontrado=1; //Actua como un dato booleano para saber si existe un elemento.
			}		
			Nodo_Actual=Nodo_Actual->siguiente_dato;
		}
		if(Nodo_Encontrado==0) //La condición evalua que el dato solicitado no existe.
		{
			printf ("El elemento no fue encontrado\n");
		}
	} 
	else 
	{
		printf("\n La cola no existe \n");
	}
}

void Modificar_Lista(NODO *Lista) 
{
	NODO* Nodo_Actual=(NODO *)malloc(sizeof(NODO)); //Permite recorrer la lista.
	Nodo_Actual = Primer_Nodo;  //Establece que existe un pirmer valor en la lista.

	printf("Ingrese el valor del Nodo a Buscar para Modificar: \n");
	scanf("%d", &Nodo_Encontrado);

	if(Primer_Nodo!=NULL) 
	{
		while(Nodo_Actual!=NULL && Nodo_Encontrado!=1) 
		{
			
			if(Nodo_Actual->dato==Busqueda_Nodo) 
			{
				printf("\n Nodo con el dato (%d) Encontrado \n" ,Busqueda_Nodo);
				printf("\n Ingrese el nuevo dato para este Nodo: " );
				scanf("%d" ,&Nodo_Actual->dato);
				printf("\n Nodo Modificado con exito \n");
				Nodo_Encontrado=1;
			}		
			Nodo_Actual=Nodo_Actual->siguiente_dato; //Actualiza el apuntador.
		}
		if(Nodo_Encontrado==0) //En caso de que el usuario se equivoque al introducir el dato.
		{
			printf("Nodo no Encontrado.\n");
		}
	} 
	else
	{
		printf("La lista no existe.\n");
	}
}

void Eliminar_Elemento(NODO *Lista) 
{
	NODO* Nodo_Actual=(NODO *)malloc(sizeof(NODO)); //Permite recorrer la lista
	Nodo_Actual = Primer_Nodo; //Establece que existe un pirmer valor en la lista.
	
	NODO* Nodo_anterior=(NODO *)malloc(sizeof(NODO)); //Guarda el valor del apuntador actual.
	Nodo_anterior=NULL; 

	printf("Ingrese el valor del Nodo a Buscar para Eliminar: ");
	scanf("%d", &Nodo_Encontrado);

	if(Primer_Nodo!=NULL) 
	{
		while(Nodo_Actual!=NULL && Nodo_Encontrado!=1)
		{
			if(Nodo_Actual->dato==Busqueda_Nodo) 
			{	
				//Existen tres casos cuando se quiere eliminar un elemento
				if(Nodo_Actual==Primer_Nodo) //Primer caso: El primer elemento es el que sale.
				{
					Primer_Nodo=Primer_Nodo->siguiente_dato; //El primer dato pasa a apuntar al siguiente.
					//Hace que la lista se recorra.
				}		
				else //Establece que hay condiciones adicionales.
				if(Nodo_Actual==Ultimo_Nodo) //El ultimo elemento es el que sale.
				{
					Nodo_anterior->siguiente_dato=NULL; //Establece que ya no hay mas datos que ingresar.
					Ultimo_Nodo=Nodo_anterior; //Si no hay datos que ingresar, el ultimo dato es el que sale.
					//Si el ultimo dato es que sale, entonces el antepenultimo dato se vuelve el ultimo.
				} 
				else //En caso de que el dato este en el medio de la lista.
				{	//El Nodo_anterior alamcena los datos del centro de la lista.
					//como anterior alamcena el centro, cuando avance alsiguiente dato, el anterior se vuelve el elemento actual
					//El elemento actual es el que sale.
					Nodo_anterior->siguiente_dato=Nodo_Actual->siguiente_dato;
				}
				printf("El elemento ha sido eliminado con exito.\n");
				Nodo_Encontrado=1; //Cuando existe un nodo al cual modificar.
			}
			Nodo_anterior=Nodo_Actual;	
			Nodo_Actual=Nodo_Actual->siguiente_dato; //Actualiza el apuntador.
		}
		if(Nodo_Encontrado==0) //En caso de que el usuario se equivoque al digitar el numero.
		{
			printf("El elemento no se ha encontrado.\n");
		}
		else
		{
			free(Nodo_anterior); //Borra el espacio de memoria asignado.
		}
	} 
	else
	{
		printf("La lista no existe, no tiene elementos\n");
	}
}

void Multi_Nodo(NODO *Lista)
{
	int i, j, recopilados;

	printf("INTRODUZCA DOS VECES LA CANTIDAD DE DATOS A EVALUAR/INGRESAR.\n");
	printf("Número de datos a ingresar: \n");
	scanf("%d", &recopilados);
	printf("La cantidad de datos que forman la lista es: [%d]\n", recopilados);

	if(Lista!=NULL)
	{
		Insertar_Elemento(Lista);
		for(i=0; i<recopilados; i++)
		{
			printf("Coordinando ordenamiento...\n");
		}
		Lista_Ordenanda(Lista);
	}
	else
	{
		printf("La lista no contiene ningun elemento.\n");
	}
}