#include <string>
using std::string;

#include "EmpleadoPorComision.h"

#ifndef BASEMAS_H
#define BASEMAS_H

class EmpleadoBaseMasComision : public EmpleadoPorComision {
private:
    double salarioBase;

public:
    EmpleadoBaseMasComision (const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0);

    void setSalarioBase( double );
    double getSalarioBase() const ;

    //Aparentemente solo serán métodos sobreescritos
    double calcularIngresos();
    void imprimir();

    ~EmpleadoBaseMasComision ();
};

#endif
