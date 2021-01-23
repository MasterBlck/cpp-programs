#ifndef PILA_H
#define PILA_H

#include <iostream>

//Sintáxis para declara que ésta clase sea genérica
template< typename T >
class Pila {
private:
    T *pilaPtr;
    int cima;
    size_t tam;

public:
    Pila (size_t = 10);

    //Funciones de pila
    void push(const T &);
    bool pop(T &);

    //hay o no elementos en la pila
    bool estaVacia() const;
    bool estaLlena() const;

    size_t size() const;

     ~Pila ();
};

template< typename T >
Pila< T >::Pila(size_t t){
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
size_t Pila< T >::size() const{
    return tam;
}

template< typename T >
Pila< T >::~Pila(){
    delete [] pilaPtr;
}


#endif
