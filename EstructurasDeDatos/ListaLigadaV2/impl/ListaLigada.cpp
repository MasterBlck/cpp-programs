#include <iostream>
#include "../headers/ListaLigada.h"
#include "../headers/Nodo.h"

using std::cout;
using std::endl;

ListaLigada::ListaLigada(){
	iniLista = NULL;
	numElementos = 0;
}

void ListaLigada::insertarAlInicio(int dat){
	Nodo *nuevo = new Nodo(dat);

	nuevo->liga = iniLista;
	iniLista = nuevo;
	numElementos++;
}

void ListaLigada::insertarAlFinal(int dat){
	Nodo *nuevo = new Nodo(dat);

	if(iniLista == NULL){  //si la lista está vacia, apuntador de inicio apunta al nuevo nodo
		iniLista = nuevo;
	}
	else{
		Nodo *aux = iniLista;
		while(aux->liga != NULL){
			aux = aux->liga;
		}
		aux->liga = nuevo;
	}
	numElementos++;
}

void ListaLigada::insertarEnPosicion(int i, int dat){
	Nodo *nuevo = new Nodo(dat);

	if(i >= numElementos || i < 0){ // devuelve error si i esta fuera del rango de elementos
		std::cerr << "El valor "<< i << " está fuera de rango" << '\n';
		return ;
	}


	if(i == 0){
		nuevo->liga = iniLista;
		iniLista = nuevo;
	}
	else{
		Nodo *aux = iniLista;
		for(int it = 0; it < i-1; it++){
			aux = aux->liga;
		}

		nuevo->liga = aux->liga;
		aux->liga = nuevo;
	}

	numElementos++;
}

int ListaLigada::borrarAlInicio(){
	int eliminado = -1;  //si la lista esta vacía devuelve marca de error

	if(iniLista != NULL){ //si la lista tiene elementos, se puede eliminar nodos al inicio
		Nodo *viejo = iniLista;
		iniLista = iniLista->liga;
		eliminado = viejo->dato;

		//liberando memoria
		//viejo->liga = NULL; // o 0 que es lo mismo que NULL
		delete viejo;

		numElementos--;
	}
	return eliminado;
}

int ListaLigada::borrarEnPosicion(int i){
	int eliminado = -1;

	if(iniLista != NULL && i < numElementos){
		Nodo *viejo = iniLista;
		if(i == 0){ // borrar el elemento 0 de la lista
			iniLista = iniLista->liga;
		}else{   //aquí al menos existen 2 elementos en la lista
			Nodo *anterior = iniLista;

			viejo = viejo->liga;
	        for(int it = 0; it < i-1; it++){
				anterior = anterior->liga;
	            viejo = viejo->liga;			//el nodo viejo estará en la posición i para ser eliminado
	        }

			anterior->liga = viejo->liga;
			eliminado = viejo->dato;

			//liberando memoria
			//viejo->liga = NULL;
		}
		//liberando memoria
		delete viejo;
		numElementos--;
	}
	return eliminado;
}

int ListaLigada::borrarAlFinal(){
	int eliminado = -1;

	if(iniLista != NULL){
		Nodo *viejo = iniLista;
		Nodo *anterior = iniLista;

		viejo = viejo->liga;
		while((viejo != NULL) && (viejo->liga != NULL)){ //verificar en caso de error
			viejo = viejo->liga;
			anterior = anterior->liga;
		}

		eliminado = viejo->dato;
		anterior->liga = NULL;

		//liberando memoria
		delete viejo;

		numElementos--;
	}
	return eliminado;
}

//**************************PRECAUCION: POSIBLE FUGA DE MEMORIA******************************
int ListaLigada::borrarAlFinal2(){ //version donde se usa 1 solo apuntador
	int eliminado = -1;

        if(iniLista != NULL){
                Nodo *viejo = iniLista;

                while(viejo->liga != NULL)
                {
                        viejo = viejo->liga;
                }

				eliminado = viejo->dato;

                //liberando memoria o eliminando "viejo"
				delete viejo;
				viejo = 0; //o NULL

				numElementos--;
        }
        return eliminado;

}

int ListaLigada::obtenerNumElementos(){
	return numElementos;
}

Nodo* ListaLigada::obtenerInicio(){
		return iniLista;
}

void ListaLigada::imprimir(){
	Nodo *aux = iniLista;

	while(aux != NULL){
		cout << aux->dato << "->";
		aux = aux->liga;
	}
}
//Operaciones con sublistas
//********************************************************************************************
void ListaLigada::insertarSublistaAlInicio(ListaLigada l){
	Nodo *aux = l.obtenerInicio();

	if (aux == NULL) {
		std::cout << "ListaLigada sin elementos" << '\n';
		return;
	}

	//recorre aux en la lista l, no de ésta lista
	while(aux->liga != NULL){
		aux = aux->liga;
	}
	aux->liga = iniLista;
	iniLista = l.obtenerInicio();
	//iniLista = l.iniLista;
	numElementos += l.obtenerNumElementos();
}

void ListaLigada::insertarSublistaAlFinal(ListaLigada l){

	if(l.obtenerInicio() == NULL){
		std::cout << "ListaLigada sin elementos" << '\n';
	}else if( iniLista == NULL ){
		insertarSublistaAlInicio(l);
	}else{
		Nodo *aux = iniLista;
		while(aux->liga != NULL){
			aux = aux->liga;
		}

		aux->liga = l.obtenerInicio();
		numElementos += l.obtenerNumElementos();
	}
}

