#include <string>
#include "../include/Nodo.h"
using std::string;
Nodo::Nodo(string nom, int peso){
    this->vertice = nom;
    this->pesoArista = peso;
    this->ligaAdelante = NULL;
    this->ligaAbajo = NULL;
}

Nodo::Nodo(string nom){
    this->vertice = nom;
    this->pesoArista = -1;  //significa que la arista no tiene peso
    this->ligaAdelante = NULL;
    this->ligaAbajo = NULL;
}

Nodo::~Nodo(){}
