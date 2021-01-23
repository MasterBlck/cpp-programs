#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    int x, y;

public:
    Punto (int = 0, int = 0);

    void setX(int);
    int getX() const;

    void setY(int);
    int getY() const;

    //declaramos virtual a éste método para hacer uso del polimorfismo
    virtual void imprimir() const;
    ~Punto ();
};

#endif
