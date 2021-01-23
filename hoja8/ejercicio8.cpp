#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nom[20];
	char apell[20];
	char num_tel[12];
	float notas[3], prom;
}T_Alumno;

void leer_info_alumnos(T_Alumno *a, int n, char *file);
void imprimirAlumnos(T_Alumno *a, int n);
T_Alumno obtenerMejor(T_Alumno *alums, int n);
void obtenerLista(T_Alumno *alums, int n);

int main(){
	T_Alumno *alumnos, mejorAlum;
	char nomArchivo[50];
	int nalumnos;
	
	printf("Cuantos alumnos hay en el curso? ");
	scanf("%d", &nalumnos);
	getchar();

	alumnos = (T_Alumno*) malloc(sizeof(T_Alumno)*nalumnos);
	printf("Introduzca el nombre del archivo: ");
	scanf("%s", nomArchivo);
	getchar();
	
	printf("Leyendo desde el archivo %s...\n", nomArchivo);
	leer_info_alumnos(alumnos, nalumnos, nomArchivo);
	printf("Alumnos leidos:\n");
	imprimirAlumnos(alumnos, nalumnos);

	mejorAlum = obtenerMejor(alumnos, nalumnos);
	printf("El mejor alumno es %s %s, con un promedio de %.2f\n", mejorAlum.nom, mejorAlum.apell, mejorAlum.prom);

	obtenerLista(alumnos, nalumnos);
	free(alumnos);
	return 0;
}


void leer_info_alumnos(T_Alumno *a, int n, char *file){
	int i=0, j;
	float sum=0, prom=0;
	FILE *archivo = fopen(file, "rw");

	if (archivo == NULL){
		printf("El archivo no existe");
		exit(1);
	}

	while(i < n){
		fscanf(archivo, "%s%s%s", (a+i)->nom, (a+i)->apell, (a+i)->num_tel);
		j=0;
		while(j < 3){
			fscanf(archivo,"%f", &(a+i)->notas[j]);
			sum =(float) (sum + (a+i)->notas[j]);
			j++;
		}

		(a+i)->prom =(float) (sum / 3);
		sum = 0;
		i++;
	}

	fclose(archivo);
}

void imprimirAlumnos(T_Alumno *a, int n){
	int i, j;

	i=0;
	do{
		printf("%-10s%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f\n", (a+i)->nom, (a+i)->apell,(a+i)->num_tel, (a+i)->notas[0],(a+i)->notas[1], (a+i)->notas[2], (a+i)->prom);
	}while(++i < n);
			//sum = sum + (a+i)->notas[j];
}

T_Alumno obtenerMejor(T_Alumno *alums, int n){
	T_Alumno mejor;
	int i=0;
	mejor.prom = (alums+i)->prom;
	do{
		if((alums+i)->prom > mejor.prom){
			mejor.prom = (alums+i)->prom;

			/*No Solamente copiar el promedio*/
			strcpy(mejor.nom, (alums+i)->nom);	
			strcpy(mejor.apell, (alums+i)->apell);	
			strcpy(mejor.num_tel, (alums+i)->num_tel);	
		}
	}while(++i < n);

	return mejor;	
}

void obtenerLista(T_Alumno *alums, int n){
	int i, nbuenos;
	float notaSuperar;
	char opc;

	do{
		printf("Introduzca si quiere:\n\t1. Algebra\n\t2. Calculo\n\t3. Programacion\n");
		scanf("%c", &opc);
		getchar();

		printf("Nota a superar: ");
		scanf("%f", &notaSuperar);
		i=0;
		nbuenos=0;
		switch(opc){
			case '1': /*nota de algebra*/
			    	  printf("Algebra\n");
				  while(i < n){
				  	if(notaSuperar <= (alums+i)->notas[0]){
				  		//printf("%.2f\t%.2f\t%d\t%d\n", notaSuperar, (alums+i)->notas[1], i, n);
						printf("%s %s\n", (alums+i)->nom, (alums+i)->apell);
						nbuenos++;
					}
					i++;
				  }
				  printf("Alumnos buenos: %d\n",nbuenos);
				break;

			case '2':/*Nota de cslculo*/
			    	  printf("Calculo\n");
				  while(i < n){
				  	if(notaSuperar <= (alums+i)->notas[1]){
						printf("%s %s\n", (alums+i)->nom, (alums+i)->apell);
						nbuenos++;
					}
					i++;
				  }
				  printf("Alumnos buenos: %d\n",nbuenos);
				break;
			
			case '3':/*Nota de Programacion*/
			    	  printf("Programacion\n");
				  while(i < n){
				  	if(notaSuperar <= (alums+i)->notas[2]){
						printf("%s %s\n", (alums+i)->nom, (alums+i)->apell);
						nbuenos++;
					}
					i++;
				  }
				  printf("Alumnos buenos: %d\n",nbuenos);
				break;

			default:
				printf("Opcion no valida\n");
				break;
		}
	}while(opc > '3' && opc < '1');
}
