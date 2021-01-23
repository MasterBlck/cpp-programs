#include <iostream>
#include <thread>

using std::cout;
using std::thread;

void hola(){
	cout<<"Hola este es un programa concurrente\n";
}

int main(){
	thread hilo(hola);
	hilo.join();
	return 0;
}
