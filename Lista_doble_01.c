#include <stdio.h>
#include <stdlib.h>

typedef struct NODO 
{
	int Data;
	struct NODO* Next;
	struct NODO* Fore;
} 
NODO;

//Apuntadores auxiliares para construir la estructura de la lista.
NODO* First=NULL;
NODO* Last=NULL;
//Fueron declarados globales con motivos de obtimización.

//Actuan como auxiliares para modificar el valor solicitado.
int Research_Nodo=0; //Establece la referencia para buscar un elemento.
int Find_Nodo=0; //Establece un control para saber si se identifico un elemento.
//Se inicializan en 0 debido a que son contadores.
//Al ser contadores será posible modificar el arreglo.
//Fueron declarados globales con motivos de obtimización.

void Repeat_Insert_Nodo(NODO *List);
void Insert_Nodo(NODO *List);
void Search_Nodo(NODO *List);
void Modify_Nodo(NODO *List);
void Delate_Nodo(NODO *List);
//Metodos de despliegue en una lista doble.
void Show_List_Down(NODO *List);
void Show_List_UP(NODO *List);
//Métodos para recorrer una lista mediante ordenamiento.
void Minimun_To_Maximun(NODO *List);
void Maximun_To_Minimun(NODO *List);

int main() 
{
	int Opcions=0;

	NODO List;
	List.Data=0;
	List.Next=NULL;
	List.Fore=NULL;

	do
	{
		printf("1). Insertar elemento a la lista.\n");
		printf("2). Desplegar la lista del primer al ultimo elemento.\n");
		printf("3). Desplegar la lista del ultimo al primer elemento.\n");
		printf("4). Mostrar los elementos de menor a mayor.\n");
		printf("5). Mostrar los elementos de mayor a menor.\n");
		printf("6). Buscar un elemento en la lista.\n");
		printf("7). Modificar un elemento en la lista.\n");
		printf("8). Eliminar un dato de la lista.\n");
		printf("9). Salir del programa.\n");
		scanf("%d", &Opcions);
		printf("\n");
		if(Opcions<=0 || Opcions>=10)
		{
			printf("Opción invalida, por favor intentelo de nuevo.\n");
			exit(0);
		}
		printf("Usted ha escogido la opción: [%d].\n",Opcions);
		printf("\n");

		switch(Opcions) 
		{
			case 1:
			{
				printf("Ingresar elemento a la lista.\n");
				Repeat_Insert_Nodo(&List);
			}
			break;
			case 2:
			{
				printf("Mostar elementos del primero al ultimo.\n");
				Show_List_UP(&List);
			}
			break;
			case 3:
			{
				printf("Mostrar lista del ultimo al primer elemento.\n");
				Show_List_Down(&List);
			}
			break;
			case 4:
			{
				Minimun_To_Maximun(&List);
			}
			break;
			case 5:
			{
				Maximun_To_Minimun(&List);
			}
			break;
			case 6:
			{
				printf("Busque el elemento que deseé.\n");
				Search_Nodo(&List);
			}
			break;	
			case 7:
			{
				printf("ADVERTENCIA\n");
				printf("Para que esta opción funcione correctamente, debe de haber usado primero la de buscar un elemento.\n");
				printf("Cambiar algun elemento de la lista\n");
				Modify_Nodo(&List);
			}
			break;
			case 8:
			{
				printf("Eliminar un elemento de la lista.\n");
				Delate_Nodo(&List);
			}
			break;
			case 9:
			{
				printf("Ha salido del programa.\n");
				exit(0); break;
			}	
		}
	} 
	while(Opcions!=9);
	
	return 0;
}

