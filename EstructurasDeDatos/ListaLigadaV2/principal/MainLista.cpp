#include <iostream>
//#include <cstdlib>
//#include <ctime>
#include "../headers/ListaLigada.h"

using std::cout;
using std::endl;

int main()
{
	//srand(time(NULL));

	ListaLigada listita;
	listita.insertarAlInicio(8);
	listita.insertarAlInicio(9);
	listita.insertarAlInicio(12);

	listita.imprimir();
	cout << "\n";

	listita.insertarAlFinal(14);
	listita.insertarAlFinal(2);

	listita.imprimir();
	cout << "\nNumero de elementos antes de borrar: " << listita.obtenerNumElementos() << endl;

	//listita.borrarAlInicio();
	//listita.borrarAlFinal();
	listita.borrarEnPosicion(2);
	listita.imprimir();
	cout << "\nNumero de elementos despues de borrar: " << listita.obtenerNumElementos() << endl;

	//int eliminado = listita.borrarAlFinal2(); //<----------un posible error DE FUGA DE MEMORIA
	//cout << "Dato eliminado: " << eliminado << endl;
	listita.borrarAlFinal();
	listita.imprimir();
	cout << "\nNumero de elementos despues de borrar: " << listita.obtenerNumElementos() << endl;
	return 0;
}
