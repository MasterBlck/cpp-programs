#include <iostream>
using std::cout;
using std::endl;

#include "EmpleadoPorComision.h"
#include "EmpleadoBaseMasComision.h"

int main(int argc, char const *argv[]) {
    EmpleadoPorComision empleadoporcom("Juan", "Perez", "56789709", 1000, 0.06);
    EmpleadoPorComision *ptrEmpleadoPorComi = NULL;

    EmpleadoBaseMasComision empleadobasemascomi( "Tirza", "Baez", "765653378", 500, 0.04, 300);
    EmpleadoBaseMasComision *ptrempleadobasemascomi = NULL;


    cout << "Impresion de los objetos de la superclase y la clase hija\n";
    empleadoporcom.imprimir();
    empleadobasemascomi.imprimir();

    //Orienta el apuntador de la clase base al objeto de la clase base e imprime
    ptrEmpleadoPorComi = &empleadoporcom;
    cout << "Imprimiendo a Juan Perez por medio de un apuntador\n";
    ptrEmpleadoPorComi->imprimir();

    //Orienta el apuntador de la clase derivada al objeto de la clase derivada e imprime
    ptrempleadobasemascomi = &empleadobasemascomi;
    cout << "Imprimiendo a Tirza Baez (clase hija) por medio de un apuntador\n";
    ptrempleadobasemascomi->imprimir();

    //Orienta el apuntador de CLASE BASE al objeto de CLASE DERIVADA e imprime
    ptrEmpleadoPorComi = &empleadobasemascomi;
    cout << "Imprimiendo a Tirza Baez (clase hija) por medio de un apuntador de la CLASE BASE\n";
    ptrEmpleadoPorComi->imprimir();

    return 0;
}
