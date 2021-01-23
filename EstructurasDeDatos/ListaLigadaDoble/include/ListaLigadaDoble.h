#ifndef LISTALIGADADOBLE_H
#define LISTALIGADADOBLE_H

#include <iostream>
#include "../../Lista/include/Lista.h"
#include "../../NodoDoble/include/NodoDoble.h"

//La lista ligada será genérica
template< typename T >
class ListaLigadaDoble : public Lista< T >{
protected:
    NodoDoble< T > *iniLista;
    NodoDoble< T > *finLista;

public:
    ListaLigadaDoble();
    ListaLigadaDoble( int );
    ListaLigadaDoble( T * );

    //métodos para ser sobreescritos desde la superclase (aquí ya no se indicará que son métodos sobreescritos)
    virtual void agregarAlInicio( T );
    virtual void agregarAlFinal( T );
    virtual T eliminarAlInicio();
    virtual T eliminarAlFinal();
    virtual void agregarEn(int , T );
    virtual T eliminarEn(int);
    virtual bool estaVacia() const;    // irá en función de iniLista de cada subclase

    //Impresiones
    virtual string mToString() const;
    virtual void imprimir() const;
    virtual T obtenerValorInicial() const;
    virtual T obtenerValorFinal() const;
    virtual T obtenerValorEn( int ) const;

    ~ListaLigadaDoble ();
};

template< typename T >
ListaLigadaDoble< T >::ListaLigadaDoble() {
    iniLista = finLista = NULL;
}

template< typename T >
ListaLigadaDoble< T >::ListaLigadaDoble( int tam ) {

    iniLista = finLista = NULL;
}

template< typename T >
ListaLigadaDoble< T >::ListaLigadaDoble(T *arreglo) {
    iniLista = finLista = NULL;
}

//métodos polimórficamente sobreescritos desde la clase Lista
template< typename T >
void ListaLigadaDoble< T >::agregarAlInicio( T elemento ){

}

template< typename T >
void ListaLigadaDoble< T >::agregarAlFinal( T elemento ){

}

template< typename T >
T ListaLigadaDoble< T >::eliminarAlInicio() {
    T test;
    return test;
}

template< typename T >
T ListaLigadaDoble< T >::eliminarAlFinal() {
    T test;
    return test;
}

template< typename T >
void ListaLigadaDoble< T >::agregarEn(int i, T elemento ) {

}

template< typename T >
T ListaLigadaDoble< T >::eliminarEn(int i) {
    T test;
    return test;
}

template< typename T >
bool ListaLigadaDoble< T >::estaVacia() const {
    return iniLista == NULL;
}

//Impresiones
template< typename T >
void ListaLigadaDoble< T >::imprimir() const {

}

template< typename T >
string ListaLigadaDoble< T >::mToString() const {
    return "";
}

template< typename T >
T ListaLigadaDoble< T >::obtenerValorInicial() const {
    T test;
    return test;
}

template< typename T >
T ListaLigadaDoble< T >::obtenerValorFinal() const {
    T test;
    return test;
}

template< typename T >
T ListaLigadaDoble< T >::obtenerValorEn( int i ) const {
    T test;
    return test;
}

template< typename T >
ListaLigadaDoble< T >::~ListaLigadaDoble() {
    //delete finLista;
    //delete iniLista;
}
#endif
