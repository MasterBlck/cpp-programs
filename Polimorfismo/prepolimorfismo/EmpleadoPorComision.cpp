#include <iostream>
using std::endl;
using std::cout;

#include "EmpleadoPorComision.h"

EmpleadoPorComision::EmpleadoPorComision(
                                            const string &nombre,
                                            const string &apellido,
                                            const string &nss,
                                            double vtasBrutas,
                                            double tcomision
                                        ) : nombre(nombre),
                                            apellido(apellido),
                                            numeroSeguroSocial(nss) {
    //valida e inicializa las ventas brutas
    setVentasBrutas(vtasBrutas);

    //valida e inicializa la tarifaComision
    setTarifaComision(tcomision);
}

void EmpleadoPorComision::setNombre( const string &nombre ) { this->nombre = nombre; }
string EmpleadoPorComision::getNombre() const { return nombre; }

void EmpleadoPorComision::setApellido( const string &apellido ) { this->apellido = apellido; }
string EmpleadoPorComision::getApellido() const { return apellido; }

void EmpleadoPorComision::setNumeroSeguroSocial( const string &nss) { this->numeroSeguroSocial = nss; }
string EmpleadoPorComision::getNumeroSeguroSocial() const { return numeroSeguroSocial; }

void EmpleadoPorComision::setVentasBrutas( double vtasBrutas ){
    this->ventasBrutas = ( vtasBrutas <= 0.0 ) ? 0.0 : vtasBrutas;
}

double EmpleadoPorComision::getVentasBrutas() const { return ventasBrutas; }

void EmpleadoPorComision::setTarifaComision( double tarifa ) {
    this->tarifaComision = ( tarifa <= 0.0 ) ? 0.0 : tarifa;
}

double EmpleadoPorComision::getTarifaComision() const { return tarifaComision; }

double EmpleadoPorComision::calcularIngresos(){
    return getTarifaComision() * getVentasBrutas();
}

void EmpleadoPorComision::imprimir(){
    cout << "{" << endl <<
                "\tnombre : " << nombre << "," << endl <<
                "\tapellido : " << apellido << "," << endl <<
                "\tnumeroSeguridadSocial : " << numeroSeguroSocial << "," << endl <<
                "\tventasBrutas : " << ventasBrutas << "," << endl <<
                "\ttarifaComision : " << tarifaComision << endl <<
             "}" << endl;


}

EmpleadoPorComision::~EmpleadoPorComision(){}
