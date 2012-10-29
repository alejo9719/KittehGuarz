#ifndef BURMES_HH
#define BURMES_HH
#include "Gato.hh"

class Burmes:
	public Gato
{
public:
	Burmes(int peso, QRect rectangulo, int X, int Y):peso(peso), rectangulo(rectangulo), X(X), Y(Y){}
	~Burmes(){}
	void acelerar()
	{
		Vx*=2;
		Vy*=2;
	}
};

#endif