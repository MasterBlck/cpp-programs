#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw; // permite al programa establecer una anchura de campo o tabulación específica

int main(int argc, char const *argv[]) {
    //impresión de los tamaños de todos los tipos de datos básicos en C++
    cout << setw(18) << "Tipo de dato" << setw(21) << "Tamaño en bytes" << endl;
    cout << setw(18) << "bool" << setw(20) << sizeof(bool) << endl
         << setw(18) << "char" << setw(20) << sizeof(char) << endl
         << setw(18) << "signed char" << setw(20) << sizeof(signed char) << endl
         << setw(18) << "unsigned char" << setw(20) << sizeof(unsigned char) << endl
         << setw(18) << "short int" << setw(20) << sizeof(short int) << endl
         << setw(18) << "unsigned short int" << setw(20) << sizeof(unsigned short int) << endl
         << setw(18) << "int" << setw(20) << sizeof(int) << endl
         << setw(18) << "unsigned int" << setw(20) << sizeof(unsigned int) << endl
         << setw(18) << "long int" << setw(20) << sizeof(long int) << endl
         << setw(18) << "unsigned long int" << setw(20) << sizeof(unsigned long int) << endl
         << setw(18) << "wchar_t" << setw(20) << sizeof(wchar_t) << endl
         << setw(18) << "float" << setw(20) << sizeof(float) << endl
         << setw(18) << "double" << setw(20) << sizeof(double) << endl
         << setw(18) << "long double" << setw(20) << sizeof(long double)<< endl;
    return 0;
}
