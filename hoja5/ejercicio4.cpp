#include <stdio.h>
#include <math.h>
#define MAX_POINTS 100

void leerPuntos(int *x, int *y);
void calcularLados(int xs[], int ys[], int ls[], int *n);
int calcularPerimetro(int ls[], int *n);

int main(){
	int coorX[MAX_POINTS], coorY[MAX_POINTS], longitudes[MAX_POINTS];
	int npoints, i;

	printf("Cuantos puntos tiene el poligono? ");
	scanf("%d", &npoints);

	for(i=0; i < npoints; i++){
		printf("Dame la coordenada del punto #%d :\n", i+1);
		leerPuntos(&coorX[i], &coorY[i]);
	}
	
	calcularLados(coorX, coorY, longitudes, &npoints);

	printf("\nEl perimetro del poligono es %d\n", calcularPerimetro(longitudes, &npoints));
	return 0;
}


void leerPuntos(int *x, int *y){
	printf("\tx = ");
	scanf("%d", x);

	printf("\ty = ");
	scanf("%d", y);
}


void calcularLados(int xs[], int ys[], int ls[], int *n){
	int i;
	for(i=0; i < *n; i++){
		
		if(i == *n-1){
			ls[i] = (int) sqrt(pow(xs[0]- xs[i],2) + pow(ys[0] - ys[i],2));
		}else{
			ls[i] = (int) sqrt(pow(xs[i+1]- xs[i],2) + pow(ys[i+1] - ys[i],2));
		}
		
		printf("Lado[%d] = %d\n", i, ls[i]);	
	}
}

int calcularPerimetro(int ls[], int *n){
	int i=0, perimetro=0;
	while(i < *n){
		perimetro = perimetro + ls[i];
		i++;
	}

	return perimetro;
}
