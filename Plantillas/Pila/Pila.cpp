#include <iostream>
#include "Pila.h"

template< typename T >
Pila< T >::Pila< T >(int t){
    cima = -1;
    tam = t > 0 ? t : 10;   // se valida que el tamaño sea > 0
    pilaPtr = new T[tam];
}

template< typename T >
void Pila< T >::push(const T &valor) {
    if( !estaLlena() ){
        pilaPtr[ ++cima ] = valor;
    }
}

template< typename T >
bool Pila< T >::pop(T &valorFuera){
    if ( !estaVacia() ) {
        valorFuera = pilaPtr[ cima-- ];
        return true;
    }

    return false;
}

template< typename T >
bool Pila< T >::estaVacia() const{
    return cima == -1;
}

template< typename T >
bool Pila< T >::estaLlena() const{
    return cima == tam - 1;
}

template< typename T >
int Pila< T >::size() const{
    return tam;
}

template< typename T >
Pila< T >::~Pila(){
    delete [] pilaPtr;
}
