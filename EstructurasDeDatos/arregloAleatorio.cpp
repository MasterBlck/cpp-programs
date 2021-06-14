#include <iostream>
using namespace std;

#include <cstdlib>
using std::rand;


int main(int argc, char* argv[])
{
	int arreglo[10];
	int aux;

	//obteniendo arreglo
	for(int i=0; i<10; i++)
	{
		arreglo[i] = 1 + rand()%(101-1);
		cout << arreglo[i]<< "\n";
	}

	cout << "---------------------------------\n";

	//ordenando el arreglo
	for(int i = 1; i<=10; i++)
	{
		for(int j=0; j<=(10-2); j++)
		{
			if(arreglo[j] > arreglo[j+1])
			{
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}


	for(int i=0; i<10; i++)
        {
                cout << arreglo[i]<< "\n";
        }

        cout << "---------------------------------\n";


	return 0;
}
