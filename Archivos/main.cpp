#include <iostream>
using namespace std;

#include <fstream>
using std::ofstream;

#include <cstdlib>
using std::exit;

int main(){
    char nom[50], app[50], tel[20], email[100];
    ofstream archivo("contactos.dat", ios::out);

    if( !archivo ){
        cerr << "Error no se encontró el archivo";
        exit( 1 );
    }

    cout << "Escriba el nombre, apellido, número de teléfono y email" << endl
         << "Escriba EOF para finalizar (ctrl+d)\n?";
    
    while( cin >> nom >> app >> tel >> email){
        archivo << nom << ' ' << app << ' ' << tel << ' ' << email << endl;
        cout << '?';
    }
    return 0;
}