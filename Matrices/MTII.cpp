/* Programa para manipular una Matriz Triangular Inferior Izquierda */
#include <iostream>
using std::cout;
using std::cin;
using std::left;
using std::right;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <vector>
using std::vector;

#include <iomanip>
using std::setw;

#define N 10

int matriz[N][N];

void llenarMatrizAleatoria();
void imprimirMatriz();
void imprimirMTII();
void almacenarMTIIenVector(int vector[], int tam);
void imprimirMTIIenVector(int vector[], int tam);

int main(int argc, char const *argv[]) {
    int tamanio = (int) N*(N-1)/2;  //el tamanio del vector se calcula de acuerdo al tamanio de la matriz
    int vectorMTII[tamanio];

    cout << "Obteniendo la matriz aleatoria...\nMatriz:\n";
    llenarMatrizAleatoria();
    imprimirMatriz();

    cout << "Matriz Triangular Inferior Izquierda:" << endl;
    imprimirMTII();

    cout << "Almacenando MTII en vector...\nVector:\n";
    almacenarMTIIenVector(vectorMTII, tamanio);
    imprimirMTIIenVector(vectorMTII, tamanio);

    return 0;
}

void llenarMatrizAleatoria(){
    srand( time( NULL ) );
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            matriz[i][j] = 1 + rand() % 100;
        }
    }
}

void imprimirMatriz(){
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cout << setw(5) << right << matriz[i][j];
        }
        cout << endl;
    }
}

void imprimirMTII() {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j <= i; j++) {
            cout << setw(5) << right << matriz[i][j];
        }
        cout << endl;
    }
}

void almacenarMTIIenVector(int vector[], int tam){
    /*Algoritmo de orden O(n^2) para almacenar los elementos de la MTII en un vector*/
    int posicion;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            posicion = i*(i-1)/2 + j;
            vector[posicion] = matriz
        }
        cout << endl;
    }
}

void imprimirMTIIenVector(int vector[], int tam){

}
