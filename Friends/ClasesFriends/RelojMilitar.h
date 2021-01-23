#ifndef RELOJMILITAR_H
#define RELOJMILITAR_H

class RelojMilitar {
    friend void modificarHorario(RelojMilitar &, int, int, int);
private:
    int hora, minutos, segundos;

public:
    RelojMilitar(int, int, int);
    void establecerHora(int, int, int);
    void imprimirHora();
};

#endif
