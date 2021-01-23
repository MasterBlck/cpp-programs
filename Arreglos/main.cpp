#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Arreglo.h"

int main() {
    Arreglo *a = new Arreglo(8);
    Arreglo b(28);
    Arreglo *resultado = new Arreglo();

    a->obtenerValoresAlatorios();
    b.obtenerValoresAlatorios();

    cout << "Contenido del Arreglo A:" << endl;
    cout << *a;

    cout << "Contenido del Arreglo B:" << endl;
    cout << b;

    cout << "Contenido del Arreglo resultado:" << endl;
    *resultado = *a + b;
    cout << *resultado;

    delete a;
    delete resultado;

    return 0;
}
