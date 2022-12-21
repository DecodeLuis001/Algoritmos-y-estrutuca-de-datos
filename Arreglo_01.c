#include<stdio.h>
#include<string.h> //verifica las cadenas que se involucran.

int main()
{
	char caracteres[256];
	unsigned char flag=0, PrimeraVez=1;
	int contador_caracteres=0;
	int index, counter=0, letras=0, cantidad, space=0;
    
	printf("Escriba un mensaje: \n");
	printf("El limite de caracteres a ingresar es de 256\n");
    printf("AL TERMINAR DE ESCRIBIR PRESIONE LA TECLA ESPACIO\n");
	gets(caracteres);
	{   //Total de palabras de la cadena.
		for (index=0; index<=strlen(caracteres); index++) //strlen calcula el numero de caracteres de la cadena
		{
			if(caracteres[index]== ' ')//permite escribir el mensaje en seguida sin necesidad de tener que presionar espacio.
			{
				if(letras==0) //se inicializa en C para que cuente la primer palbara que no lleve espacio.
				{
                    if(caracteres[index+1]!=' ') //asegura que se este tomando en cuenta una letra en vez de otro espacio.
					counter++;
				}
			}
		}
		if(caracteres[index+1]!=' ') //asegura que se este tomando en cuenta una letra en vez de otro espacio.
        {
            counter++;
        }
        
	}
    
	printf("las palabras del mensaje son: \n");
	index=0;
    while(caracteres[index]!='\0')
    {
        while(caracteres[index]==' ') //Busca espacios repetidos.
        {
            {
                index++; //Brinca espacios hasta encontrar un caracter.
                space++;
                flag=1;
            }
            if(flag)
            {
                if(!PrimeraVez)
                    printf("\t Numero de caracteres: %i\n", contador_caracteres);
                contador_caracteres=0;
                flag=0;
            }
        }
        printf("%c\n",caracteres[index]);
        index++;
        contador_caracteres++;
        PrimeraVez=0;
    }
    cantidad =(strlen(caracteres)-space);

	printf("Su mensaje contiene, el número de caracteres: %d\n", cantidad);
	printf("El total de palabras es: %i\n", counter-1);
	printf("El texto capturado es: %s\n", caracteres);
    
	letras=0; //Necesario para que reconozca el mensaje tal cual se introduce, de otro modo se omite la primer letra de la primer palabra.
	while(caracteres[letras]!='\0')
	{
		printf("%c", caracteres[letras]);
		letras++;
        return 0;
	}
}
