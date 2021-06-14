#include <iostream>
#include "../include/Grafo.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    Grafo grafo(5);
    cout << "Programación del grafo dinámico\nGrafo:"<<endl;

    //Operaciones sobre el grafo
    grafo.insertarAristaDirigida("1", "3");
    grafo.insertarAristaNoDirigida("0", "4");
    grafo.insertarAristaNoDirigida("2", "1");
    grafo.insertarAristaNoDirigida("2", "3");
    grafo.insertarAristaNoDirigida("3", "4");
    grafo.insertarAristaDirigida("3", "0");
    grafo.insertarAristaNoDirigida("0", "1");

    cout << "Antes de eliminar la arista:"<< endl;
    grafo.imprimir();
    cout << "\n";

    grafo.eliminarArista("1", "3");
    grafo.eliminarArista("3", "0");
    grafo.eliminarArista("1", "0");
    grafo.eliminarArista("3", "4");

    cout << "Despues de eliminar la arista:"<< endl;
    grafo.imprimir();
    cout << "\n";
    return 0;
}
