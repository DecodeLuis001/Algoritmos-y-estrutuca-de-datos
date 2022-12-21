#include<stdio.h>
#include<stdlib.h>

#define maximo 9 //número de elementos máximos con los que se pueden trabajar.

typedef struct
{
    unsigned int Elementos_Totales; //Será el tamaño total del arreglo
    unsigned int Dimension; //El número de elementos permitidos en el arreglo.
    int Inicio;
    int Final;
    int *Datos_ingresados; //apunta al arreglo para que se vaya almacenando.
}
FILA;

char IsFull(FILA *f); //Unico prototipo debido a que es necesaria en partes extra del código especificamente en el enfilar.

FILA* Crear_Fila(unsigned int Elementos_Totales)
{
    FILA *fila;
    
    fila=(FILA *)malloc(sizeof(FILA));
    fila->Elementos_Totales=Elementos_Totales;
    fila->Dimension=0;
    fila->Inicio=-1; //Indica que no hay ningun elemento en el arrelgo, el primer elemento empieza en 0.
    fila->Final=-1; //Establece la condición de que la fila se ciclica.
    fila->Datos_ingresados=(int *)malloc(sizeof(FILA)*Elementos_Totales);
    
    return(fila);
}

void Capturar_Datos(FILA *fila)
{
    int i;
    
    if(&(fila->Datos_ingresados[fila->Inicio])==NULL)
    {
        printf("Dato[0]= \n");
        fpurge(stdin);
        scanf("%d",&fila->Datos_ingresados[0]);
    }
    else
    {
        for(i=0;i<fila->Elementos_Totales;i++)
        {
            printf("\n Ingrese el dato [%i]= ",i);
            scanf("%d",&fila->Datos_ingresados[i]);
        }
    }
    printf("\n");
}

void Eliminar_Fila(FILA *fila)
{
    free(fila->Datos_ingresados); //Elimina la memoria interna.
    free(fila); //Elimina la memoria de la estructura.
    printf("La fila ha sido eliminada\n");
}

char Enqueue(FILA *fila)
{
    int i;
    
    if(IsFull(fila))
    {
        return 0;
    }
    else
    {
        for(i=0; i<fila->Elementos_Totales; i++)
        {
            fila->Final++;
            fila->Datos_ingresados[fila->Final]=fila->Datos_ingresados[i];
            fila->Dimension++;
        }
        
    }
    return 1;
}

void Dequeue(FILA *fila)
{
    int Dato_eliminado;
    //int guardado;
    
    fila->Inicio++; //El arreglo se alamacena conforme se ingresa un nuevo número.
    Dato_eliminado=fila->Datos_ingresados[fila->Inicio]; //Sirve para que el primer dato que se tiene en el arreglo sea el primero en salir.
    printf("El dato que ha sido eliminado es: %i\n",Dato_eliminado);
    fila->Elementos_Totales++; //Almacena el arreglo restante una vez eliminado el primer número.
}

char IsFull(FILA *fila)
{
    if(fila->Dimension==fila->Elementos_Totales)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Imprimir_Fila(FILA *fila)
{
    int i;
    
    for(i=fila->Final;i>=0;i--)
    {
        printf("Posicion[%d]=%i\n",i, fila->Datos_ingresados[i]);
        printf("\n");
    }
    printf("\n");
}

int Primer_Dato(FILA *fila)
{
    int dato_inicial; //Servira para saber el dato que esta en primer lugar a la fila.
    
    fila->Inicio++; //Saber el primer valor del arreglo.
    dato_inicial=fila->Datos_ingresados[fila->Inicio];
    fila->Inicio--; //Saber el ultimo valor del arreglo.
    
    return(dato_inicial);
}

char IsEmpty(FILA *fila)
{
    if(fila->Final==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    FILA *fila_01;
    int Casos=1;
    int Opciones;
    
    fila_01=Crear_Fila(maximo); //Inicializa la fila creando un vector de nueve elementos.
    
    do
    {
        printf("1) Ingresar datos a la fila (Se imprimime la fila).\n");
        printf("2) Mostrar el frente de la fila.\n");
        printf("3) Sacar dato del frente.\n");
        printf("4) Eliminar fila y salir del programa.\n");
        printf("\n");
        scanf("%i",&Opciones);
        printf("\n");
        if(Opciones>=5)
        {
            printf("La opción es invalida intente de nuevo por favor.\n");
            printf("\n");
            break;
        }
        //return(Opciones);
        
        switch(Opciones)
        {
            case 1:
            {
                printf("Solo puede ingresar 9 datos en la fila\n");
                
                if(Enqueue(fila_01))
                {
                    Capturar_Datos(fila_01);
                }
                else
                {
                    printf("No se puede agregar más datos, la fila ha alcanzado su limite.\n");
                }
                printf("Los datos ingresados al arreglo son: \n");
                printf("\n");
                if(IsEmpty(fila_01))
                {
                    printf("No hay datos que imprimir en la fila\n");
                    break;
                }
                Imprimir_Fila(fila_01);
            }
            break;
            case 2:
            {
                if(IsEmpty(fila_01))
                {
                    printf("No hay datos que mostrar, la fila esta vacia.\n");
                    break;
                }
                printf("El dato que esta al frente es: %i\n\n",Primer_Dato(fila_01));
            }
            break;
            case 3:
            {
                if(IsEmpty(fila_01))
                {
                    printf("No hay datos que eliminar del arreglo.\n");
                    printf("\n");
                    continue;
                }
                else
                {
                    Dequeue(fila_01);
                    printf("\n");
                    continue;
                }
                return Opciones;
            }
            break;
            case 4:
            {
                if(IsEmpty(fila_01))
                {
                    printf("No hay datos que eliminar de la fila, la fila esta en ceros.\n");
                    return 0; break;
                }
                Eliminar_Fila(fila_01);
                return 0; break;
            }
        }
        Casos++;
    }
    while(Casos<=3);
    
    return 0;
}

