#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../headers/Vector.h"

using std::cout;
using std::endl;

Vector::Vector()
{
	for(int i=0; i < 10; i++)
		vector[i] = 0;
}

void Vector::llenarAleatorio()
{
	srand(time(NULL));

	for(int i=0; i < 10; i++)
		vector[i] = 1+rand()%(101-1);
}

void Vector::imprimirVector()
{
	for(int i=0; i < 10; i++)
                cout << vector[i] << endl;
}
