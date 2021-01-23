#include <iostream>
using std::cout;
using std::endl;

#include "EmpleadoBaseMasComision.h"

EmpleadoBaseMasComision::EmpleadoBaseMasComision(
                                                  const string &nombre,
                                                  const string &apellido,
                                                  const string &nss,
                                                  double ventas,
                                                  double tarifa,
                                                  double salario
                                               )
:EmpleadoPorComision(nombre, apellido, nss, ventas, tarifa){
    setSalarioBase(salario);
}

void EmpleadoBaseMasComision::setSalarioBase( double salario ){
    this->salarioBase = (salario <= 0.0 ) ? 0.0 : salario;
}

double EmpleadoBaseMasComision::getSalarioBase() const {
    return salarioBase;
}

//Aparentemente solo serán métodos sobreescritos
double EmpleadoBaseMasComision::calcularIngresos() {
    return getSalarioBase() + EmpleadoPorComision::calcularIngresos();  // aquí se hace llamado al método de la superclase calcularIngresos()
}

void EmpleadoBaseMasComision::imprimir(){
    cout << "Con salario Base:\n";
    EmpleadoPorComision::imprimir();
    cout << "Salario Base = $ " << salarioBase << endl;
}
EmpleadoBaseMasComision::~EmpleadoBaseMasComision(){}
