#ifndef NODODOBLE_H
#define NODODOBLE_H

#include "../../Nodo/include/Nodo.h"

template< typename T >
class NodoDoble : public Nodo< T > {   //al momento de hacer la herencia, debemos especificar el tipo de dato T
public:
    NodoDoble *ligaAtras;
    NodoDoble (T dato);
    ~NodoDoble ();
};

template< typename T >
NodoDoble< T >::NodoDoble(T dato) : Nodo< T >( dato ){  //al momento de llamar al constructor de la superclase, debemos especificar el tipo de dato T
    ligaAtras = NULL;  //posible error
}

template< typename T >
NodoDoble< T >::~NodoDoble(){ }

#endif
