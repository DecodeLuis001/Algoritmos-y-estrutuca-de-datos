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
	float real;
	float imaginario;
}
COMPLEJO;

typedef struct 
{
    float *A_datos_Reales, *A_datos_Imaginairos;
    float Elementos_Reales, Elementos_Imaginarios;
}
VECTOR;

VECTOR* Crea_vector_Real(float Dato);
VECTOR* Crea_vector_Imaginario(float Dato);
void Capturar(VECTOR *Reales);
void Capturar(VECTOR *Imaginarios);
void Imprimir_Vector_Real(VECTOR *I_Real);
void Imprimir_Vector_Imaginario(VECTOR *I_Imaginario);
void Eliminar_Real(VECTOR *I_Real);
void Eliminar_Imaginario(VECTOR *I_Imaginario);
float Suma_Complejos_Reales(VECTOR *R);
float Suma_Complejos_Imaginarios(VECTOR *I);
float Promedio_Real(VECTOR *R);
float Promedio_Imaginario(VECTOR *I);

//Asignacion de memoria necesaria.
//Generar memoria para generara viarable de esa estrucutra, luego agrgar una cantidad N de dados a esa estructura usando malloc.
VECTOR* Crea_vector_Real(float Dato_Real)
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
	ptr->Elementos_Reales=Dato_Real;
	//Forma de reservar la memoria necesaria mediante cast.
	ptr->A_datos_Reales=(float *)malloc(sizeof(float) *Dato_Real);

	return(ptr); //Regresa la dirección que contiene y llega a V.
}

VECTOR* Crea_vector_Imaginario(float Dato_Imaginario)
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
	ptr->Elementos_Imaginarios=Dato_Imaginario;
	//Forma de reservar la memoria necesaria mediante cast.
	ptr->A_datos_Imaginairos=(float *)malloc(sizeof(float) *Dato_Imaginario);

	return(ptr); //Regresa la dirección que contiene y llega a V.
}

void Capturar_Reales(VECTOR *Reales)
{
	unsigned int i;

	for(i=0; i<Reales->Elementos_Reales; i++)
	{
		printf("\n Ingrese el dato: Posición[%i]= ", i);
		//Usa la aritmetica de apuntadores.
		scanf("%f", Reales->A_datos_Reales+i); //El indice i modifica la dirección de los elementos ingresados.
	}
	printf("\n");
}

void Capturar_Imaginarios(VECTOR *Imaginarios)
{
	unsigned int j;

	for(j=0; j<Imaginarios->Elementos_Imaginarios; j++)
	{
		printf("\n Ingrese el dato: Posición[%i]= ", j);
		//Usa la aritmetica de apuntadores.
		scanf("%fj", Imaginarios->A_datos_Imaginairos+j); //El indice i modifica la dirección de los elementos ingresados.
	}
	printf("\n");
}

void Imprimir_Vector_Real(VECTOR *I_Real)
{
    unsigned int i;
    
    for(i=0; i<I_Real->Elementos_Reales; i++)
    {
        //El segundo %i imprime el contenido, meidante el uso de apuntadores.
        //El apuntador obtiene y lee las direcciones de los datos almacenados.
        printf("Posición[%i]=%.2f\n", i, *(I_Real->A_datos_Reales+i));
    }
}

void Imprimir_Vector_Imaginario(VECTOR *I_Imaginario)
{
    unsigned int j;
    
    for(j=0; j<I_Imaginario->Elementos_Imaginarios; j++)
    {
        //El segundo %i imprime el contenido, meidante el uso de apuntadores.
        //El apuntador obtiene y lee las direcciones de los datos almacenados.
        printf("Posición[%i]=%.2fj\n", j, *(I_Imaginario->A_datos_Imaginairos+j));
    }
}

//Libera memoria a tráves de malloc-free.
void Eliminar_Real(VECTOR *I_Real)
{
    free(I_Real->A_datos_Reales); //Corespondiente al segundo malloc.
    free(I_Real); //Correspondiente al primer malloc.
}

//Libera memoria a tráves de malloc-free.
void Eliminar_Imaginario(VECTOR *I_Imaginario)
{
    free(I_Imaginario->A_datos_Imaginairos); //Corespondiente al segundo malloc.
    free(I_Imaginario); //Correspondiente al primer malloc.
}

