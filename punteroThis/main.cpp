#include <iostream>
using std::cout;
using std::endl;

#include "Tiempo.h" // definición de la clase Tiempo

int main() {
    Tiempo t; // crea un objeto Tiempo

    // llamadas en cascada a funciones
    t.setHora( 18 ).setMinuto( 30 ).setSegundo( 22 );
    // imprime el tiempo en los formatos universal y estándar

    cout << "Tiempo universal: ";
    t.imprimirUniversal();

    cout << "\nTiempo estandar: ";
    t.imprimirEstandar();

    cout << "\n\nNuevo tiempo estandar: ";
    // llamadas en cascada a funciones
    t.setTiempo( 20, 20, 20 ).imprimirEstandar();
    cout << endl;
    return 0;
} // fin de main
