#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo{
private:
    int hora, minuto, segundo;

public:
    Tiempo( int = 0, int = 0, int = 0 ); // constructor predeterminado

    // funciones "set" (los tipos de valores de retorno Tiempo & permiten las llamadas en cascada del mismo objeto que se está instanciando)
    Tiempo &setTiempo( int, int, int ); // set hora, minuto, segundo
    Tiempo &setHora( int ); // establece la hora
    Tiempo &setMinuto( int ); // establece el minuto
    Tiempo &setSegundo( int ); // establece el segundo

    // funciones "get" (por lo general se declaran const)
    int getHora() const; // devuelve la hora
    int getMinuto() const; // devuelve el minuto
    int getSegundo() const; // devuelve el segundo

    // funciones para imprimir (por lo general se declaran const)
    void imprimirUniversal() const; // imprime el tiempo universal
    void imprimirEstandar() const; // imprime el tiempo estándar
};

#endif