float Suma_Complejos_Reales(VECTOR *R)
{
    int suma=0;
    unsigned int i;
    float resultado;
    
    for(i=0; i<R->Elementos_Reales; i++)
    {
        //Accedemos al dato de memoria, mientras se acumula en suma.
        suma+=*(R->A_datos_Reales+i);
    }
    resultado=(float)suma;
    return(resultado);
}

float Suma_Complejos_Imaginarios(VECTOR *I)
{
    int suma=0;
    unsigned int j;
    float resultado;
    
    for(j=0; j<I->Elementos_Imaginarios; j++)
    {
        //Accedemos al dato de memoria, mientras se acumula en suma.
        suma+=*(I->A_datos_Imaginairos+j);
    }
    resultado=(float)suma;
    return(resultado);
}

float Promedio_Real(VECTOR *R)
{
    int suma=0;
    unsigned int i;
    float resultado;
    
    for(i=0; i<R->Elementos_Reales; i++)
    {
        //Accedemos al dato de memoria, mientras se acumula en suma.
        suma+=*(R->A_datos_Reales+i);
    }
    resultado=(float)suma/R->Elementos_Reales;
    return(resultado);
}

float Promedio_Imaginario(VECTOR *I)
{
    int suma=0;
    unsigned int j;
    float resultado;
    
    for(j=0; j<I->Elementos_Imaginarios; j++)
    {
        //Accedemos al dato de memoria, mientras se acumula en suma.
        suma+=*(I->A_datos_Imaginairos+j);
    }
    resultado=(float)suma/I->Elementos_Imaginarios;
    return(resultado);
}


int main()
{
    VECTOR *R, *I;
    float Real, Imaginario;

	printf("¿Cuántos datos reales desea ingresar?:\n");
	fpurge(stdin);
	scanf("%f", &Real);
    if(Real<0)
    {
        printf("No puede ingresar una cantidad negativa de datos.\n");
    }
	printf("\n");
	R=Crea_vector_Real(Real);

	printf("¿Cuántos datos imaginarios desea ingresar?:\n");
	fpurge(stdin);
	scanf("%fj", &Imaginario);
    if(Imaginario<0)
    {
        printf("No puede ingresar una cantidad negativa de datos.\n");
    }
	printf("\n");
	I=Crea_vector_Imaginario(Imaginario);


	printf("Ingrese los datos para capturar su vector real: \n");
	Capturar_Reales(R);
	printf("Ingrese los datos para capturar su vector imaginario: \n");
	Capturar_Imaginarios(I);
    
    printf("El vector real capturado es: \n");
    Imprimir_Vector_Real(R);
    printf("\n");
    printf("El vector imaginario capturado es: \n");
    Imprimir_Vector_Imaginario(I);
    printf("\n");
    
    printf("\n");
    printf("La suma de los datos reales introducidos es: %.2f\n", Suma_Complejos_Reales(R));
    printf("\n");
    printf("La suma de los datos imaginarios introducidos es: %.2fj\n", Suma_Complejos_Imaginarios(I));
    printf("\n");
    if(Suma_Complejos_Imaginarios(I)<0)
    {
        printf("La suma general es: %2.2f%2.2fj\n",Suma_Complejos_Reales(R), Suma_Complejos_Imaginarios(I));
    }
    else
    {
        printf("La suma general es: %2.2f+%2.2fj\n",Suma_Complejos_Reales(R), Suma_Complejos_Imaginarios(I));
    }
    printf("\n");
    
    printf("El promedio de los número reales introducidos es: %.2f\n", Promedio_Real(R));
    printf("\n");
    printf("El promedio de los número imaginarios introducidos es: %.2f\n", Promedio_Imaginario(I));
    printf("\n");
    if(Promedio_Imaginario(I)<0)
    {
        printf("El promedio general es: %2.2f%2.2fj\n",Promedio_Real(R), Promedio_Imaginario(I));
    }
    else
    {
        printf("El promedio general es: %2.2f+%2.2fj\n",Promedio_Real(R), Promedio_Imaginario(I));
    }
    printf("\n");
    
	Eliminar_Real(R);
    Eliminar_Imaginario(I);
	
	printf("\n");
	return 0;
}
