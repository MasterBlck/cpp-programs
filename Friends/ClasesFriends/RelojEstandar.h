#ifndef RELOJESTANDAR_H
#define RELOJESTANDAR_H

class RelojEstandar{
    friend void modificarHorario(RelojEstandar &, int, int, int);
private:
    int hora, minutos, segundos;

public:
    RelojEstandar(int, int, int);
    void establecerHora(int, int, int);
    void imprimirHora();
};

#endif
