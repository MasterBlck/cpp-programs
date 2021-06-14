#include <iostream>
#include "../headers/Nodo.h"

Nodo::Nodo(int dato){
	this->dato = dato;
	this->liga = NULL;
}

Nodo::~Nodo(){ /*destructor de nodo*/ }