void Insert_Nodo(NODO *List)
{
	NODO* New_Nodo=(NODO *)malloc(sizeof(NODO)); //Crea el elemento para agregarlo a la lista.

	printf("Ingrese el dato que contendra el nuevo Nodo: \n");
	scanf("%d", &New_Nodo->Data);
	
	if(First==NULL) //Cuando no hay datos ingresados en la lista
	{
		First=New_Nodo; //El primer elemento es igual al nuevo.
		First->Next=NULL; //Entonces el primero apunta al siguiente dato que no existe.
		First->Fore=NULL; //De igual forma el primero debe de apuntar al siguiente dato que tampoco existe.
		//Para este caso donde el primero apunte a un nulo, se debe interpetar 
		//como si se apuntara un número, inexistente negativo
		Last=First; //Finalmente como solo hay un elemento el primero es igual al ultimo.
	}
	else //Si ya se ingreso un dato en la lista.
	{
		//Por propiedad de la lista doble enlazada.
		Last->Next=New_Nodo; //El ultimo apunta al siguiente, el siguiente será un nuevo elemento.
		New_Nodo->Next=NULL; //El nuevo elemento, que es el ultimo debe apuntar a un siguiente dato, pero este esta vacio.
		New_Nodo->Fore=Last; //El nuevo elemento esta en el medio por lo que debe apuntar a un dato anterior.
		//Al apuntar al dato anterior y como es una lista circular el anterior sería el ultimo.
		Last=New_Nodo; //El ultimo entonces es igual al nuevo elemento.
	}
	printf("El elemento ha sido ingresado con exito.\n");
}

void Repeat_Insert_Nodo(NODO *List)
{
	int i, elements;

	printf("¿Cuántos elementos desea ingresar en la lista.\n");
	scanf("%d", &elements);

	for(i=0; i<elements; i++)
	{
		Insert_Nodo(List);
	}
}

//La funciones buscar y modificar un elemento se hacen en referencia a un primer elemento.
//Pero dado que es una lista circular, bien se puede estblecer que el nodo actual sea igual al ultimo nodo.
//Es decir First(primer nodo)=Actual equivale a que Last(ultimo nodo)=Actual.
void Search_Nodo(NODO *List) 
{
	//Este código es universal en el programa pues recorre la lista.
	//El nodo actual es un auxiliar para recorrer la lista.
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Permite almacenar los datos en la lista.
	Actual=First; //Para que la lista se recorra conforme se ingresan los datos y dado que es una lista circular.
	//Al momento de ingresar un dato, ese primer dato será el dato actual.
	//Siendo el primer dato tenemos:
	//[Sin elementos]-->[Actual]-->[Posible nuevo dato.]

	printf("Ingrese el dato a Buscar: \n");
	scanf("%d", &Research_Nodo);
	
	if(First!=NULL) //En caso de que la lista este vacia.
	{
		do //Recorre la lista.
		{	
			if(Actual->Data==Research_Nodo) //Recorre la lista hasta encontrar el elemento buscado.
			{
				printf("El elemento con el dato (%d) fue encontrado.\n",Research_Nodo);
				Find_Nodo=1; //Avala que el nodo fue encontrado.
			}
			Actual=Actual->Next; //Actualiza el apuntador en tanto se recorra la lista.
		}
		while(Actual!=NULL && Find_Nodo!=1);
		if(Find_Nodo==0) //En caso de que el usuario ingresara un dato erroneo.
		{
			printf("El elemento no fue encontrado.\n");
		}
	}
	else 
	{
		printf ("No hay elementos en la lista.\n");
	}
}

void Modify_Nodo(NODO *List) 
{
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los elementos introducidos.
	Actual=First; //Permite recorrer la lista, mientras se actualiza.

	printf("Ingrese el dato a buscar para modificar: \n");
	scanf("%d", &Find_Nodo);
	
	if(First!=NULL) 
	{
		do //Recorre la lista.
		{	
			if(Actual->Data==Find_Nodo) //Recorre la lista hasta encontrar el elemento buscado.
			{
				printf("El elemento con el dato (%d) fue encontrado\n",Find_Nodo);
				printf("Ingrese el nuevo dato para este lugar en la lista: \n");
				scanf("%d", &Actual->Data); //Para modificar el elemento.
				printf("\nEl dato ha sido modifcado con exito\n");
				Find_Nodo=1; //Establece que se ha encontrado el elemento.
			}
			Actual=Actual->Next; //Actualiza el apuntador en tanto se recorra la lista.
		}
		while(Actual!=NULL && Find_Nodo!=1);
		if(Find_Nodo==0) //En caso de que el usuario ingresara un dato erroneo.
		{
			printf("El elemento no fue encontrado\n");
		}
	}
	else 
	{
		printf("La lista se encuentra vacia\n");
	}
}

