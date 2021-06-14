/*
 * Licencia de hacker
 */

#include "../include/nodo.h"

Nodo::Nodo(int dato)
{
	this->dato = dato;
	this->ligaAdelante = null; 
	this->ligaAtras = null;  
}


Nodo::~Nodo()
{

}
