/*
 * Archivo: Nodo.h
 * 
 * */

#ifndef NODO_h
#define NODO_H

//definición de la clase Nodo que es genérica
template <class T> class Nodo
{
	public:
		T dato;
		Nodo<t> *liga;
		
		Nodo(T t); //constructor
		
};

#endif
