#ifndef NODO_H
#define NODO_H

#include <iostream>

//El nodo tendrá datos genéricos
template< typename T >
class Nodo {
private:
    T data;

public:
    Nodo *liga;
    Nodo(T dato);

    //métodos de encapsulamiento
    T obtenerDato();
    void establecerDato(T elemento);
    ~Nodo();
};

//No se permite generar un archivo.cpp
template< typename T >
Nodo< T >::Nodo( T dato ){
    liga = NULL;
    this->data = dato;
}

template< typename T >
Nodo< T >::~Nodo(){ }

#endif
