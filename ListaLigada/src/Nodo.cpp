#include <iostream>
#include "../include/Nodo.h"

using namespace std;

Nodo::Nodo(int dato){
    data = dato;
    liga = NULL;
}

void Nodo::establecerDato(int elemento){
    data = elemento;
}

void Nodo::imprimir(){
    cout << data << endl;
}

int Nodo::obtenerDato(){
    return data;
}

Nodo::~Nodo(){}