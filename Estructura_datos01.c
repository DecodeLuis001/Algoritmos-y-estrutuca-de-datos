/*

Estructura de datos: agrupación lógica de la información o datos de distinto tipo que tiene un nombre común.
	sintaxis de la estrcutura de datos.

	typedef struct
	{
		tipo_de_dato Miembro1(variable1);
		tipo_de_dato Miembro2(variable2);
		...
		tipo_de_dato MiembroN(variablN);
	}
	Nombre_de_la_estructura;
*/

#include<stdio.h>
typedef struct
{
	float re;
	float im;
}
COMPLEJO;

void Imprimir_complejo(COMPLEJO X);
COMPLEJO Suma_Complejos(COMPLEJO A, COMPLEJO B);
COMPLEJO Multiplica_Complejos(COMPLEJO A, COMPLEJO B);

int main()
{	
	COMPLEJO Z, W, R, M;

	Z.re=2;
	Z.im=-3;
	W.re=1;
	W.im=5;
	Imprimir_complejo(Z);
	printf("\n");
	Imprimir_complejo(W);

	R=Suma_Complejos(Z,W);
	printf("La suma de los complejos es: \n");
	Imprimir_complejo(R);
    M=Multiplica_Complejos(Z,W);
    printf("La multiplicación de los complejos es: \n");
    Imprimir_complejo(M);
	printf("\n");
	return 0;
}

void Imprimir_complejo(COMPLEJO X)
{
	if(X.im<0)
	{
		printf("%2.2f%2.2fj\n",X.re, X.im);
	}
	else
	{
		printf("%2.2f+%2.2fj\n",X.re, X.im);
	}
	//Forma alterna: printf("%2.2f+%2.2fj\n",X.re, X.im)	
}

COMPLEJO Suma_Complejos(COMPLEJO A, COMPLEJO B)
{
	COMPLEJO suma;

	suma.re=A.re+B.re;
    suma.im=A.im+B.im;
	return(suma);
}

COMPLEJO Multiplica_Complejos(COMPLEJO A, COMPLEJO B)
{
    COMPLEJO mul;
    
    mul.re=A.re*B.re;
    mul.im=A.im*B.im;
    return(mul);
    
}
