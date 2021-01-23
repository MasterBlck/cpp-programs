#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

void imprimirVector( const vector< int > & ); // muestra el vector
void recibirVector( vector< int > & ); // introduce los valores en el vector
void compararVectores(const vector< int > &, const vector< int > &);

int main(int argc, char const *argv[]) {
    vector< int > enteros1( 7 ); // vector de 7 elementos< int >
    vector< int > enteros2( 10 ); // vector de 10 elementos< int >

    // imprime el tamaño y el contenido de enteros1
    cout << "El tamanio del vector enteros1 es " << enteros1.size()
         << "\nvector despues de la inicializacion:" << endl;
    imprimirVector( enteros1 );

    // imprime el tamaño y el contenido de enteros2
    cout << "\nEl tamanio del vector enteros2 es " << enteros2.size()
    << "\nvector despues de la inicializacion:" << endl;
    imprimirVector( enteros2 );

    // recibe e imprime enteros1 y enteros2
    cout << "\nEscriba 17 enteros:" << endl;
    recibirVector( enteros1 );
    recibirVector( enteros2 );
    cout << "\nDespues de la entrada, los vectores contienen:\n"
    << "enteros1:" << endl;
    imprimirVector( enteros1 );
    cout << "enteros2:" << endl;
    imprimirVector( enteros2 );

    compararVectores(enteros1, enteros2);

    // crea el vector enteros3 usando enteros1 como un
    // inicializador; imprime el tamaño y el contenido
    vector< int > enteros3( enteros1 ); // constructor de copia

    cout << "\nEl tamanio del vector enteros3 es " << enteros3.size()
    << "\nvector despues de la inicializacion:" << endl;
    imprimirVector( enteros3 );

    // usa el operador de asignacion (=) con objetos vector
    cout << "\nAsignacion de enteros2 a enteros1:" << endl;
    enteros1 = enteros2; // asigna enteros2 a enteros1

    cout << "enteros1:" << endl;
    imprimirVector( enteros1 );
    cout << "enteros2:" << endl;
    imprimirVector( enteros2 );

    compararVectores(enteros1, enteros2);

    // usa corchetes para crear rvalue
    cout << "\nenteros1[5] es " << enteros1[ 5 ];

    // usa corchetes para crear lvalue
    cout << "\n\nAsignacion de 1000 a enteros1[5]" << endl;
    enteros1[ 5 ] = 1000;
    cout << "enteros1:" << endl;
    imprimirVector( enteros1 );

    // intenta usar subíndice fuera de rango
    cout << "\nIntento de asignar 100000 a enteros1.at( 5 )" << endl;
    enteros1.at( 5 ) = 100000; // ERROR: fuera de rango
    imprimirVector(enteros1);
    return 0;
}

// imprime el contenido del vector
void imprimirVector( const vector< int > &arreglo ){
    size_t i;
    for (i = 0; i < arreglo.size(); i++) {
        cout << setw( 12 ) << arreglo[ i ];

        if ( ( i + 1 ) % 4 == 0 ) // 4 números por fila de resultados
            cout << endl;
    }

    if ( i % 4 != 0 )
        cout << endl;
}

// recibe el contenido del vector
void recibirVector( vector< int > &arreglo ){
    srand( time( NULL ) );
    for ( size_t i = 0; i < arreglo.size(); i++ ){
        arreglo[i] = 1 + rand() % 100;
    }
} // fin de la función recibirVector

void compararVectores(const vector< int > &v1, const vector< int > &v2){
    if (v1 != v2) {
        cout << "Los vectores son diferentes" << '\n';
    }else if( v1 == v2) {
        cout << "Los vectores son iguales" << '\n';
    }
}// fin de compararVectores()
