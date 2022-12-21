#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<stdio.h>
#include<string.h>

int main()
{
    int i, j;
    float Comparador; //sirve como medio de almacenamiento para la comparacion entre palabras (dado que cada letra recibe un valor númerico dependiendo su posición en el abecedario, esto para saber que eltra va despues de otra)
    char Auxiliar[20]; //proporcionara una variable en donde se depositan los nombre para después compararlos.
    int i, counter=0; //el contador permite que actue la condicion hasta el valor máximo de nombres, de tal modo de que si se reccorre el arreglo y no esta el nombre se imprime el mensaje "no esta".
    char names[15]; //permite ingresar el nombre para saber si esta o no en el aareglo.
    char Nombres[20][15]={"Luis", "Juan", "Alex", "Jose", "Samuel", "Ramon", "Santiago", "Salvador", "Marco", "Carlos", "Miguel", "Ana", "Maria", "Paola", "Paulina", "Sara", "Martha", "Javier", "Jhon", "Leonardo"};
    
    printf("Los nombres del arreglo son: \n");

    for(i=0; i<20; i++)
    {                                               //amperson permite que el printf muestre el                                                 nombre completo de la cadena en el arreglo                                                  de caracteres.
        printf("%s\n", &Nombres[i][0]);
    }
    
    for(i=0; i<20; i++)//Ciclo que realiza el proceso de ordenamiento, explora las letras de cada palabra dentro del arreglo.
    {
        for(j=0; j<20; j++) 
        {
            //el comando "strmcp" busca realizar la comparación de las palabras dentro del arreglo.
            Comparador = strcmp(Nombres[j], Nombres[j+1]);
            if(Comparador>0)
            {
                //el comando "strcpy" copia el contenido de la cadena que se seleccione y la deposita en una variable destino, la función de la coma dentro del comando tiene una similitud al simbolo de igual.
                strcpy(Auxiliar,Nombres[j]);
                strcpy(Nombres[j],Nombres[j+1]);
                strcpy(Nombres[j+1],Auxiliar);
            }
        }
    }
    printf("\n");

    printf("Los nombres ordenados del arrelgo son: \n");
    for(i=0; i<20; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
    {
        printf("%d.- %s\n",i+1, Nombres[i]); //se usa porciento d y s debido a la combinación de condiciones entre el ciclo for aniado y el uso de un contador flotante.
    }


    return 0;
}