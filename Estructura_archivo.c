#include<stdio.h>

typedef struct
{
	float C1, C2, C3;
}
Calificaciones;

int main()
{
	FILE* ptrArchivo1;
	Calificaciones AlumnoA, AlumnoB, AlumnoC;

	AlumnoA.C1=9.0;
	AlumnoA.C2=8.5;
	AlumnoA.C3=9.5;
	AlumnoB.C1=9.0;
	AlumnoB.C2=7.5;
	AlumnoB.C3=9.5;
	AlumnoC.C1=8.0;
	AlumnoC.C2=8.0;
	AlumnoC.C3=8.0;

	ptrArchivo1=fopen("Calificaciones.bin", "w+rb+");
	if(ptrArchivo1==NULL)
	{
		printf("No se pudo crear el arhcivo.\n");
	}
	fwrite(&AlumnoA, sizeof(Calificaciones), 1, ptrArchivo1);
	fwrite(&AlumnoB, sizeof(Calificaciones), 1, ptrArchivo1);
	fwrite(&AlumnoC, sizeof(Calificaciones), 1, ptrArchivo1);

	fclose(ptrArchivo1);
	printf("\n");

	return 0;
}