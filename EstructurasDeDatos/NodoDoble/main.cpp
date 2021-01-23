#include <iostream>
#include <string>

using namespace std;

#include "include/NodoDoble.h"

int main(int argc, char const *argv[]) {
    NodoDoble< int > nodoEntero( 45 );
    NodoDoble< double > nodoDouble( 23.89 );
    NodoDoble< string > nodoStr( "Texto" );

    Nodo< char > *letra = new NodoDoble< char >( 'c' );

    cout << "El nodo doble entero contiene: " << nodoEntero.obtenerDato() << endl;
    cout << "El nodo doble de double contiene: " << nodoDouble.obtenerDato() << endl;
    cout << "El nodo doble de string contiene: " << nodoStr.obtenerDato() << endl;

    cout << "El nodo (doble) de char contiene: " << letra->obtenerDato() << endl;
    cout << letra->ligaAtras <<"|" letra->obtenerDato() << "|" << letra->liga << endl;

    return 0;
}
