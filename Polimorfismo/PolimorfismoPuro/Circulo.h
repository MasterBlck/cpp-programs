#ifndef CIRCULO_H
#define CIRCULO_H

#include "Punto.h"

class Circulo : public Punto {
private:
    double radio;

protected:
    const double PI = 3.1416;

public:
    Circulo (int = 0, int = 0, double = 0.0);

    void establecerRadio( double );
    double obtenerRadio() const;
    double obtenerDiametro() const;
    double obtenerCircunferencia() const;
    //Función heredada como virtual desde la clase Figura
    virtual double obtenerArea() const;

    //la función imprimir() de la clase padre se va a sobreescribir
    virtual string obtenerNombre() const;
    virtual void imprimir() const;
    ~Circulo ();
};

#endif
