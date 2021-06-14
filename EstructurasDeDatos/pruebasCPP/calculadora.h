#ifndef CALCULADORA_H
#define CALCULADORA_H

class calculadora{
	public:
		calculadora(int id);
		~calculadora();
		int sumar(int a, int b);
		int restar(int a, int b);
		int multiplicar(int a, int b);
		float dividir(int a, int b);
	private:
		int id;
};

#endif
