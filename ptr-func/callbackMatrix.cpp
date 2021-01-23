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
#define M 10

/* Programa para realizar pocas operaciones sobre matrices usando arreglos de apuntadores a funciones y la clase
   vector */

void imprimirMatriz(int [N][M], int, int, void (*)(int [N][M], int, int));
void llenarMatrizAleatoria(int [N][M], int, int);
int menu();

//Funciones que se pasarán como paramentros a la funcion imprimirMatriz();
void MFULL(int [N][M], int, int);     //toda la matriz
void MSD(int [N][M], int, int);                          //matriz superior derecha
void MID(int [N][M], int, int);                         //matriz inferior derecha
void MSI(int [N][M], int, int);                          //matriz superior izquierda
void MII(int [N][M], int, int);                          //matriz inferiro izquierda

int main(int argc, char const *argv[]) {
    int matriz[N][M], opc;

    cout << "Obteniendo la matriz aleatoria...\nMatriz:\n";
    llenarMatrizAleatoria(matriz, N, M);
    imprimirMatriz(matriz, N, M, MFULL);

    while ((opc = menu()) != 'e') {
        switch (opc) {
            case 'a':
            case 'A':
                     cout << "Matriz Triangular superior Derecha:" << endl;
                     imprimirMatriz(matriz, N, M, MSD);
                     break;

            case 'b':
            case 'B':
                     cout << "Matriz Triangular inferior Derecha:" << endl;
                     imprimirMatriz(matriz, N, M, MID);
                     break;

            case 'c':
            case 'C':
                     cout << "Matriz Triangular superior Izquierda:" << endl;
                     imprimirMatriz(matriz, N, M, MSD);
                     break;

            case 'd':
            case 'D':
                     cout << "Matriz Triangular Inferior Izquierda:" << endl;
                     imprimirMatriz(matriz, N, M, MII);
                     break;

            default:
                     cout << "Opcion incorrecta" << endl;
                     break;
        }
    }

    return 0;
}

void llenarMatrizAleatoria(int matriz[N][M], int n, int m) {
    srand( time( NULL ) );

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            //cout << setw(5) << right << matriz[i][j];
            matriz[i][j] = 1 + rand() % 100;
        }
    }
}

void imprimirMatriz(int matriz[N][M], int n, int m, void (*tipoMatriz)(int matriz[N][M], int n, int m)) {
    (*tipoMatriz)(matriz, n, m);
}

void MFULL(int matriz[N][M], int n, int m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << setw(5) << right << matriz[i][j];
        }
        cout << endl;
    }
}

void MSD(int matriz[N][M], int n, int m) {
    for (size_t i = 0; i < n; i++) {
        //Imprime ceros para rellenar la parte inferior
        for (size_t k = 0; k < i; k++)
            cout << setw(5) << right << "0";

        for (size_t j = i; j < m; j++) {
            cout << setw(5) << right << matriz[i][j];
        }
        cout << endl;
    }
}

void MID(int matriz[N][M], int n, int m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if ((i < n-1) && (j < m-1)) {
                cout << setw(5) << right << 'n';
            } else {
                cout << setw(5) << right << 'm';
            }
        }
        cout << endl;
    }
}

void MSI(int matriz[N][M], int n, int m) {
    /* code */
}

void MII(int matriz[N][M], int n, int m) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j <= i; j++) {
            cout << setw(5) << right << matriz[i][j];
        }
        cout << endl;
    }
}

int menu(){
    char opcion;

    cout << "Seleccione el tipo de Matriz que desea imprimir\n" <<
            "a) Matriz Superior Derecha:\n" <<
            "b) Matriz Inferior Derecha:\n" <<
            "c) Matriz Superior Izquierda\n" <<
            "d) Matriz Inferior Izquierda\n"
            "e) Salir\n"
            "Opcion: ";
    cin >> opcion;

    return  (int)opcion;
}
