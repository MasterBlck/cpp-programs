#include <iostream>
using std::cout;
using std::endl;

#include "Punto.h"
#include "Circulo.h"

int main() {

    Punto punto(30, 50);
    Punto *ptrPunto = NULL;

    Circulo circulito( 120, 89, 2.7 );
    Circulo *ptrCirculo = NULL;

    cout << "Punto: " << endl;
    punto.imprimir();

    cout << "Circulo: \n";
    circulito.imprimir();

    //Dirigir el apuntador de la clase base al objeto de la clase base e imprimir
    ptrPunto = &punto;
    cout << "Punto (por ptr): " << endl;
    ptrPunto->imprimir();

    ptrCirculo = &circulito;
    cout << "Circulo (por Ptr): \n";
    ptrCirculo->imprimir();

    //Dirigir el apuntador de la clase base al objeto de la CLASE DERIVADA e imprimir
    ptrPunto = &circulito;
    cout << "\nCirculo (por ptrPunto): \n";
    ptrPunto->imprimir();

    return 0;
}