void ListaLigada::insertarSublistaEni(int i, ListaLigada l) {
	if(i >= numElementos || i < 0){
		std::cerr << "El valor "<< i << " está fuera de rango" << '\n';
		return ;
	}

	if( l.obtenerInicio() == NULL ){			//validar caso en que la sublista esté vacia
		std::cout << "ListaLigada sin elementos" << '\n';
		return ;
	}

	Nodo *ptrSublista = l.obtenerInicio();


	if( i == 0 ){
		ptrSublista = iniLista;
		iniLista = l.obtenerInicio();
	}else{
		Nodo *aux = iniLista;

		while(ptrSublista->liga != NULL)
		 	ptrSublista = ptrSublista->liga;

		for(int it = 0; it < (i-1); it++){
			aux = aux->liga;
		}

		ptrSublista->liga = aux->liga;
		aux->liga = l.obtenerInicio();
		numElementos += l.obtenerNumElementos();
	}
}

//Asumimos que la lista tiene por lo menos 2 elementos y que i y j son rangos válidos
ListaLigada ListaLigada::obtenerSublista(int i, int j){  //j debe ser > i
	ListaLigada listanueva;
	if ((i >= numElementos || i < 0) && (j >= numElementos || j < 0 || j <= i)) {  //verificar validación
		std::cerr << "Par de valores "<< i <<" y "<< j << " están fuera de rango" << '\n';
		return listanueva;
	}

	Nodo *ptrI = iniLista, *ptrJ;
	int it;
	//Ubicar el ptrI en la posicion i de la lista ligada
	for (it = 0; it < i ; it++) {
		ptrI =  ptrI->liga;
	}
	ptrJ = ptrI;
	for(int k = it-1; k < j; k++){
		listanueva.insertarAlFinal(ptrJ->dato);
		ptrJ = ptrJ->liga;
	}

	return listanueva;
}

void ListaLigada::borrarRango(int i, int j){
	if ((i >= numElementos || i < 0) && (j >= numElementos || j < 0 || j <= i)) {  //verificar validación
		std::cerr << "Par de valores "<< i <<" y "<< j << " están fuera de rango" << '\n';
		return ;
	}

	Nodo *ptrI = iniLista, *viejos;
	int it;
	//Ubicar el ptrI en la posicion i-1 de la lista ligada
	for (it = 0; it < (i-1) ; it++) {
		ptrI =  ptrI->liga;
	}
	viejos = ptrI->liga;
	for (int k = it; k < j; k++) {
		ptrI->liga = viejos->liga;
		delete viejos;
		viejos = ptrI->liga;
		numElementos--;
	}
}
//Impresiones
//********************************************************************************************
int ListaLigada::obtenerValorInicial(){
	if (iniLista == NULL) {
		return -1;
	}else{
		return iniLista->dato;
	}
}

int ListaLigada::obtenerValorFinal() {
	if (iniLista == NULL) {
		return -1;
	}else{
		Nodo *aux = iniLista;
		while (aux->liga != NULL) {
			aux = aux->liga;
		}
		return aux->dato;
	}
}

int ListaLigada::obtenerValorEn(int i){
	if (i < 0 || i >= numElementos) {
		return -1;
	}

	if (i == 0) {
		return iniLista->dato;
	}

	Nodo *aux = iniLista;
	for (int c = 0; c < i ; c++) {
		aux = aux->liga;
	}

	return aux->dato;
}
//Operaciones Matematicas
//********************************************************************************************
int ListaLigada::obtenerMaximo(){
	if (iniLista == NULL) {
		return -1;
	}else{
		Nodo *aux = iniLista;
		int max = aux->dato;
		while (aux != NULL) {
			if (aux->dato > max)
				max = aux->dato;

			aux = aux->liga;
		}
		return max;
	}
}

int ListaLigada::obtenerMinimo(){
	if (iniLista == NULL) {
		return -1;
	}else{
		Nodo *aux = iniLista;
		int min = aux->dato;
		while (aux != NULL) {
			if (aux->dato < min)
				min = aux->dato;

			aux = aux->liga;
		}
		return min;
	}
}

float ListaLigada::obtenerPromedio(){
	if (iniLista == NULL) {
		return -1;
	}else{
		Nodo *aux = iniLista;
		float sum = 0, prom = 0;
		while (aux != NULL) {
			sum += aux->dato;
			aux = aux->liga;
		}

		prom = (float)(sum/numElementos);
		return prom;
	}
}

int ListaLigada::obtenerSumatoria(){
	if (iniLista == NULL) {
		return -1;
	}else{
		Nodo *aux = iniLista;
		int sum = 0;
		while (aux != NULL) {
			sum += aux->dato;
			aux = aux->liga;
		}
		return sum;
	}
}

int ListaLigada::obtenerMultiplicatoria(){
	if (iniLista == NULL) {
		return -1;
	}else{
		Nodo *aux = iniLista;
		int mul = 1;
		while (aux != NULL) {
			mul *= aux->dato;
			aux = aux->liga;
		}
		return mul;
	}
}
ListaLigada::~ListaLigada(){/*destructor de lista ligada*/}
