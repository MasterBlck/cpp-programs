#include <iostream>
using std::cout;
using std::endl;

#include "Circulo.h"

Circulo::Circulo(int x, int y, double r) : Punto(x, y) {
    this->radio = r;
}

void Circulo::establecerRadio( double r ){ this->radio = r; }

double Circulo::obtenerRadio() const { return this->radio; }

double Circulo::obtenerDiametro() const {
    return this->radio * 2;
}

double Circulo::obtenerCircunferencia() const {
    return PI * obtenerDiametro();
}

double Circulo::obtenerArea() const {
    return PI * obtenerRadio() * obtenerRadio();
}

string Circulo::obtenerNombre() const {
    return "Circulo";
}

void Circulo::imprimir() const {
    cout << "Centro del circulo = "; Punto::imprimir();
    cout << "; \nRadio = " << obtenerRadio() << endl;
}
Circulo::~Circulo(){}
