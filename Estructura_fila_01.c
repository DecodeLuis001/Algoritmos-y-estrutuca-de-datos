//Cola estática circular.

#include<stdio.h>
#include<stdlib.h>
#define true 1	//Cumplen la función de funciones boleanas dado que en c no estn implementadas.
#define false 0 
#define maximo 9 //número de eleemntos máximos con los que se pueden trabajar.

typedef struct 
{	//son las posiciones de cada elemento que se introduce
	int inicio;
	int final;
	int vector[maximo];
    int N_Elementos;
    unsigned int Dimension_fila;
    int* Datos;
}
FILA;

int IsEmpty(FILA *fila); //único prototipo debido a que es requerida en tres funciones ademas del int main().

void Iniciar_fila(FILA *fila)
{
    //int vector[maximo];
    
    //fila=(FILA *)malloc(sizeof(FILA));
    //fila->vector[8]=vector[8];
    //fila->Dimension_fila=0;
    fila->inicio=-1;
    fila->final=-1; //Establece el modo ciclicio en el programa mismo inicio, mismo final.
    //fila->Datos=(int *)malloc(sizeof(int)*vector[8]);
}

/*
void Eliminar_Fila(FILA* fila)
{
    free(fila->Datos); //Elimina la memoria interna.
    free(fila); //Elimina la memoria de la estructura.
}
*/

int Elementos(FILA *fila)
{
    if(IsEmpty(fila))
    {
        return 0;
    }
    else
    {
        if(fila->inicio<=fila->final)
        {
            return fila->final - fila->inicio+1; //El más uno necesario para que el programa
            //cuente con lógica, dado que empieza a contar desde el elemento 0.
        }
        else //en caso de que se meta un dato extra al máximo permitido.
        {
            return maximo - fila->inicio + fila->final + 1;
        }
    }
}

int IsFull(FILA *fila)
{
    if(Elementos(fila)==maximo) //Comprueba que la fila no puede recibir más elementos debido a la capacidad del arreglo; el arreglo tiene una capacidad máxima de 9 elementos de 0 a 8.
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Esta función es la que permite hacer circular a la fila.
void Elemento_extra(FILA *fila, int vector_fila)
{
    if(!IsFull(fila)) //Expresa que el elemento es el tope de la fila
    { //Sin embargo la fila puede o no estar llena.
        if(IsEmpty(fila))
        {
            fila->inicio=0;
        }
        if(fila->final==(maximo-1))
        {
            fila->final=0; //Asegura que la posición cero no esta ocuapada.
        }    //Previene un sementation fault.
        else
        {
            fila->final++;
        }
        fila->vector[fila->final]=vector_fila;
        //Para saber el comportamiento de los elementos ingresados en la fila.
        printf("Esta en la posición inicial %i\n", fila->inicio);
        printf("El elemento actual es: %d esta en la posición final %i\n\n",fila->vector[fila->final], fila->final);
        //Muestra el movimiento del ciclo conforme al elemento que se agregue.
    }
    else
    {
        printf("La fila ha alcanzado su máximo de elementos\n");
    }
}

void Eliminar_Elemento(FILA *fila)
{
    if(!IsEmpty(fila))
    {
        int vaiable_temporal=fila->inicio;
        if(Elementos(fila)==1)
        {
            Iniciar_fila(fila);
        }
        else
        {
            fila->inicio++;
        }
        printf("\n");
        printf("Elemento que ha sido eliminado: %d\n", vaiable_temporal); //Ayuda a entender que el programa tiene un modo de ciclado conforme se van eliminando elementos.
        printf("La nueva ubicación actual es: %d con el valor %d y el final es: %d\n",fila->vector[fila->inicio],fila->inicio, fila->final);
        //Visualiza el ciclo de una mejor manera al usuario, recorre el arreglo para saber que elemento fue eliminado.
        printf("\n");
    }
    else
    {
        printf("La fila esta vacia, es imposible eliminar el elemento\n");
    }
}

int IsEmpty(FILA *fila)
{
    if(fila->final==-1) //valida que la cola este vacia o inicia en elemento cero.
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    FILA *fila;
    //int vector[maximo];
    //int i, N_Elementos;
    
    Iniciar_fila(fila);
    
    /*
    printf("¿Cuántos elementos desea ingresar?\n");
    scanf("%d", &N_Elementos);
    printf("\n");
    for(i=0; i<N_Elementos; i++)
    {
        if(N_Elementos<vector[8])
        {
            printf("El máximo de valores ha sido ingresado\n");
        }
        else
        {
            Elemento_extra(fila, N_Elementos);
        }
    }
    */
    
	printf("\n");
	Elemento_extra(fila, 1); //Cada una de estas funciones agrega un elemento diferente a la lista.
	Elemento_extra(fila, 2); 
	Elemento_extra(fila, 3);
	Elemento_extra(fila, 4);
	Elemento_extra(fila, 5);
	Elemento_extra(fila, 6);
	Elemento_extra(fila, 7);
	Elemento_extra(fila, 8);
	Elemento_extra(fila, 9);
    Elemento_extra(fila, 10); //Demuestra que existe un limite en el programa.
	
    Eliminar_Elemento(fila); //Funciona como una forma de recorrer el arreglo.
	Eliminar_Elemento(fila); //Cada que se agrega esta función las posiciones de inicio y final cambian.
    Eliminar_Elemento(fila);
    printf("\n");
    printf("El elemento inicio es: %d y el final es: %d\n", fila->vector[fila->inicio], fila->vector[fila->final]);

    //Eliminar_Fila(fila);
    
	return true;
}
