#include <iostream>
using std::cout;
using std::endl;

#include "Punto.h"

Punto::Punto(int x, int y){
    this->x = x;
    this->y = y;
}

void Punto::setX(int x){ this->x = x; }

int Punto::getX() const { return this->x; }

void Punto::setY(int y){ this->y = y; }

int Punto::getY() const { return this->y; }

string Punto::obtenerNombre() const {
    return "Punto";
}

void Punto::imprimir() const {
    cout << "[ " << this->x << "," << this->y << " ]";
}

Punto::~Punto(){}
