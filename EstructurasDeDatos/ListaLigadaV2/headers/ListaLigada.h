#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "Nodo.h"

class ListaLigada{
	public:
		ListaLigada();
		~ListaLigada();
		void insertarAlInicio(int dat);
		void insertarAlFinal(int dat);
		void insertarEnPosicion(int i, int dat);
		void imprimir();
		int borrarAlInicio();
		int borrarEnPosicion(int i);
		int borrarAlFinal();
		int borrarAlFinal2();
		int obtenerNumElementos();
		Nodo* obtenerInicio();
		//Operaciones con sublistas
		void insertarSublistaAlInicio(ListaLigada l);
		void insertarSublistaAlFinal(ListaLigada l);
		void insertarSublistaEni(int i, ListaLigada l);
		ListaLigada obtenerSublista(int i, int j);
		void borrarRango(int i, int j);
		//Impresiones
		int obtenerValorInicial();
		int obtenerValorFinal();
		int obtenerValorEn(int i);
		//Operaciones Matematicas
		int obtenerMaximo();
		int obtenerMinimo();
		float obtenerPromedio();
		int obtenerSumatoria();
		int obtenerMultiplicatoria();
	private:
		Nodo *iniLista;
		int numElementos;
};

#endif
