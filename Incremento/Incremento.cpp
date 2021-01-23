// Fig. 10.5: Incremento.cpp
// Las definiciones de las funciones miembro para la clase Incremento demuestran el uso
// de un inicializador de miembros para inicializar una constante de un tipo de datos integrado.
#include <iostream>
using std::cout;
using std::endl;

#include "Incremento.h" // incluye la definición de la clase Incremento
// constructor
Incremento::Incremento( int c, int i )
    : cuenta( c ), // inicializador para un miembro no const
        incremento( i ) // inicializador requerido para un miembro const
{
// cuerpo vacío
} // fin del constructor de Incremento

// imprime los valores de cuenta e incremento
void Incremento::imprimir() const{
    cout << "cuenta = " << cuenta << ", incremento = " << incremento << endl;
} // fin de la función imprimir
