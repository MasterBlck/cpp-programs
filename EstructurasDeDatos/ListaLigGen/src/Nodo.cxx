/*
 * Nodo.cxx
 * 
 *Implementación de la clase Nodo.cxx
 * 
 */


#include <iostream>
#include "../include/Nodo.h"

Nodo::Nodo(T t)
{
	dato = t;
	liga = NULL;
}
