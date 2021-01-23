#include <iostream>
using std::cout;
using std::endl;

#include "RelojMilitar.h"
#include "RelojEstandar.h"

int main(int argc, char const *argv[]) {
    RelojEstandar restandar(2, 8, 45);
    RelojMilitar rmilitar(23, 15, 15);

    cout << "Hora estandar antes de modificarla: ";
    restandar.imprimirHora();

    cout << "Hora militar antes de modificarla: ";
    rmilitar.imprimirHora();

    modificarHorario(restandar, 1, 0, 0);
    modificarHorario(rmilitar, 0, 0, 0);

    cout << "Hora estandar después de modificarla: ";
    restandar.imprimirHora();

    cout << "Hora militar después de modificarla: ";
    rmilitar.imprimirHora();
    return 0;
}
