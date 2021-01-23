#ifndef PUNTO_H
#define PUNTO_H

#include "Figura.h"

class Punto : public Figura{
private:
    int x, y;

public:
    Punto (int = 0, int = 0);

    void setX(int);
    int getX() const;

    void setY(int);
    int getY() const;

    //declaramos virtual a éste método para hacer uso del polimorfismo
    virtual string obtenerNombre() const;   //al heredar de la clase Figura no es necesario poner el = 0
    virtual void imprimir() const;

    ~Punto ();
};

#endif
