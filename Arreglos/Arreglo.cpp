#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::exit;
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#include "Arreglo.h"

Arreglo::Arreglo(int tam) {

    tamanio = ( tam > 0 ? tam : 10);
    ptr = new int[tamanio];

    for (size_t i = 0; i < tamanio; i++)
        ptr[i] = 0;
}

Arreglo::Arreglo(const Arreglo &copia){
    tamanio = copia.tamanio;

    ptr = new int[tamanio];
    for (size_t i = 0; i < tamanio; i++)
        ptr[i] = 0;
}

void Arreglo::restablecerTamanio( int t ) {
    Arreglo tmp(tamanio);
    if (t == static_cast<int>(tamanio)) return;

    tmp = *this;    //invoca al operator Sobrecargado =
    tamanio = t;
    delete [] ptr;
    ptr = new int[tamanio];

    //debe realizar el ciclo de acuerdo al tamanio de éste arreglo
    for (size_t i = 0; i < tamanio; i++) {
        ptr[i] = (tmp.obtenerTamanio() <= i) ? 0 : tmp.ptr[i];
    }

}

unsigned int Arreglo::obtenerTamanio() const {
    return tamanio;
}

void Arreglo::obtenerValoresAlatorios(){
    srand( time(NULL) );
    for (size_t i = 0; i < tamanio; i++) {
        ptr[i] = 1 + rand() % 101;
    }
}

const Arreglo &Arreglo::operator=( const Arreglo &derecho){
    //evitamos la autoasignación
    if ( &derecho != this) {

        if (tamanio != derecho.tamanio) {
            tamanio = derecho.tamanio;
            delete [] ptr;

            ptr = new int[tamanio];
        }

        for (size_t i = 0; i < tamanio; i++) {
            ptr[i] = derecho.ptr[i];
        }
    }

    return *this;
}

bool Arreglo::operator==( const Arreglo &derecho ) const {

    if (tamanio != derecho.obtenerTamanio())
        return false;

    for (size_t i = 0; i < tamanio; i++) {
        if (ptr[i] != derecho.ptr[i])
            return false;
    }

    return true;
}

bool Arreglo::operator!=( const Arreglo &derecho ) const {
    return !(*this == derecho);
}

ostream &operator<<(ostream &pantalla, const Arreglo &a){
    for (size_t i = 0; i < a.tamanio; i++) {
        pantalla << "Arreglo[" << i << "] = " << a.ptr[i] << endl;
    }

    return pantalla;
}

istream &operator>>(istream &entrada, Arreglo &a){
    for (size_t i = 0; i < a.tamanio; i++) {
        entrada >> a.ptr[i];
    }

    return entrada;
}

int &Arreglo::operator[](int indice){
    //verificar el manejo de errores
    if (indice < 0 || indice >= static_cast<int>(tamanio)) {
        cerr << "Error, índice fuera de rango" << '\n';
        exit(1);
    }

    return ptr[indice];
}

int Arreglo::operator[](int indice) const {
    //verificar el manejo de errores
    if (indice < 0 || indice >= static_cast<int>(tamanio)) {
        cerr << "Error, índice fuera de rango" << '\n';
        exit(1);
    }

    return ptr[indice];
}

//Sumar 2 Arreglos
Arreglo Arreglo::operator+(const Arreglo &derecho){
    Arreglo resultado;

    //Si éste Arreglo es de mayor tamaño que el de la derecha entonces el
    //resultado debe ser de igual tamanio que el de éste objeto
    if (tamanio >= derecho.obtenerTamanio()) {
        resultado.restablecerTamanio(tamanio);
    } else {
        resultado.restablecerTamanio(derecho.obtenerTamanio());
    }

    for (size_t i = 0; i < resultado.obtenerTamanio(); i++) {

        if (i >= derecho.obtenerTamanio()) {
            resultado.ptr[i] = ptr[i];
        } else if (i >= tamanio){
            resultado.ptr[i] = derecho.ptr[i];
        }else{
            resultado.ptr[i] = ptr[i] + derecho.ptr[i];
        }
    }

    return resultado;
}

//Restar 2 Arreglos
Arreglo Arreglo::operator-(const Arreglo &derecho){
    Arreglo resultado;

    //Si éste Arreglo es de mayor tamaño que el de la derecha entonces el
    //resultado debe ser de igual tamanio que el de éste objeto
    if (tamanio >= derecho.obtenerTamanio()) {
        resultado.restablecerTamanio(tamanio);
    } else {
        resultado.restablecerTamanio(derecho.obtenerTamanio());
    }

    for (size_t i = 0; i < resultado.obtenerTamanio(); i++) {

        if (i >= derecho.obtenerTamanio()) {
            resultado.ptr[i] = ptr[i];
        } else if (i >= tamanio){
            resultado.ptr[i] = derecho.ptr[i];
        }else{
            resultado.ptr[i] = ptr[i] - derecho.ptr[i];
        }
    }

    return resultado;
}

//Multiplicar 2 Arreglos
Arreglo Arreglo::operator*(const Arreglo &derecho){
    Arreglo resultado;

    //Si éste Arreglo es de mayor tamaño que el de la derecha entonces el
    //resultado debe ser de igual tamanio que el de éste objeto
    if (tamanio >= derecho.obtenerTamanio()) {
        resultado.restablecerTamanio(tamanio);
    } else {
        resultado.restablecerTamanio(derecho.obtenerTamanio());
    }

    for (size_t i = 0; i < resultado.obtenerTamanio(); i++) {

        if (i >= derecho.obtenerTamanio()) {
            resultado.ptr[i] = ptr[i];
        } else if (i >= tamanio){
            resultado.ptr[i] = derecho.ptr[i];
        }else{
            resultado.ptr[i] = ptr[i] * derecho.ptr[i];
        }
    }

    return resultado;
}

//Dividir 2 Arreglos
Arreglo Arreglo::operator/(const Arreglo &derecho){
    Arreglo resultado;

    //Si éste Arreglo es de mayor tamaño que el de la derecha entonces el
    //resultado debe ser de igual tamanio que el de éste objeto
    if (tamanio >= derecho.obtenerTamanio()) {
        resultado.restablecerTamanio(tamanio);
    } else {
        resultado.restablecerTamanio(derecho.obtenerTamanio());
    }

    for (size_t i = 0; i < resultado.obtenerTamanio(); i++) {

        if (i >= derecho.obtenerTamanio()) {
            resultado.ptr[i] = ptr[i];
        } else if (i >= tamanio){
            resultado.ptr[i] = derecho.ptr[i];
        }else{
            resultado.ptr[i] = (derecho.ptr[i] != 0) ? ptr[i] / derecho.ptr[i] : -1;
        }
    }

    return resultado;
}

//Multiplicar arreglo * escalar
Arreglo Arreglo::operator*(const int &esklr){
    Arreglo resultado(tamanio);

    for (size_t i = 0; i < resultado.obtenerTamanio(); i++) {
        resultado[i] = ptr[i] * esklr;
    }

    return resultado;
}

Arreglo::~Arreglo(){
    delete [] ptr;
}
