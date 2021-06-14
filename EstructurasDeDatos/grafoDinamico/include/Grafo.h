#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"
#include <string>
#include <sstream>

enum TipoGrafo{GRAFO_DIRIGIDO, GRAFO_NO_DIRIGIDO, GRAFO_MIXTO};
enum grafoMemory{GRAFO_ESTATICO, GRAFO_DINAMICO};

class Grafo{
	public:
        Grafo();
        Grafo(int numNodos);
        ~Grafo();
        //Operaciones básicas
        void insertarVertice(string nombre);
        void insertarAristaDirigida(string vorigen, string vdestino);
		void insertarAristaDirigida(string vorigen, string vdestino, int peso);
		void insertarAristaNoDirigida(string vorigen, string vdestino);
		void insertarAristaNoDirigida(string vorigen, string vdestino, int peso);
		int eliminarArista(string vi, string vj);
		void imprimir();
		//operaciones intermedias
		void imprimirVecinosDe(string v);
		void imprimirCaminos(string vorigen, string vdestino);
		void eliminarVertice(string v);
		int gradoDe(string v); //éste aplica para grafos no dirigidos
		int gradoEntranteDe(string v); //para grafos dirigidos
		int gradoSalienteDe(string v);
		int gradoTotal(string v);  //suma del grado entrante mas grado saliente


	private:
        int numVertices, numAristas;
		Nodo *iniGrafo, *finGrafo;
};

#endif
