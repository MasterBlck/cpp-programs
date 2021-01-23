#include <iostream>
using std::cout;
using std::fixed;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include "Figura.h"
#include "Punto.h"
#include "Circulo.h"
#include "Cilindro.h"

void virtualViaApuntador( const Figura * );
void virtualViaReferencia( const Figura & );

int main() {
    //establecer formato de punto flotante
    cout << fixed << setprecision(2);

    Punto punto(7, 11);                            //Crear un punto
    Circulo circulito( 22, 8, 3.5 );               //crear un circulo
    Cilindro cilindro(10, 10, 3.3, 10);            //crear un Cilindro

    // VINCULACIÓN ESTATICA
    cout << punto.obtenerNombre() << ": \n";
    punto.imprimir();
    cout << "\n\n";

    // VINCULACIÓN ESTATICA
    cout << circulito.obtenerNombre() << ": \n";
    circulito.imprimir();
    cout << "\n";

    // VINCULACIÓN ESTATICA
    cout << cilindro.obtenerNombre() << ": \n";
    cilindro.imprimir();
    cout << "\n";

    //Creando un vector de 3 apuntadores de la clase padre 'Fugura'
    vector<Figura *> figuraVector(3);

    figuraVector[0] = &punto;
    figuraVector[1] = &circulito;
    figuraVector[2] = & cilindro;

    //Usar un ciclo para recorrer elementos de figuraVector y llamar
    //a virtualViaApuntador()
    //para imprimir el nombre se la figura, los atributos, el área y el
    //volumen de  cada objeto mediante la vinculación dinámica
    cout << "\nLlamadas a funciones virtuales mediante apuntadores de la clase base: \n\n";
    for (size_t i = 0; i < figuraVector.size(); i++) {
        virtualViaApuntador( figuraVector[i] );
    }

    //Usar un ciclo para recorrer elementos de figuraVector y llamar
    //a virtualViaReferencia()
    //para imprimir el nombre se la figura, los atributos, el área y el
    //volumen de  cada objeto mediante la vinculación dinámica
    cout << "\nLlamadas a funciones virtuales mediante referencia de la clase base: \n\n";
    for (size_t i = 0; i < figuraVector.size(); i++) {
        virtualViaReferencia( *figuraVector[i] );
    }

    return 0;
}

//Hacer llamadas a funciones virtuales mediante un apuntador de la clase base utilizando
//vinculación dinámica
void virtualViaApuntador( const Figura *ptrClaseBase ){
    cout << ptrClaseBase->obtenerNombre() << ": ";

    ptrClaseBase->imprimir();

    cout << "El área es : " << ptrClaseBase->obtenerArea()
         << "\nEl volumen es : " << ptrClaseBase->obtenerVolumen()
         << "\n\n";
}

//Hacer llamadas a funciones virtuales mediante una referencia de la clase base utilizando
//vinculación dinámica
void virtualViaReferencia( const Figura &refClaseBase ){
    cout << refClaseBase.obtenerNombre() << ": ";

    refClaseBase.imprimir();

    cout << "El área es : " << refClaseBase.obtenerArea()
         << "\nEl volumen es : " << refClaseBase.obtenerVolumen()
         << "\n\n";
}
