#include "../include/Nodo.h"
#include "../include/Grafo.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream;

Grafo::Grafo(){
    numVertices = 0;
    numAristas = 0;
    iniGrafo = NULL;
    finGrafo = NULL;
}

Grafo::Grafo(int numNodos){
    iniGrafo = finGrafo = NULL;
    numAristas = 0;
    for (int i = 0; i < numNodos; i++) {
        ostringstream snum;
        snum << i;
        insertarVertice(snum.str());
    }
}

void Grafo::insertarVertice(string nombre){
    Nodo *nuevo = new Nodo(nombre);
    //por lo general, los vertices se van insertando al final y hacia abajo
    if (iniGrafo == NULL) {
        iniGrafo = finGrafo = nuevo;
    }else{  //en caso de que el grafo tenga al menos un vértice
        finGrafo->ligaAbajo = nuevo;
        finGrafo = finGrafo->ligaAbajo;
    }

    numVertices++;
}

//No se está validando si el vértice NO existe
void Grafo::insertarAristaDirigida(string vorigen, string vdestino){
    Nodo *vertices = iniGrafo;

    //buscar el vértice de origen
    while (vertices->vertice != vorigen) {
        vertices = vertices->ligaAbajo;
    }

    //el vértice de origen está actualmente en vertices->vertice
    //insertar la conexión al final de las adyacencias
    while (vertices->ligaAdelante != NULL) {
        vertices = vertices->ligaAdelante;         //mover el puntero hasta el último elemento de adyacencia
    }
    Nodo *conn = new Nodo(vdestino);
    vertices->ligaAdelante = conn;
    numAristas++;
}

void Grafo::insertarAristaDirigida(string vorigen, string vdestino, int peso){
    Nodo *vertices = iniGrafo;

    //buscar el vértice de origen
    while (vertices->vertice != vorigen) {
        vertices = vertices->ligaAbajo;
    }

    //el vértice de origen está actualmente en vertices->vertice
    //insertar la conexión al final de las adyacencias
    while (vertices->ligaAdelante != NULL) {
        vertices = vertices->ligaAdelante;         //mover el puntero hasta el último elemento de adyacencia
    }
    Nodo *conn = new Nodo(vdestino, peso);
    vertices->ligaAdelante = conn;
    numAristas++;
}

void Grafo::insertarAristaNoDirigida(string vorigen, string vdestino){
    insertarAristaDirigida(vorigen, vdestino);
    insertarAristaDirigida(vdestino, vorigen);
}

void Grafo::insertarAristaNoDirigida(string vorigen, string vdestino, int peso){
    insertarAristaDirigida(vorigen, vdestino, peso);
    insertarAristaDirigida(vdestino, vorigen, peso);
}

//Puede eliminar una arista dirigida o no dirigida
int Grafo::eliminarArista(string vi, string vj){
    Nodo *ver1, *ver2;
    ver1 = ver2 = iniGrafo;

    //la condición del for podría mejorarse para que el apuntador ver1 no recorra toda la lista
    for (int i = 0; i < numVertices; i++) {
        if (ver1->vertice == vi || ver1->vertice == vj) {
            Nodo *viejo = ver2->ligaAdelante;
            while (viejo->vertice != vi && viejo->vertice != vj) {
                viejo = viejo->ligaAdelante;
                ver2 = ver2->ligaAdelante;
                if (viejo == NULL) break;
            }

            //eliminando la conexión
            if (viejo != NULL)
                ver2->ligaAdelante = viejo->ligaAdelante;
            delete viejo;
        }

        ver1 = ver1->ligaAbajo;
        ver2 = ver1;
    }
    return 0;
}

void Grafo::imprimir(){
    Nodo *vertices = iniGrafo, *conexiones;
    while (vertices != NULL) {
        //Imprime el vértice
        cout << vertices->vertice << "--";
        conexiones = vertices->ligaAdelante;
        while (conexiones != NULL) {
            //Imprime las conexiones del vértice actual
            cout << "->" << conexiones->vertice << "|" << conexiones->pesoArista;
            conexiones = conexiones->ligaAdelante;
        }

        cout << '\n';
        conexiones = vertices->ligaAbajo;
        vertices = vertices->ligaAbajo;
    }
}

Grafo::~Grafo(){ cout << "Se destruye el grafo" << endl; }
