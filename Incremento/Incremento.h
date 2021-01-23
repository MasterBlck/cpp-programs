// Fig. 10.4: Incremento.h
// Definición de la clase Incremento.
#ifndef INCREMENTO_H
#define INCREMENTO_H

class Incremento
{
    public:
        Incremento( int c = 0, int i = 1 ); // constructor predeterminado
        // definición de la función agregarIncremento

        void agregarIncremento(){
            cuenta += incremento;
        } // fin de la función agregarIncremento

        void imprimir() const; // imprime cuenta e incremento

    private:
        int cuenta;
        const int incremento; // miembro de datos const
}; // fin de la clase Incremento
#endif