void Delate_Nodo(NODO *List) 
{
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los elementos introducidos.
	Actual=First; //Permite recorrer la lista, mientras se actualiza.

	NODO* Fore=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los elementos introducidos.
	Fore=NULL; //Es igual a nulo pues se ira actualizando conforme se ingresen los datos en la lista.

	printf("Ingrese el elemento a buscar para eliminar: \n");
	scanf("%d" ,&Research_Nodo);
	
	if(First!=NULL) //Recorre la lista.
	{
		do //Permite recorrer la lista una vez ingresados los datos.
		{	
			if(Actual->Data==Research_Nodo) //Recorre la lista hasta encontrar el elemento a eliminar.
			{	
				//Se establcen tres casos en donde se puede eliminar un elemento.
				//1). Cuando el elemento a eliminar sea el primero.
				//2). Cuando el elemento a eliminar sea el ultimo.
				//3). Cuando el elemento a eliminar este en el centro de la lista.
				if(Actual==First)
				{
					First=First->Next;
					First->Fore=NULL; //Establece que se elimine el dato si no hay datos anteriores al primero ingresado.
				}
				else
					if(Actual==Last) 
					{
						Fore->Next=NULL; //elimina el dato siguiente al anterior.
						//[Fore]-->[Next]; [Next]->No existe otro elemento.
						//Si no existe otro elemento después del que le sigue a fore, ese next se elimina.
						Last=Fore; //Puesto que es una lista circular el ultimo en algun punto será el anterior.
					}
				else
				{
					Fore->Next=Actual->Next;
					//Establece la linealidad en la lista, es decir el dato actual apunta al siguiente como al anterior.
					Actual->Next->Fore=Fore;
					//Entonces el anterior es el dato a eliminar.
				}
				printf("El nodo fue eliminado con exito\n");
				Find_Nodo=1; //Avala que el nodo fue eliminado
				//Es decir alguna de las tres condiciones fue cumplida.
			}
			Fore=Actual;
			Actual=Actual->Next; //Actualiza el apuntador, lo que hace que la lista se recorra.
		}
		while(Actual!=NULL && Find_Nodo!=1);
		if(Find_Nodo==0) //Si el usuario se equivoca al introducir un dato.
		{
			printf ("El elemento no fue encontrado\n");
		}
		else
		{
			free(Fore); //Se libera la memoria almacenada del dato anterior.
		}
	}
	else
	{
		printf("La lista no tiene elementos\n");
	}
}

//NOTA: show_list down y up son funciones inverss una de otra.
void Show_List_UP(NODO *List)
{
	//NOTA: Una lista circular doble ningun elemento apuntador puede apuntar a NULL.
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los elementos introducidos.
	Actual=First; //Permite recorrer la lista.
	//El nodo de centro debe ser igual al primero para que se desplegue del primero al ultimo.

	if(First!=NULL) //En caso de que la lista este vacia.
	{
		while(Actual!=NULL) //En tanto no se llegue a un ultimo elemento.
		{
			printf("%d\n",Actual->Data); //Imprime el valor del elemento que se creo conforme se ingresa en el aareglo abstracto.
			//Ambas igualdades establecen una actualización en la lista que se crea.
			Actual=Actual->Next; //Actualiza el apuntador, en referencia a que existe un dato siguiente al actual.
		 	//Actualiza el apuntador, en referencia a que existe un dato anterior al actual.
			//Al hacer que la lista se actualize se pueden ingresar mas datos.
		}
	}
	else
	{
		printf("La lista esta vacia.\n");
	}
}

