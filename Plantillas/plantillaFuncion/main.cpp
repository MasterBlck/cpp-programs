#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//Definición de una plantilla de función
template< typename T>             //Define un tipo T que puede ser cualquier tipo de dato
void imprimirUnArreglo(T *arreglo, int &n){
    for (size_t i = 0; i < n; i++) {
        cout << " arreglo[" << i << "] = " << arreglo[i] << endl;
    }
    cout << endl;
}

int main() {
    int tamA = 8;
    int tamB = 9;
    int tamC = 12;
    int tamD = 5;

    int enteros[tamA] = {9, 7, 0, 4, 5, 1, 7, 8};
    float flotantes[tamB] = {9.9, 7.5, 9.8, 4.5, 5.4, 1.8, 7.1, 8.9};
    char letras[tamC] = "Jovencito";
    string palabras[tamD] = {
        "cabeza",
        "nombre",
        "escuela",
        "sexy_girl",
        "ojos"
    };

    cout << "El arreglo de enteros contiene: \n";
    imprimirUnArreglo( enteros , tamA);

    cout << "El arreglo de flotantes contiene: \n";
    imprimirUnArreglo( flotantes, tamB );

    cout << "El arreglo de letras contiene: \n";
    imprimirUnArreglo( letras, tamC );

    cout << "El arreglo de palabras contiene: \n";
    imprimirUnArreglo( palabras, tamD );
    return 0;
}
