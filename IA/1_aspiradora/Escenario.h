#include "Aspiradora.h"

#ifndef ESCENARIO_H
#define ESCENARIO_H
#define N 30

enum TamBasura { MUCHA = 25, REGULAR = 15, POCA = 8};
enum Areas { AREA_A, AREA_B };

class Escenario {
private:
    char *areaA[N], *areaB[N];  // se definen las filas que debe tener la matriz
    Aspiradora *aspiradora;

public:
    Escenario ();
    void imprimir();
    void tirarBasura(int x, int y, unsigned int cant, char area);
    void limpiar(int x, int y, char area);
    ~Escenario ();
};

#endif
