#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <iostream>
#include "../../Lista/include/Lista.h"
#include "../../Nodo/include/Nodo.h"

//La lista ligada será genérica
template< typename T >
class ListaLigada : public Lista< T > {
protected:
    Nodo< T > *iniLista;
    Nodo< T > *finLista;

public:
    ListaLigada();
    ListaLigada( int );
    ListaLigada( T *, int );

    //métodos para ser sobreescritos desde la superclase (aquí ya no se indicará que son métodos sobreescritos)
    virtual void agregarAlInicio( T );
    virtual void agregarAlFinal( T );
    virtual T eliminarAlInicio();
    virtual T eliminarAlFinal();
    virtual void agregarEn(int , T );
    virtual T eliminarEn(int);
    virtual bool estaVacia() const;    // irá en función de iniLista de cada subclase

    //Impresiones
    virtual string mToString() const;
    virtual void imprimir() const;
    virtual T obtenerValorInicial() const;
    virtual T obtenerValorFinal() const;
    virtual T obtenerValorEn( int ) const;

    ~ListaLigada();
};

template< typename T >
ListaLigada< T >::ListaLigada() {
    iniLista = finLista = NULL;
    Lista< T >::nElementos = 0;
}

template< typename T >
ListaLigada< T >::ListaLigada( int tam ) {
    Lista< T >::nElementos = static_cast< size_t >( tam );
    iniLista = finLista = NULL;

    //Al inicializar la lista, la iniciamos con elementos vacios
    for (size_t i = 0; i < tam; i++) {
        //insertar al final un elemento vacío
    }
}

template< typename T >
ListaLigada< T >::ListaLigada(T *arreglo, int tam) {
    Lista< T >::nElementos = static_cast< size_t >( tam );
    iniLista = finLista = NULL;

    //inicializar la lista con los elementos del arreglo
    for (size_t i = 0; i < tam; i++) {
        //insertar al final un elemento del arreglo
        //agregarAlFinal( arreglo[i] );
    }
}

//métodos polimórficamente sobreescritos desde la clase Lista
template< typename T >
void ListaLigada< T >::agregarAlInicio( T elemento ){
    Nodo< T > *nuevo = new Nodo< T >( elemento );

    nuevo->liga = iniLista;
    iniLista = nuevo;
    Lista< T >::nElementos++;
}

template< typename T >
void ListaLigada< T >::agregarAlFinal( T elemento ){
    Nodo< T > *nuevo = new Nodo< T >( elemento );

    if (estaVacia()) {
        iniLista = finLista = nuevo;
    } else {
        finLista->liga = nuevo;
        finLista = finLista->liga;
    }

    Lista< T >::nElementos++;
}

template< typename T >
T ListaLigada< T >::eliminarAlInicio(){
    Nodo< T > *viejo;
    T datoViejo;

    if (estaVacia()) {
        //validar error en caso de tratar de eliminar un nodo en una lista vacía
        cerr << "Error al intentar eliminar en lista vacía\n";
        return 0;
    } else {
        datoViejo = iniLista->obtenerDato();
        viejo = iniLista;
        iniLista = iniLista->liga;

        delete viejo;
    }

    Lista< T >::nElementos--;

    return datoViejo;
}

template< typename T >
T ListaLigada< T >::eliminarAlFinal() {
    Nodo< T > *viejo;
    T datoViejo;

    if (estaVacia()) {
        //validar error en caso de tratar de eliminar un nodo en una lista vacía
        cerr << "Error al intentar eliminar en lista vacía\n";
        return 0;
    } else {
        datoViejo = finLista->obtenerDato();
        viejo = finLista;
        finLista = iniLista;
        //error
        while (finLista->liga != viejo && finLista->liga != NULL) {
            finLista = finLista->liga;
        }

        finLista->liga = NULL;

        delete viejo;
    }

    Lista< T >::nElementos--;

    return datoViejo;
}

template< typename T >
void ListaLigada< T >::agregarEn(int i, T elemento ) {

}

template< typename T >
T ListaLigada< T >::eliminarEn(int i) {
    T test;
    return test;
}

template< typename T >
bool ListaLigada< T >::estaVacia() const {
    return iniLista == NULL && finLista == NULL;
}

//Impresiones
template< typename T >
void ListaLigada< T >::imprimir() const {
    Nodo< T > *ite = iniLista;

    while (ite != NULL) {
        cout << ite->obtenerDato() << "->" ;
        ite = ite->liga;
    }
}

template< typename T >
string ListaLigada< T >::mToString() const{
    Nodo< T > *ite = iniLista;
    string strLista = "";

    while (ite != NULL) {
        //Error de tipos
        strLista += ite->obtenerDato() + "->" ;
        ite = ite->liga;
    }

    return strLista;
}

template< typename T >
T ListaLigada< T >::obtenerValorInicial() const {

    if(iniLista == NULL && finLista == NULL){
        cerr << "Error al obtener valor inicial, lista vacia\n";
        return 0;
    } else {
        return iniLista->obtenerDato();
    }
}

template< typename T >
T ListaLigada< T >::obtenerValorFinal() const {

    if(iniLista == NULL && finLista == NULL){
        cerr << "Error al obtener valor final, lista vacia\n";
        return 0;
    } else {
        return finLista->obtenerDato();
    }
}

template< typename T >
T ListaLigada< T >::obtenerValorEn( int i ) const {
    T test;
    return test;
}

template< typename T >
ListaLigada< T >::~ListaLigada() {
    //delete finLista;
    //delete iniLista;
}
#endif
