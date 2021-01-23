#include <iostream>
using std::cout;
using std::endl;
int main(){
    int c;

    // demuestra el postincremento
    c = 5; // asigna 5 a c
    cout << c << endl; // print 5
    cout << c++ << endl; // imprime 5 y después postincrementa
    cout << c << endl; // imprime 6
    cout << endl; // salta una línea

    // demuestra el preincremento
    c = 5; // asigna 5 a c
    cout << c << endl; // imprime 5
    cout << ++c << endl; // preincrementa y después imprime 6
    cout << c << endl; // imprime 6
    return 0; // indica que terminó correctamente
} // fin de main
