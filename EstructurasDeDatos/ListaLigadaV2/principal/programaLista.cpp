#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../headers/ListaLigada.h"
#define N 10

using std::cout;
using std::cin;
using std::endl;

void menu();

int main()
{
    char opc;
    ListaLigada listita;
	srand(time(NULL));

	for (int i = 1; i <= N; i++) {
	    listita.insertarAlFinal(rand() % 101);
	}

    cout << "Lista Inicial:\n";
	listita.imprimir();
    menu();
    cin >> opc;

    while(opc != '7'){

        switch (opc) {
            case '1':
                    listita.insertarAlInicio(rand() % 101);
                    break;

            case '2':
                    listita.insertarAlFinal(rand() % 101);
                    break;

            case '3':
                    if(listita.borrarAlInicio() == -1)
                        std::cerr << "error al borrarAlInicio" << '\n';
                    break;

            case '4':
                    if(listita.borrarAlFinal() == -1)
                        std::cerr << "error al borrarAlFinal" << '\n';
                    break;

            case '5':
                    int i;
                    cout << "Posicion i donde se desea insertar ? "<<"[0..."<< listita.obtenerNumElementos() - 1 << "]\n";
                    cin >> i;
                    listita.insertarEnPosicion(i, rand() % 101);
                    break;

            case '6':
                    int k;
                    cout << "Posicion i donde se desea borrar ? "<<"[0..."<< listita.obtenerNumElementos() - 1 << "]\n";
                    cin >> k;
                    if(listita.borrarEnPosicion(k) == -1)
                        std::cerr << "Error al borrarEnPosicion i" << '\n';
                    break;

            default:
                    cout << "Opción incorrecta" << '\n';
                    menu();
                    break;
        }

        std::cout << "Numero de elementos: "<< listita.obtenerNumElementos() << '\n';
        listita.imprimir();
        cout << "\nOtra opción?" << '\n';
        cin >> opc;
    }


	return 0;
}

void menu(){
    cout << "\n1) Insertar al inicio\n"<<
            "2) Insertar al final\n"<<
            "3) Borrar al Inicio\n"<<
            "4) Borrar al final\n"<<
            "5) Insertar en i posicion\n"<<
            "6) Borrar en i posicion\n"
            "7) Salir\n?: "<<endl;
}
