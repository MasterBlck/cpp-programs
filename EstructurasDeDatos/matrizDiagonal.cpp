/* Programa para sacar la diagonal de una matriz*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define TAM 10

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int matriz[TAM][TAM];
	srand(time(NULL));

	//llenando la matriz
	for(int i=0; i<TAM; i++)
	{
		for(int j=0; j<TAM; j++)
		{
			matriz[i][j] = 1+rand()%(101-1); //numeros aleatorios entre 1 y 100
		}
	}

	//imprimiendo solo las diagonales
	for(int i=0; i<TAM; i++)
        {
                cout << matriz[i][i] << "\n" << endl; 
        }

	//imprimiendo la matriz completa
	 for(int i=0; i<TAM; i++)
        {
                for(int j=0; j<TAM; j++)
                {
                        cout << matriz[i][j] << "   ";
                }
		cout << "\n";
        }


	return 0;

}
