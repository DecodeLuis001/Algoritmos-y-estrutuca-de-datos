#include<stdio.h>

typedef struct
{
	float C1, C2, C3;
}
Calificaciones;

int main()
{
	FILE* ptrArchivo1;
	int k;
	Calificaciones Alumnos[3];

	ptrArchivo1=fopen("Calificaciones.bin", "rb");
	if(ptrArchivo1==NULL)
	{
		printf("No se pudo crear el archivo.\n");
	}

	fread(Alumnos, sizeof(Calificaciones), 3, ptrArchivo1);

	fclose(ptrArchivo1);

	for(k=0; k<3; k++)
	{
		printf("Alumno[%i]: %f %f %f\n",k+1, Alumnos[k].C1, Alumnos[k].C2, Alumnos[k].C3);
	}
	printf("\n");
	return 0;
}