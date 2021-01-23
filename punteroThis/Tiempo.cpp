#include <iostream>
using std::cout;
#include <iomanip>
using std::setfill;
using std::setw;
#include "Tiempo.h" // Definición de la clase Tiempo

// función constructor para inicializar los datos privados;
// llama a la función miembro setTiempo para establecer las variables;
// los valores predeterminados son 0 (vea la definición de la clase)
Tiempo::Tiempo( int hr, int min, int seg ){
    setTiempo( hr, min, seg );
} // fin del constructor de Tiempo

// establece los valores de hora, minuto y segundo
Tiempo &Tiempo::setTiempo( int h, int m, int s ){ // observe Tiempo & return
    setHora( h );
    setMinuto( m );
    setSegundo( s );
    return *this; // permite las llamadas en cascada
} // fin de la función setTiempo

// establece el valor de hora
Tiempo &Tiempo::setHora( int h ){ // observe Tiempo & return
    hora = ( h >= 0 && h < 24 ) ? h : 0; // valida la hora
    return *this; // permite las llamadas en cascada
} // fin de la función setHora

// establece el valor de minuto
Tiempo &Tiempo::setMinuto( int m ){ // observe Tiempo & return
    minuto = ( m >= 0 && m < 60 ) ? m : 0; // valida el minuto
    return *this; // permite las llamadas en cascada
} // fin de la función setMinuto

// establece el valor de segundo
Tiempo &Tiempo::setSegundo( int s ){ // observe Tiempo & return
    segundo = ( s >= 0 && s < 60 ) ? s : 0; // valida el segundo
    return *this; // permite las llamadas en cascada
} // fin de la función setSegundo

// obtiene el valor de hora
int Tiempo::getHora() const {
    return hora;
} // fin de la función getHora

// obtiene el valor de minuto
int Tiempo::getMinuto() const {
    return minuto;
} // fin de la función getMinuto

// obtiene el valor de segundo
int Tiempo::getSegundo() const {
    return segundo;
} // fin de la función getSegundo

// imprime el Tiempo en formato universal (HH:MM:SS)
void Tiempo::imprimirUniversal() const {
    cout << setfill( '0' ) << setw( 2 ) << hora << ":"
    << setw( 2 ) << minuto << ":" << setw( 2 ) << segundo;
} // fin de la función imprimirUniversal

// imprime el Tiempo en formato estándar (HH:MM:SS AM o PM)
void Tiempo::imprimirEstandar() const {
    cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )
    << ":" << setfill( '0' ) << setw( 2 ) << minuto
    << ":" << setw( 2 ) << segundo << ( hora < 12 ? " AM" : " PM" );
} // fin de la función imprimirEstandar
