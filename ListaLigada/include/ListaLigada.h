#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "Nodo.h"

class ListaLigada {
protected:
    Nodo *iniLista;
    Nodo *finLista;
    int nElementos;
public:
    ListaLigada();

    //métodos para ser sobreescritos desde la superclase (aquí ya no se indicará que son métodos sobreescritos)
    void agregarAlInicio( int data );
    void agregarAlFinal( int data );
    int eliminarAlInicio();
    int eliminarAlFinal();
    //void agregarEn(int index, int data);
    //int eliminarEn(int index);
    bool estaVacia();    // irá en función de iniLista de cada subclase

    //Impresiones
    //string mToString();
    void imprimir();
    int obtenerValorInicial();
    int obtenerValorFinal();
    //int obtenerValorEn( int index );

    ~ListaLigada();
};
#endif