/*Nodo de la lista ligada 
con un solo campo*/
#ifndef NODO_H
#define NODO_H

class Nodo{
	public:
		Nodo(int dato);
		~Nodo();
		Nodo *liga;
		int dato;
};

#endif
