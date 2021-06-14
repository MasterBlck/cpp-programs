#include <iostream>
#include "calculadora.h"

calculadora::calculadora(int id)
{
	this->id = id;
}

int calculadora::sumar(int a, int b)
{
	return a+b;
}

int calculadora::restar(int a, int b)
{
        return a-b;
}

int calculadora::multiplicar(int a, int b)
{
        return a*b;
}

float calculadora::dividir(int a, int b)
{
        return b==0 ? -1 : a/b;
}

calculadora::~calculadora()
{
	std::cout << "destruyendo calculadora " << this->id << std::endl;
}
