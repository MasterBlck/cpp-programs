#include <iostream>
using namespace std;

#include <fstream>
using std::ifstream;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;


void imprimirLinea( string, const string, string, string ); // prototipo

int main(){
    char nom[50], app[50], tel[20], email[100];
    // el constructor de ifstream abre el archivo
    ifstream archivo( "clientes.dat", ios::in );

    // sale del programa si ifstream no pudo abrir el archivo
    if ( !archivo ){
        cerr << "No se pudo abrir el archivo" << endl;
        exit( 1 );
    }

    cout << "Imprimiendo el contenido del archivo" << endl;

    while( archivo >> nom >> app >> tel >> email ){
        imprimirLinea(nom, app, tel, email);
    }
    return 0;
}

void imprimirLinea(string nom, const string app, string tel, string email){
    cout << "Nombre : " << nom << endl
         << "Apellido : " << app << endl
         << "Teléfono : " << tel << endl
         << "Email : " << email 
         << "\n\n";
}