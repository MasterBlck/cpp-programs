#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../headers/ListaLigada.h"
#define N 16

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
    srand(time(NULL));
    ListaLigada listaprincipal;
    ListaLigada sublista;

    for (int i = 0; i < N; i++) {
        listaprincipal.insertarAlFinal(rand() % 101);
        /*if(i < N/2)
            sublista.insertarAlFinal(rand() % 101);*/
    }

    cout << "Lista principal: ";
    listaprincipal.imprimir();
    cout << "\nNum. de elementos en lista principal: " <<listaprincipal.obtenerNumElementos()<<endl;

    cout << "\nSublista: ";
    sublista.imprimir();

    //agregando una sublista a la lista principal
    //listaprincipal.insertarSublistaAlInicio(sublista);
    //listaprincipal.insertarSublistaAlFinal(sublista);
    //listaprincipal.insertarSublistaEni(9, sublista);
    listaprincipal.borrarRango(5, 11);

    cout << "\nLista principal: ";
    listaprincipal.imprimir();
    cout << "\nNum. de elementos en lista principal: " <<listaprincipal.obtenerNumElementos()<<endl;

    cout << '\n';
    return 0;
}
