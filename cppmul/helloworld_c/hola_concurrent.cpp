#include <iostream>
#include <thread>

using std::cout;
using std::thread;

void hola(){
	cout<<"Hola este es un programa concurrente\n";
}

int &suma(){
	return suma();
}

int main(){
	thread t(hola);
	t.join();
	return 0;
}
