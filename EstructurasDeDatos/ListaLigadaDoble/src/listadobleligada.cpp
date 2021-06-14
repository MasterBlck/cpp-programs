/*
 * Licencia de hacker
 */
#include <iostream>
#include "../include/listadobleligada.h"
#include "../include/nodo.h"

using std::cout;
using std::endl;

ListaDobleLigada::ListaDobleLigada()
{
	iniLista = null;
}

void ListaDobleLigada::insertarAlInicio(int dato)
{
	Nodo *nuevo = new Nodo(dato);
	
	nuevo->ligaAdelante = iniLista;
	
	if(iniLista != null)
		iniLista->ligaAtras = nuevo;
	
	iniLista = nuevo;
	numElementos++;
}

void ListaDobleLigada::insertarAlFinal(int dato)
{
	Nodo *nuevo = new Nodo(dato);
	
	if(iniLista == null)
		iniLista = nuevo;
	else{
		Nodo *aux = iniLista;
		
		while(aux->ligaAdelante != null)
			aux = aux->ligaAdelante;
		
		nuevo->ligaAtras = aux;
		aux->ligaAdelante = nuevo;
	}
	
	numElementos++;
}

void ListaDobleLigada::insertarEnPosicion(int i, int dato)
{
	Nodo *nuevo = new Nodo(dato);
}



void ListaDobleLigada::imprimir()
{
	Nodo *ptr = iniLista;
	
	while(ptr != null)
	{
		cout << ptr->dato << "->" ;
		ptr = ptr->ligaAdelante;
	}
	
	cout << endl;
}

ListaDobleLigada::~ListaDobleLigada()
{
}