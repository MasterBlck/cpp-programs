#include <iostream>
#include "Aspiradora.h"

Aspiradora::Aspiradora() : N(9)
{}

void Aspiradora::aspirar(char *area[], int n, int x, int y) {
    std::cout << "Entro a a.aspirar()" << '\n';

    //algoritmo que mueve a x, y al centro del área que se quiere limpiar
    // N = Tamanio del área que se quiere limpiar
    // n = Tamanio del área A o B del Escenario
    for (int i = x - N/2; i <= x+N/2 ; i++) {
        for (int j = y - N/2; j <= y+N/2; j++) {
            // tanto i como j están dentro del rango del tamanio del área del escenario??
            if ((i >= 0 && i < n) && (j >=0 && j < n)) {
                area[i][j] = '0';
            }
        }
    }
}

Aspiradora::~Aspiradora(){}
