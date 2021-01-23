#ifndef FIGURA_H
#define FIGURA_H

#include <string>
using std::string;

class Figura {
private:
    /* data */

public:
    virtual double obtenerArea() const;
    virtual double obtenerVolumen() const;

    //Funciones Abstractas que hacen de ésta clase Abstracta
    virtual string obtenerNombre() const = 0;    //con una funcion que tengamos = 0 la clase será abstracta
    virtual void imprimir() const = 0;
};

#endif
