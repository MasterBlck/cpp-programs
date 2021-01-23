#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nom[20];
	char tel[12];
	int n;
}T_PERSONA;

int tamanioArchivo(FILE *arch);
void leerArchivo(FILE *arch, T_PERSONA *p);
int contarPersonas(T_PERSONA *p);

void barcelona(FILE *arch, T_PERSONA *p);

int main(){
	T_PERSONA *personas;
	FILE *fp = fopen("lista.txt", "r");

	if(fp == NULL){
		printf("Error de apertura de archivo\n");
		exit(1);
	}

	personas = (T_PERSONA*) malloc(sizeof(T_PERSONA));  /*Se crea el vector de personas en funcion al tamanio del archivo*/
	leerArchivo(fp, personas);

	printf("Hay %d personas\n", contarPersonas(personas));
	barcelona(fp, personas);	
	free(personas);
	fclose(fp);
	return 0;
}	

int tamanioArchivo(FILE *arch){
	fseek(arch, 0L, SEEK_END);
	return ftell(arch);
}

void leerArchivo(FILE *arch, T_PERSONA *p){
	printf("%-10s%-10s", "Telefono", "Nombre");
	//fscanf(arch, "%s %s", p->tel, p->nom);
	p->n = 0;								
	while(!feof(arch)){
		printf("%-10s%-10s\n",p-> tel,p->nom);
		fscanf(arch, "%s %s", p->tel, p->nom);
		p->n++;
	}
}

int contarPersonas(T_PERSONA *p){
	return p->n-1;
}

void barcelona(FILE *arch, T_PERSONA *p){
	FILE *nuevo = fopen("barcelona.txt", "w");
	fseek(arch, 0L, SEEK_SET); /*Situar el offset al principio del archivo*/
	while(!feof(arch)){
		fscanf(arch, "%s %s", p->tel, p->nom);
		if(p->tel[0] == '9' && p->tel[1] == '3'){
			fprintf(nuevo, "%-10s%-10s\n", p->tel, p->nom);	
			printf("%-10s%-10s\n", p->tel, p->nom);	
		}
	}

	fclose(nuevo);
}
