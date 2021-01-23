#ifndef NODO_H
#define NODO_H

#include <iostream>
class Nodo {
private:
    int data;

public:
    Nodo *liga;
    Nodo(int dato);

    //métodos de encapsulamiento
    int obtenerDato();
    void establecerDato(int elemento);
    void imprimir();
    ~Nodo();
};

#endif