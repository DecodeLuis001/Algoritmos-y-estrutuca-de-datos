//Capturar una cadena de caracteres y mostrar una tabla con los siguientes datos:
//"Este es el grupo de algoritmos y estructura de datos."
//El resultado es:
/*
Este 			4
es 				2
El 				2
grupo			5			
algoritmos		10
y				1
estructuras		11
de				2
datos			5
total de carcateres:	42 
total de palabras: 		9
*/

#include<stdio.h>
#include<string.h>

int main()
{	
	int indice, contador_caracteres=0, letras=0;
    int index, cantidad_espacios=0, espacios=0, contador=0, caracter=0;
	unsigned char flag=0, PrimeraVez=1;
	char caracteres[256];

	printf("El limite de caracteres a capturar es: 256\n");
	printf("Escriba el mensaje a capturar:\n");
	gets(caracteres);
	{
		indice=0;
		while(caracteres[indice]!='\0')
		{
			while(caracteres[indice]==' ') //Busca espacios repetidos.
			{
				{
					indice++; //Brinca espacios hasta encontrar un caracter.
					flag=1;
				}
				if(flag)
				{	
					if(!PrimeraVez)
					printf("\n %i\t", contador_caracteres);
					//printf("indice=%i, %c\n",indice, caracteres[indice]);
					contador_caracteres=0;
					flag=0;
				}
			}
			printf("%c\n",caracteres[indice]);
			indice++;
			contador_caracteres++;
			PrimeraVez=0;
		}
	}
	printf("%i\n", contador_caracteres);
	printf("\n");


	printf("El texto ingresado es: %s \n", caracteres);
}
