#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIAS_MES 30

typedef struct{
	char nombre_estacion[50];
	float temperaturas[30];
}T_estacion;

typedef struct{
	T_estacion lista_estac[100];
	int n_estaciones;
}T_estaciones;

void crearDatos(T_estaciones *est);
void cargarDatos(T_estaciones *est);
float calculos(T_estaciones *est);
void imprimeBuffer(T_estaciones *est);

int main(){
	T_estaciones *estaciones = (T_estaciones*) malloc(sizeof(T_estaciones));
	T_estaciones *estLeidas = (T_estaciones*) malloc(sizeof(T_estaciones));
	float promedioMaximas;
	
	if (estaciones == NULL){
		printf("No se reservo espacio de memoria");
		exit(1);
	}

	crearDatos(estaciones);
	estLeidas->n_estaciones = estaciones->n_estaciones;
	cargarDatos(estLeidas);
	imprimeBuffer(estLeidas);
	promedioMaximas = calculos(estLeidas);
	
	printf("El promedio de las temperaturas maximas es %.2f\n", promedioMaximas);

	free(estLeidas);
	free(estaciones);
	return 0;
}


void crearDatos(T_estaciones *est){
	int i, j;
	FILE *f = fopen("estaciones.dat", "wr");

	srand(time(NULL));

	if(f == NULL){
		printf("Error de apertura de archivo");
		exit(1);
	}

	printf("Cuantas estaciones va a alamcenar? ");
	scanf("%d", &est->n_estaciones);
	getchar();

	i=0;
	while(i < est->n_estaciones){
		printf("Nombre de la estacion #%d: ", i+1);
		scanf("%s", est->lista_estac[i].nombre_estacion);
		getchar();
	
		j=0;
		while(j < DIAS_MES){
			/*printf("\tTemperatura dia #%d: ", j+1);
			scanf("%f", &est->lista_estac[i].temperaturas[j]; Descomenta si quieres leer por teclado*/

			est->lista_estac[i].temperaturas[j] = (float) (rand() % 101); /*Obtengo las temperaturas de manera aleatoria, si quieres puedes comentarla*/
			j++;
		}

		/*Escribe en el archivo todas las temperaturas leidas en el programa de 1 en 1*/
		fwrite(&est->lista_estac[i], sizeof(T_estacion), 1, f);
		i++;
	}
	
	fclose(f);
	
}

void cargarDatos(T_estaciones *est){	
	int i, j, datosLeidos;
	FILE *f = fopen("estaciones.dat", "r");

	if(f == NULL){
		printf("Error de apertura de archivo, no existe");
		exit(1);
	}

	i=0;
	while(i < est->n_estaciones){
		datosLeidos = fread(&est->lista_estac[i], sizeof(T_estacion), 1, f);
		if(datosLeidos <= 0){
			printf("No se leyó ningun dato de archivo");
			exit(1);
		}
		i++;
	}

	fclose(f);
}

float calculos(T_estaciones *est){
	float tempMaximas[100], sum, prom;   /*Se almacenaran las temperaturas maximas por estacion*/
	int i,j;

	for(i=0; i < est->n_estaciones; i++){
		tempMaximas[i] = est->lista_estac[i].temperaturas[0];
		for(j=0; j < DIAS_MES; j++){
			if(tempMaximas[i] < est->lista_estac[i].temperaturas[j]){
				tempMaximas[i] = est->lista_estac[i].temperaturas[j];
			}
		}
		sum = sum + tempMaximas[i];
		printf("Temperatura maxima de la estacion #%d: %.2f\n", i+1, tempMaximas[i]);
	}
	
	/*Calculando la media de las temperaturas maximas*/
	prom = sum / est->n_estaciones;

	return prom;
}

void imprimeBuffer(T_estaciones *est){
	int i,j;

	i=0;
	do{
		printf("Nombre estacion #%d: %s\n", i+1, est->lista_estac[i].nombre_estacion);
		j=0;
		while(j < DIAS_MES){
			printf("\tTemperatura dia #%d = %.2f\n", j+1, est->lista_estac[i].temperaturas[j]);
			j++;
		}
		
	}while(++i < est->n_estaciones);
}
