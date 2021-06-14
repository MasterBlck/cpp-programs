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
    ListaLigada listita;

    for (int i = 0; i < N; i++) {
        listita.insertarAlFinal(rand()%101);
    }

    cout << "Lista principal: "; listita.imprimir();
    cout << "\nValor Inicial: "<< listita.obtenerValorInicial() << endl;
    cout << "Valor Final: "<< listita.obtenerValorFinal() << endl;
    cout << "Valor en posicion 9: " << listita.obtenerValorEn(9) << endl;
    cout << "Valor maximo: "<< listita.obtenerMaximo() << endl;
    cout << "Valor minimo: "<< listita.obtenerMinimo() << endl;
    cout << "Promedio: " << listita.obtenerPromedio() << endl;
    cout << "Sumatoria: "<< listita.obtenerSumatoria() << endl;
    cout << "Multiplicatoria: "<< listita.obtenerMultiplicatoria() << endl;
    return 0;
}
