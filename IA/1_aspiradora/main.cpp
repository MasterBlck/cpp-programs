#include "Escenario.h"

int main() {
    Escenario *miEscenario = new Escenario();

    miEscenario->imprimir();
    miEscenario->tirarBasura(29, 29, POCA, AREA_A);
    miEscenario->limpiar(26, 26, AREA_A);
    miEscenario->imprimir();

    delete miEscenario;
    return 0;
}
