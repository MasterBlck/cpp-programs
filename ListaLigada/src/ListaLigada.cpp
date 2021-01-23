#include <iostream>
#include "../include/Nodo.h"
#include "../include/ListaLigada.h"

using namespace std;

ListaLigada::ListaLigada(){
    iniLista = NULL;
    finLista = NULL;
}

void ListaLigada::agregarAlInicio( int data ){
    Nodo *nuevo = new Nodo( data );

    nuevo->liga = iniLista;
    iniLista = nuevo;
    ListaLigada::nElementos++;
}

void ListaLigada::agregarAlFinal( int data ){
    Nodo *nuevo = new Nodo( data );

    if (estaVacia()) {
        iniLista = finLista = nuevo;
    } else {
        finLista->liga = nuevo;
        finLista = finLista->liga;
    }

    ListaLigada::nElementos++;
}

int ListaLigada::eliminarAlInicio(){
    Nodo *viejo;
    int datoViejo;

    if (estaVacia()) {
        //validar error en caso de tratar de eliminar un nodo en una lista vacía
        cerr << "Error al intentar eliminar en lista vacía\n";
        return -1;
    } else {
        datoViejo = iniLista->obtenerDato();
        viejo = iniLista;
        iniLista = iniLista->liga;

        delete viejo;
    }

    ListaLigada::nElementos--;

    return datoViejo;
}

int ListaLigada::eliminarAlFinal(){
    Nodo *viejo;
    int datoViejo;

    if (estaVacia()) {
        //validar error en caso de tratar de eliminar un nodo en una lista vacía
        cerr << "Error al intentar eliminar en lista vacía\n";
        return 0;
    } else {
        datoViejo = finLista->obtenerDato();
        viejo = finLista;
        finLista = iniLista;
        //error
        while (finLista->liga != viejo && finLista->liga != NULL) {
            finLista = finLista->liga;
        }

        finLista->liga = NULL;

        delete viejo;
    }

    ListaLigada::nElementos--;

    return datoViejo;
}

//void ListaLigada::agregarEn(int index, int data){}

//int ListaLigada::eliminarEn(int index){}

bool ListaLigada::estaVacia(){
    return iniLista == NULL && finLista == NULL;
}

void ListaLigada::imprimir(){
    Nodo *ite = iniLista;

    while (ite != NULL) {
        cout << ite->obtenerDato() << "->" ;
        ite = ite->liga;
    }
}

int ListaLigada::obtenerValorInicial(){
    if(iniLista == NULL && finLista == NULL){
        cerr << "Error al obtener valor inicial, lista vacia\n";
        return 0;
    } else {
        return iniLista->obtenerDato();
    }
}

int ListaLigada::obtenerValorFinal(){
    if(iniLista == NULL && finLista == NULL){
        cerr << "Error al obtener valor final, lista vacia\n";
        return 0;
    } else {
        return finLista->obtenerDato();
    }
}

ListaLigada::~ListaLigada(){}