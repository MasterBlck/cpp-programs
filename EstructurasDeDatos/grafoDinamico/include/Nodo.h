/*Nodo de un grafo
  con un solo dato*/
#include <string>
#ifndef NODO_H
#define NODO_H
using std::string;

class Nodo{
	public:
		Nodo(string nom, int peso);
		Nodo(string nom);
		~Nodo();
		Nodo *ligaAdelante, *ligaAbajo;
		int pesoArista;
        string vertice;
};

#endif
