#include <iostream>
#include "../headers/Vector.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	Vector vector;

	cout << "Vector en zeros:\n";
	vector.imprimirVector();

	//llenando el vector aleatoriamente
	vector.llenarAleatorio();

	cout << "vector con elementos aleatorios:\n";
	vector.imprimirVector();

	return 0;
}
