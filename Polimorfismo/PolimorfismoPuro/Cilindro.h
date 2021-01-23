#ifndef CILINDRO_H
#define CILINDRO_H

#include "Circulo.h"

class Cilindro : public Circulo {
private:
    double altura;

public:
    Cilindro (int = 0, int = 0, double = 0.0, double = 0.0);

    void establecerAltura( double );
    double obtenerAltura() const;

    virtual double obtenerArea() const;
    virtual double obtenerVolumen() const;

    virtual string obtenerNombre() const;
    virtual void imprimir() const;

    ~Cilindro ();
};

#endif
