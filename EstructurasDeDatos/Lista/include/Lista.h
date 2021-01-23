#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

//Será una lista genérica abstracta (superclase)
template< typename T >
class Lista {
protected:
    size_t nElementos;

public:
    size_t size();

    //operaciones básicas de las estructuras lineales
    virtual void agregarAlInicio( T ) = 0;
    virtual void agregarAlFinal( T ) = 0;
    virtual T eliminarAlInicio() = 0;
    virtual T eliminarAlFinal() = 0;
    virtual void agregarEn(int , T ) = 0;
    virtual T eliminarEn(int) = 0;
    virtual bool estaVacia() const = 0;    // irá en función de iniLista de cada subclase

    //Impresiones
    virtual string mToString() const = 0;
    virtual void imprimir() const = 0;
    virtual T obtenerValorInicial() const = 0;
    virtual T obtenerValorFinal() const = 0;
    virtual T obtenerValorEn( int ) const = 0;

    //Agregar conversiones de arreglo a lista
};

template< typename T >
size_t Lista< T >::size(){
    return nElementos;
}

#endif
