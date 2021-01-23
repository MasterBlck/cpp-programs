#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#include "Escenario.h"

Escenario::Escenario() {
    aspiradora = new Aspiradora();

    for (size_t i = 0; i < N; i++) {
        areaA[i] = new char[N]; //Se inicializan las columnas de la matriz
        areaB[i] = new char[N];

        //Se inician las áreas en un estado limpio poniendo todas las casillas en 0
        for (size_t j = 0; j < N; j++) {
            areaA[i][j] = '0';
            areaB[i][j] = '0';
        }
    }

}

void Escenario::tirarBasura(int x, int y, unsigned int cant, char area) {

    srand( time(NULL) );

    switch (area) {
        case AREA_A:
                for (size_t i = x; (i < x+cant && i < N); i++) {
                    for (size_t j = y; (j < y+cant && j < N); j++) {
                        areaA[i][j] = (char) 48+rand() % 2;
                    }
                }
                break;

        case AREA_B:
                for (size_t i = x; (i < x+cant && i < N); i++) {
                    for (size_t j = y; (j < y+cant && j < N); j++) {
                        areaB[i][j] = (char) 48+rand() % 2;
                    }
                }
                break;
    }
}

void Escenario::limpiar(int x, int y, char area) {
    switch (area) {
        case AREA_A:
            aspiradora->aspirar(areaA, N, x, y);
            break;

        case AREA_B:
            aspiradora->aspirar(areaB, N, x, y);
            break;
    }

}


void Escenario::imprimir() {

    cout << "Area A:" << endl;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cout << areaA[i][j] << "   ";
        }
        cout << endl;
    }

    cout << "\n\nArea B:" << endl;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cout << areaB[i][j] << "   ";
        }
        cout << endl;
    }
}

Escenario::~Escenario(){}