void Show_List_Down(NODO *List) 
{
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los elementos introducidos.
	Actual=Last; //Por ser una lista circular, permite recorrer la lista.
	//El nodo de centro debe ser igual al ultimo para que se desplegue del ultimo al primero.

	if(First!=NULL) //En caso de que no haya elementos en la lista.
	{
		while(Actual!=NULL) //En tanto no se llegue a un ultimo elemento.
		{
			printf("%d\n" ,Actual->Data); //Imprime el valor del elemento que se creo conforme se ingresa en el aareglo abstracto.
			Actual=Actual->Fore; //Actualiza el apuntador, lo que hace que la lista se actualize.
			//Al hacer que la lista se actualize se pueden ingresar mas datos.
		}
	}
	else
	{
		printf ("La lista esta vacia.\n");
	}	
}

void Minimun_To_Maximun(NODO *List)
{
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los datos.
	Actual=First; //Establece que se comparen los elementos, Permite recorrer la lista.
	//Al ordenar mediante burbuja evita que cause el segmentation fault.
	NODO* Jump=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los datos.
	//Sirve de compración para comparar los valores.

	int Aux=0; //Almacena el dato a comparar.

	if(First!=NULL)
	{
		printf("Los datos ordenados de menor a mayor son: \n");
		printf("\n");
		Jump=First; //Modifica el valor del pivote.
		//Hace que el nodo se compare meidante saltos.
		while(Actual!=NULL) //Establece un ciclo for con un indice abstrato i.
		{
			//Recorre el arreglo de modo que el valor del nodo se modifique.
			Jump=Actual->Next; 
			
			while(Jump!=NULL) //Establece un ciclo for con un indice abstrato j.
			{
				if(Actual->Data>Jump->Data)
				{
					//Equivale a un orden de burbuja con indices.
					/*
					siendo auxiliar el alamcen de datos
					Nodo actual que apunta al dato es el indice i.
					Nodo pivote que apunta al mismo dato es el indice j.
					*/
					Aux=Actual->Data;			
					Actual->Data=Jump->Data;
					Jump->Data=Aux;
				}
				Jump=Jump->Next; //Hace que el pivote se recorra si el dato siguiente es mayor.
			}
			printf("%d\n", Actual->Data);
			Actual=Actual->Next; //Actualiza el apuntador.
		}	
	}
	else
	{
		printf("No tiene elementos en la lista.\n");
	}
	printf("\n");	
}

void Maximun_To_Minimun(NODO *List)
{
	NODO* Actual=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los datos.
	Actual=First; //Establece que se comparen los elementos.
	//Al ordenar mediante burbuja evita que cause el segmentation fault.
	NODO* Jump=(NODO *)malloc(sizeof(NODO)); //Auxiliar que almacena los datos.

	int Aux=0; //Alamcena el dato a comarar.

	if(First!=NULL)
	{
		printf("Los datos ordenados de menor a mayor son: \n");
		printf("\n");
		Jump=First; //Modifica el valor del pivote.
		//Hace que el nodo se compare meidante saltos.
		while(Actual!=NULL) //Establece un ciclo for con un indice abstrato i.
		{
			//Recorre el arreglo de modo que el valor del nodo se modifique.
			Jump=Actual->Next; 
			
			while(Jump!=NULL) //Establece un ciclo for con un indice abstrato j.
			{
				if(Jump->Data>Actual->Data)
				{
					//Equivale a un orden de burbuja con indices.
					/*
					siendo auxiliar el alamcen de datos
					Nodo actual que apunta al dato es el indice i.
					Nodo pivote que apunta al mismo dato es el indice j.
					*/
					Aux=Actual->Data;			
					Actual->Data=Jump->Data;
					Jump->Data=Aux;
				}
				Jump=Jump->Next; //Hace que el pivote se recorra si el dato siguiente es mayor.
			}
			printf("%d\n", Actual->Data);
			Actual=Actual->Next; //Actualiza el apuntador.
		}	
	}
	else
	{
		printf("No tiene elementos en la lista.\n");
	}
	printf("\n");	
}