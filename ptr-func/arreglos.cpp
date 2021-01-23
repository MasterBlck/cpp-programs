#include <iostream>
using std::cout;
using std::cin;
using std::left;
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

#define N 50
/* Programa para realizar pocas operaciones sobre arreglos usando arreglos de apuntadores a funciones y la clase
   vector */

int suma(const vector< int > &);
int max(const vector< int > &);
void obtenerVectorAleatorio(vector< int > &);
void ordenar(vector<int> &);
void imprimir(const vector<int> &);

int main(int argc, char const *argv[]) {
    //Empieza el programa
    vector<int> misDatos(N);
    char opc;
    int maximo, sumatoria;

    //arreglo de punteros a funciones inicalizados
    int (*fun_enteras[2])(const vector<int> &) = { suma, max };

    //inicializando arreglo de punteros 1 por 1
    void (*funs_void[2])( vector<int> & );
    funs_void[0] = obtenerVectorAleatorio;
    funs_void[1] = ordenar;

    //puntero a funcion para 'imprimir()'
    void (*fun_imprimir)(const vector<int> &);
    fun_imprimir = imprimir;

    //-------------------------------------------------------------------
    cout << "Obteniendo un vector aleatorio de " << N << " elementos" << endl;
    (*funs_void[0])(misDatos);
    cout << "El vector es: \n";
    (*fun_imprimir) (misDatos);

    do {
        cout << "Seleccione la operación que desea realizar " << endl
             << "a) Ordenar el arreglo" << endl
             << "b) Obtener el máximo del arreglo" << endl
             << "c) Obtener la sumatoria del arreglo" << endl
             << "d) Salir" << endl
             << "opción ? ";
        cin >> opc;

        switch (opc) {
            case 'a':
            case 'A':
                     (*funs_void[1])(misDatos);
                     cout << "Arreglo Ordenado:" << endl;
                     (*fun_imprimir)(misDatos);
                     break;

            case 'b':
            case 'B':
                    //Obtenemos el máximo del arreglo de manera explícita
                    maximo = (*fun_enteras[1])(misDatos);
                    cout << "El máximo del arreglo es: "  << maximo << endl;
                    break;

            case 'c':
            case 'C':
                    //Obtenemos la sumatoria del arreglo de manera explícita
                    sumatoria = (*fun_enteras[0]) (misDatos);
                    cout << "La sumatoria del arreglo es " << sumatoria << endl;
                    break;

            case 'd':
            case 'D': // se sale del programa pero en este 'case' no hace nada
                    break;

            default: cout << "Opción incorrecta :(" << endl;
        }

    } while(opc != 'd' && opc != 'D');

    cout << "Fin del programa :)" << endl;
    return 0;
}

int suma(const vector<int> &arreglo){
    int sum = 0;
    for (size_t i = 0; i < arreglo.size(); i++) {
        sum += arreglo[i];
    }

    return sum;
}

int max(const vector<int> &arreglo){
    int max = arreglo[0], i = 0;

    while (i < arreglo.size()) {
        if (max < arreglo[i])
            max = arreglo[i];

        i++;
    }

    return max;
}

void obtenerVectorAleatorio(vector<int> &arreglo){
    srand( time( NULL) );

    for (size_t i = 0; i < arreglo.size(); i++) {
        arreglo[i] = 1 + rand() % 101;
    }
}

void ordenar(vector<int> &arreglo){
    //ordenamiento por insersión
    int temp;
    for (int siguiente = 1; siguiente < arreglo.size(); siguiente++) {
        temp = arreglo[siguiente];
        int moverElemento = siguiente;

        while ((moverElemento > 0) && (arreglo[moverElemento - 1] > temp)) {
            arreglo[moverElemento] = arreglo[moverElemento - 1];
            moverElemento--;
        }

        arreglo[moverElemento] = temp;
    }
}

void imprimir(const vector<int> &arreglo){
    for (size_t i = 0; i < arreglo.size(); i++) {
        cout << setw(4) << left << arreglo[i];
        if (i % 5 == 0) { cout << endl; }
    }

    cout << endl;
}
