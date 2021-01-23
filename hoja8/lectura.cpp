#include <stdio.h>
#include <stdlib.h>

int main(){
	char num[12], nom[20];

	FILE *fp = fopen("lista.txt", "r");
	if (fp == NULL){
		printf("No se puede abrir archivo\n");
		exit(1);
	}
	
	printf("%-10s%-10s\n", "Telefono", "Nombre");
	fscanf(fp, "%s %s", num, nom);

	while(!feof(fp)){
		printf("%-10s%-10s\n", num, nom);
		fscanf(fp, "%s %s", num, nom);
	}

	fclose(fp);
	return 0;
}
