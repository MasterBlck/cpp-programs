#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setw; // permite al programa establecer una anchura de campo o tabulación específica
using std::setprecision;

#include <cmath> // biblioteca de matemáticas estándar de C++
using std::pow; // permite al programa utilizar la función pow

int main(){
    double monto; // monto a depositar al final de cada año
    double principal = 1000.0; // monto inicial antes del interés
    double tasa = .05; // tasa de interés

    // muestra los encabezados
    cout << "Anio" << setw( 21 ) << "Monto en deposito" << endl;
    // establece el formato de número de punto flotante
    cout << fixed << setprecision( 2 );

    // calcula el monto en depósito para cada uno de los diez años
    for ( int anio = 1; anio <= 10; anio++ ){
        // calcula el nuevo monto para el año especificado
        monto = principal * pow( 1.0 + tasa, anio );
        // muestra el año y el monto
        cout << setw( 4 ) << anio << setw( 21 ) << monto << endl;
    } // fin de for

    return 0;
}
