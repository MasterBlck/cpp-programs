#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "include/ListaLigada.h"

int main() {
    ListaLigada< int > listInt;
    ListaLigada< float > listFloat;

    srand( time(NULL) );

    //agregando elementos a las listas de tipo prinitivo
    for (size_t i = 0; i < 10; i++) {
        listInt.agregarAlFinal( rand()%101 );
        listFloat.agregarAlFinal( (rand()%101) * 0.5 );
    }

    // Imprimiendo los arreglos
    listInt.imprimir();
    cout << endl;
    listFloat.imprimir();
    cout << endl;

    cout << "Eliminando elementos al inicio :\n";
    listInt.eliminarAlInicio();
    listFloat.eliminarAlInicio();
    listInt.imprimir();
    cout << endl;
    listFloat.imprimir();
    cout << endl;

    cout << "Eliminando elementos al final :\n";
    listInt.eliminarAlFinal();
    listFloat.eliminarAlFinal();
    listInt.imprimir();
    cout << endl;
    listFloat.imprimir();
    cout << endl;

    cout << "Eliminando ultimos elementos al final :\n";
    listInt.eliminarAlFinal();
    listFloat.eliminarAlFinal();
    listInt.imprimir();
    cout << endl;
    listFloat.imprimir();
    cout << endl;

    cout << "Tratando de eliminar elementos al final :\n";
    listInt.eliminarAlFinal();
    listFloat.eliminarAlFinal();
    listInt.imprimir();
    cout << endl;
    listFloat.imprimir();
    cout << endl;


    return 0;
}
