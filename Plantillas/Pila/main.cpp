#include <iostream>
using std::cout;
using std::endl;

#include "Pila.h"

int main() {
    Pila< double > pDoubles;
    Pila< int > pInts( 15 );

    cout << "Metiendo valores a la pila de doubles:\n";
    for (size_t i = 0; i < pDoubles.size(); i++) {
        pDoubles.push( i * 0.5 );
    }

    cout << "Sacando valores de la pila de doubles:\n";
    double valorObtenido;
    while( !pDoubles.estaVacia() ) {
        pDoubles.pop( valorObtenido );
        cout << valorObtenido << endl;
    }

    cout << "Metiendo valores a la pila de enteros:\n";
    for (size_t i = 0; i < pInts.size(); i++) {
        pInts.push( i * i );
    }

    cout << "Sacando valores de la pila de enteros:\n";
    int valorObtenidoI;
    while( !pInts.estaVacia() ) {
        pInts.pop( valorObtenidoI );
        cout << valorObtenidoI << endl;
    }

    return 0;
}
