//Colas, filas:
/*
Se les conoce como FIFO; el primer dato en entrar es el ultimo en salir.
Finalidad: alamacenar datos en espera conforme ingresan a la estructura.
Esta estrucutra de datos posee varias funciones, pero las dos principales son:
encolar(), desencolar().

Existen tres variaciones principales de las filas:
1.) Circulares: el primer y el ultimo elemento estan unidas.
2.) Prioridad: los elementos que ingresan tienen un orden especifico de orden.
3.) Doblemente terminadas: los elementos pueden entrar o salir ya sea por el principio o el final de la cola.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float valor;
}
COMPLEJO;

typedef struct 
{
	unsigned int Elementos_Totales;
	unsigned int Dimension_fila;
	unsigned int Identificador_inicio;
	unsigned int Identificador_final;
	int* Datos; //apunta al arreglo para que se vaya almacenando.
}
FILA;

FILA* Crear_Fila(unsigned int Elementos_Totales);
void Eliminar_Fila(FILA* fila);
char Enquenque(FILA *fila, int Dato);
char IsFull(FILA* fila);
void Imprimir_fila(FILA* fila);

//Tarea, fila en forma circular.
void Dequeue(FILA *fila, int *Dato);
char IsEmpty(FILA *fila);               //Lista
int front(FILA *fila);
void Capturar_valor(COMPLEJO *fila);
void Capturar_fila(FILA* fila);

int main(void)
{
    unsigned int Elementos_Totales;
	FILA *fila_01;
    
    //fila_01=Crear_Fila(3);
	fila_01=Crear_Fila(Elementos_Totales);
    printf("\n");
    Capturar_fila(fila_01);
    printf("\n");
    
    /*
	if(!Enquenque(fila_01, 1))
	{
		printf("La fila ha alcanzado su valor máximo\n");
	}
	if(!Enquenque(fila_01, 2))
	{
		printf("La fila ha alcanzado su valor máximo\n");
	}
	if(!Enquenque(fila_01, 3))
	{
		printf("La fila ha alcanzado su valor máximo\n");
	}
	if(!Enquenque(fila_01, 4))
	{
		printf("La fila ha alcanzado su valor máximo\n");
	}
     */
    
	printf("\n");
	Imprimir_fila(fila_01);
	printf("\n");

	Eliminar_Fila(fila_01);
	return 0;
}

void Imprimir_fila(FILA* fila)
{
	int i;
										//i=0;
	for(i=fila->Identificador_final; i>=0; i--)
	{
        printf("Los datos ingresados son: %i\n", fila->Datos[i]);
	}
	printf("\n");
}

FILA* Crear_Fila(unsigned int Elementos_Totales)
{
    //FILA *fila;
    FILA *fila=NULL;
    
    printf("¿Cuantos elementos desea ingresar en la fila?:\n");
    scanf("%d", &Elementos_Totales);
    
	fila=(FILA *)malloc(sizeof(FILA));
	fila->Elementos_Totales=Elementos_Totales;
	fila->Dimension_fila=0;
	fila->Identificador_inicio=-1; //Indica que no hay ningun elemento en el arrelgo, el primer elemento empieza en 0.
	fila->Identificador_final=-1;
	fila->Datos=(int *)malloc(sizeof(int)*Elementos_Totales);
    
	return fila;
}

void Eliminar_Fila(FILA* fila)
{
	free(fila->Datos); //Elimina la memoria interna.
	free(fila); //Elimina la memoria de la estructura.
}

char Enquenque(FILA *fila, int Dato)
{
	if(IsFull(fila))
	{
		printf("La fila ha alcanzado su valor máximo\n");
		return 0;
	}
	else
	{
		fila->Identificador_final++;
		fila->Datos[fila->Identificador_final]=Dato;
		fila->Dimension_fila++;
	}
	return 1;
}

char IsFull(FILA* fila)
{
	if(fila->Dimension_fila==fila->Elementos_Totales)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char IsEmpty(FILA *fila)
{
    if(fila->Identificador_final==-2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Capturar_valor(COMPLEJO *fila)
{
    printf("Ingrese el dato: \n");
    scanf("%f", &(fila->valor));
}

void Capturar_fila(FILA* fila_capturada)
{
    unsigned int i;
    
    for(i=0; i<fila_capturada->Elementos_Totales; i++)
    {
        Capturar_valor(fila_capturada->A_datos_complejos+i);
    }
}
