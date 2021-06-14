#include <iostream>
#include "calculadora.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int x = 12, y = 10;
	int x2 = 14, y2 = 90;
	calculadora calc(1);
	calculadora *calc2 = new calculadora(2); 
	calculadora *pcalc;
	pcalc = &calc;

	cout << "suma: " << calc.sumar(x, y) << "\n" << endl;
	cout << "resta: " << pcalc->restar(x, y) << "\n" << endl;
	cout << "multiplicacion: " << calc2->multiplicar(x2, y2) << "\n" << endl;
	cout << "division: " << calc.dividir(x, y) << "\n" << endl;
	return 0;
}
