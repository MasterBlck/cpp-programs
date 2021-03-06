// Demostración de un arreglo de apuntadores a funciones.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// prototipos de funciones -- cada función realiza acciones similares
void funcion0( int );
void funcion1( int );
void funcion2( int );

int main(int argc, char const *argv[]) {
    // inicializa un arreglo de 3 apuntadores a funciones, cada una
    // de las cuales recibe un argumento int y devuelve void
    void (*f[3])( int ) = { funcion0, funcion1, funcion2 };

    int opcion;

    cout << "Escriba un numero entre 0 y 2, 3 para terminar: ";
    cin >> opcion;

    // procesa la opción del usuario
    while ( ( opcion >= 0 ) && ( opcion < 3 ) ){
        // invoca la función en la selección de ubicación en
        // el arreglo f y pasa la opción como un argumento
        (*f[ opcion ])( opcion );
        cout << "Escriba un numero entre 0 y 2, 3 para terminar: ";
        cin >> opcion;
    } // fin de while

    cout << "Se completo la ejecucion del programa." << endl;

    return 0;
}

void funcion0( int a ){
    cout << "Usted escribio " << a << " por lo que se llamo a la funcion0\n\n";
} // fin de la función funcion0

void funcion1( int b ){
    cout << "Usted escribio " << b << " por lo que se llamo a la funcion1\n\n";
} // fin de la función funcion1

void funcion2( int c ){
    cout << "Usted escribio " << c << " por lo que se llamo a la funcion2\n\n";
} // fin de la función funcion2
