#include <iostream>
#include <cstdlib>
#include <ctime>
#include "include/Nodo.h"
#include "include/ListaLigada.h"

#define TAM 10     //<-- constante para el tamaño de la lista
using namespace std;

int main(int argc, char const *argv[]){
    srand( time(NULL) );                       // <---- Función que servirá para cambiar el orden de los números por cada segundo que pase
    ListaLigada *listita = new ListaLigada();  //<--- Tienes una nueva lista ligada ;)
    
    
    //agregando números aleatorios a la lista
    for (int i = 0; i < TAM; i++) {      
        listita->agregarAlFinal( rand()%101 );  // agregamos al final un número al azar del 0 al 100
    }

    listita->imprimir();
    cout << endl;

    //Agregamos unos 3 elementos al inicio e imprimimos
    listita->agregarAlInicio(677);
    listita->agregarAlInicio(688);
    listita->agregarAlInicio(999);
    listita->imprimir();
    cout << endl;

    //Agregamos unos 2 elementos al final e imprimimos
    listita->agregarAlFinal(-8);
    listita->agregarAlFinal(-9);
    listita->imprimir();
    cout << endl;

    //Eliminamos 2 elementos al final
    listita->eliminarAlFinal();
    listita->eliminarAlFinal();
    listita->imprimir();
    cout << endl;

    //Eliminamos 2 elementos al inicio
    listita->eliminarAlInicio();
    listita->eliminarAlInicio();
    listita->imprimir();
    cout << endl;

    delete listita;  // en C++ debes "destruir" cada objeto
    return 0;
}
