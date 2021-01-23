#include <string>
using std::string;

#ifndef COMISION_H
#define COMISION_H

class EmpleadoPorComision {
private:
    string nombre;
    string apellido;
    string numeroSeguroSocial;
    double ventasBrutas;
    double tarifaComision;

public:
    EmpleadoPorComision (const string &, const string &, const string &, double = 0.0, double = 0.0);

    void setNombre(const string &);
    string getNombre() const;

    void setApellido(const string &);
    string getApellido() const;

    void setNumeroSeguroSocial(const string &);
    string getNumeroSeguroSocial() const;

    void setVentasBrutas( double );
    double getVentasBrutas() const;

    void setTarifaComision( double );
    double getTarifaComision() const;

    double calcularIngresos();
    void imprimir();
    ~EmpleadoPorComision ();
};

#endif
