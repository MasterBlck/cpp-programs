#include <stdio.h>
#define N 100

void leer_matriz(int *dni, int *dnj, float z[][N]);
void escribir_matriz(int ni, int nj, float z[][N]);
void sumar_matrices(int ni, int nj, float z1[][N], float z2[][N], float zs[][N]);
int se_pueden_sumar(float m1[][N], float m2[][N]);

int main(){
	int i, j;
	float matriz1[N][N], matriz2[N][N], matrizS[N][N];
	
	leer_matriz(&i, &j, matriz1);
	leer_matriz(&i, &j, matriz2);

	sumar_matrices(j, j, matriz1, matriz2, matrizS);
	escribir_matriz(i, j, matriz1);
	escribir_matriz(i, j, matriz2);
	escribir_matriz(i, j, matrizS);

	printf("i = %d, j = %d\n", i, j);
	return 0;
}


void leer_matriz(int *dni, int *dnj, float z[][N]){
	int i, j;
	printf("Dame la dimension maxima en i para la matriz: ");
	scanf("%d", dni);

	
	printf("Dame la dimension maxima en j para la matriz: ");	
	scanf("%d", dnj);

	for(i=0; i < *dni; i++){
		for(j=0; j < *dnj; j++){
			printf("Dame el valor de la matriz[%d][%d]: ", i, j);
			scanf("%f", &z[i][j]);
		}
	}
}


void escribir_matriz(int ni, int nj, float z[][N]){
	int i=0,j=0;
	printf("Los valores de la matriz son:\n");
	while(i < ni){
		j=0;
		while(j < nj){
			printf("%f\t", z[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void sumar_matrices(int ni, int nj, float z1[][N], float z2[][N], float zs[][N]){
	int i=0, j=0;

	while( i < ni ){
		j=0;
		while( j < nj ){
			zs[i][j] = z1[i][j] + z2[i][j];
			j++;
		}
		i++;
	}
}

int se_pueden_sumar(float m1[][N], float m2[][N]){
	
}
