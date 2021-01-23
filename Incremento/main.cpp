// Programa para probar la clase Incremento.
#include <iostream>
using std::cout;

#include "Incremento.h" // incluye la definición de la clase Incremento

int main(int argc, char const *argv[]) {
    Incremento valor( 10, 5 );

    cout << "Antes de incrementar: ";
    valor.imprimir();
    
    for ( int j = 1; j <= 3; j++ ){
        valor.agregarIncremento();
        cout << "Despues de incrementar " << j << ": ";
        valor.imprimir();
    } // fin de for
    return 0;
}
