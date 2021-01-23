#include <iostream>
using std::cout;
using std::endl;

#include "Cilindro.h"

Cilindro::Cilindro(int x, int y, double radio, double altura) : Circulo(x, y, radio) {
    this->altura = altura;
}

void Cilindro::establecerAltura(double altura) {
    this->altura = altura;
}

double Cilindro::obtenerAltura() const {
    return this->altura;
}

double Cilindro::obtenerArea() const {
    return (2 * Circulo::obtenerArea()) + (2 * PI * Circulo::obtenerRadio() * obtenerAltura());
}

double Cilindro::obtenerVolumen() const {
    return Circulo::obtenerArea() * this->altura;
}

string Cilindro::obtenerNombre() const {
    return "Cilindro";
}

void Cilindro::imprimir() const {
    Circulo::imprimir();
    cout << "Altura = " << obtenerAltura() << endl;
}

Cilindro::~Cilindro(){}
