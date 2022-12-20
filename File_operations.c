/*
--->Manejo de archivos
fopen: abrir el archivo desde el HD.
fclose: cerrar archivo.
feof: indic si llegamos al final del archivo.
rewird: regresa el apuntador al inicio del archivo.

--->Lectura de archivos
fgetc: lee un caracter del archivo.
fgets: lees una linea de caracteres del archivo.
fread: lee datos binarios desde el archivo.
fscanf: lee datos con formato especifico en el archivo.

--->Escritura del archivo
fputs: escribe un caracter en el archivo.
fputs: escribe una cadena de caracteres en el archivo.
fwrite: escribe datos binarios en el archivo.
fprintf: escribe datos con formato especifico en el archivo.
*/

#include<stdio.h>

//Permite abrir un archivo.
FILE* fopen(const char *Nombre_del_archivo, const char *Tipo_de_lectura);

/*
	"r" abrir archivo en modo lectura. 
	-->(Regresa null si no existe el archivo.)
	"w" abrir arhivo en modo escritura. 
	-->(Si no existe crea el archivo.)
	-->(Si existe el archivo lo sobre escribe.)
	"a" abrir archivo en modo escritura añadienendo la información al final del archivo.
	-->Si no existe el archivo crea uno nuevo.
	"r+" abrir archivo para lectura y escritura.
	-->(Regresa null si no existe el archivo.)
	"w+" crea un archivo para lectura y escritura.
	-->(Si no existe crea el archivo.)
	-->(Si existe el archivo lo sobre escribe.)
	"rb" abre archivo en modo binario para lectura y escritura.
	-->(Regresa null si no existe el archivo.)
	"rb+" abre archivo en modo binario para lectura.
	-->(Regresa null si no existe el archivo.)

//Pseudonimo de byte (Char sin signo)
size_t fwrite(void *apuntador, //Apunta a los datos a almacenar.
size_t dimension, //Tamaño del registro.
size_t cantidad, //Cantidad de registros.
FILE* Archivo); //Apuntador al archivo de escritura.
int fclose(FILE *Nombre_del_apuntador_al_archivo);
*/

int main()
{
	//Para abrir un archivo
	FILE* ptrArchvio1;
	char Arreglo[200];
	int contador;
	char caracter;

	//caracter='w';
	ptrArchvio1=fopen("test.txt", "r");
	if(ptrArchvio1!=NULL)
	{
		/*
		caracter=fgetc(ptrArchvio1);
		printf("El primer caracter es: %c\n",caracter);
		caracter=fgetc(ptrArchvio1);
		printf("El primer caracter es: %c\n",caracter);
		*/

		/*
		fgets(Arreglo, 200, ptrArchvio1);
		printf("El primer texto es: %s\n",Arreglo );
		fgets(Arreglo, 200, ptrArchvio1);
		printf("El segundo texto es: %s\n",Arreglo );
		*/

		while(!feof(ptrArchvio1)) //mientras no sea el final del archivo lo continua leyendo.
		{
			fscanf(ptrArchvio1, "%s", Arreglo);
			printf("El texto es: %s\n",Arreglo );
		}
		fclose(ptrArchvio1);
	}
	else
	{
		printf("El archivo no existe.\n");
	}
	/*
	fputc(10, ptrArchvio1);
	fputs(Arreglo, ptrArchvio1);
	for(contador=0; contador<10; contador++)
	{
		fprintf(ptrArchvio1, "Esta es la linea %i.\n",contador);
	}
	*/

	return 0;
}
