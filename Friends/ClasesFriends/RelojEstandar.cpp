#include <iostream>
using std::cout;
using std::endl;

#include "RelojEstandar.h"

RelojEstandar::RelojEstandar(int h, int m, int s){
    establecerHora(h, m, s);
}

void RelojEstandar::establecerHora(int h, int m, int s){
    hora = (h > 0 && h <= 12) ? h : 1;
    minutos = (m >= 0 && m < 60) ? m : 1;
    segundos = (s >= 0 && s < 60) ? s : 1;
}

void RelojEstandar::imprimirHora(){
    cout << hora << ":" << minutos << ":" << segundos << endl;
}

void modificarHorario(RelojEstandar &reloj, int h, int m, int s) {
    reloj.establecerHora(h, m, s);
}
