#ifndef CIRCULO_H
#define CIRCULO_H

#include "Punto.h"

class Circulo : public Punto {
private:
    const double PI = 3.1416;
    double radio;

public:
    Circulo (int = 0, int = 0, double = 0.0);

    void establecerRadio( double );
    double obtenerRadio() const;
    double obtenerDiametro() const;
    double obtenerCircunferencia() const;
    double obtenerArea() const;

    void imprimir() const;
    ~Circulo ();
};

#endif
