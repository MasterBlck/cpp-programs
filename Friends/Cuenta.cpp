#include <iostream>
using std::cout;
using std::endl;



class Cuenta{
        friend void establecerX(Cuenta &, int);

    public:
        Cuenta() : x(0){    // x = 0;
        }

        void imprimir(){
            cout << x << endl;
        }

    private:
        int x;
};

// la función setX puede modificar los datos privados de Cuenta
// debido a que setX se declara como amiga de Cuenta (línea 10)
void establecerX( Cuenta &c, int val ){  //<--------------------------No es un método de la clase Cuenta
    c.x = val; // se permite debido a que setX es amiga de Cuenta
} // fin de la función setX

int main(int argc, char const *argv[]) {
    Cuenta contador;
    cout << "contador.x despues de crear la instancia: ";
    contador.imprimir();

    //la implementación de la función friend NO está dentro de la clase
    establecerX(contador, 99);  //establece x usando la función friend
    cout << "contador.x despues de la llamada a la funcion friend setX(): ";
    contador.imprimir();

    return 0;
}
