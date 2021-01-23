#include <iostream>
using std::cout;
using std::endl;

#include "RelojMilitar.h"

RelojMilitar::RelojMilitar(int h, int m, int s)
    :hora(h),
    minutos(m),        //Inicialización estilo const, pero las variavles no son const
    segundos(s) { }

void RelojMilitar::establecerHora(int h, int m, int s){
    hora = (h > 0 && h <= 24) ? h : 1;
    minutos = (m >= 0 && m < 60) ? m : 1;
    segundos = (s >= 0 && s < 60) ? s : 1;
}

//Imprime la hora en el formato (hh:mm:ss) 24 hrs
void RelojMilitar::imprimirHora(){
    cout << hora << ":" << minutos << ":" << segundos << endl;
}


//Nuestra función friend va a modificar la hora:
void modificarHorario(RelojMilitar &relojcito, int h, int m, int s) {
    cout << "Funcion friend modificarHorario("<< h << ", "<< m <<", "<< s <<") de la clase RelojMilitar\n";
    relojcito.hora = (h >= 0 && h <= 24) ? h : 1;
    relojcito.minutos = (m >= 0 && m < 60) ? m : 1;
    relojcito.segundos = (s >= 0 && s < 60) ? s : 1;
}
