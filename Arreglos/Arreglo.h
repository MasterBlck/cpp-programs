#include <iostream>
using std::istream;
using std::ostream;

#ifndef ARREGLO_H
#define ARREGLO_H

class Arreglo {
    friend ostream &operator<<(ostream &, const Arreglo &);
    friend istream &operator>>(istream &, Arreglo &);

    friend Arreglo operator+(const int &, const Arreglo &);
private:
    int *ptr; //será el arreglo que se estará manejando dentro de la clase
    unsigned int tamanio;

public:
    Arreglo ( int = 10 ); //valor predeterminado para el Arreglo
    Arreglo ( const Arreglo & ); //constructor copia
    void restablecerTamanio( int );
    unsigned int obtenerTamanio() const;
    void obtenerValoresAlatorios();
    ~Arreglo ();

    //Operadores Sobrecargados
    const Arreglo &operator=( const Arreglo &);
    bool operator==( const Arreglo & ) const;
    bool operator!=( const Arreglo & ) const;

    //operadores aritmeticos Sobrecargados
    Arreglo operator+(const Arreglo &);
    Arreglo operator-(const Arreglo &);
    Arreglo operator*(const Arreglo &);
    Arreglo operator/(const Arreglo &);

    Arreglo operator*(const int &);

    int &operator[]( int );
    int operator[]( int ) const;
};

#endif
