#include <stdio.h>

typedef struct{
	char nombre[50];
	float notas[5];
}T_Alumno;	/*Guarda los datos de un Alumno*/

typedef struct{
	T_Alumno alumnos[100];
	int n_alumnos;
}T_Alumnos; /*Guarda los datos de todos los alumnos de una clase*/


void insertar_alumno(T_Alumno alumno, FILE *archivo);

int main(){
	T_Alumno alum;
	FILE *f;
	
	f = fopen("alumnos.bin", "wab");
	if(f == NULL){
		printf("Error de apertura de archivo");
		return 1;
	}

	printf("Dame el nombre de un alumno: ");
	scanf("%s", alum.nombre);
	getchar();

	printf("Inserte 5 calificaciones de %s\n", alum.nombre);
	for(int i=0; i < 5; i++){
		printf("Nota #%d: ", i);
		scanf("%f", &alum.notas[i]);
	}

	insertar_alumno(alum, f);

	return 0;
}

void insertar_alumno(T_Alumno alumno, FILE *f){
	fwrite(&alumno, sizeof(T_Alumno), 1, f);

}

