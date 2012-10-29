#ifndef RAGDOLL_HH
#define RAGDOLL_HH
#include "Gato.hh"

class Ragdoll:
	public Gato
{
private:
	Gato* g1;
	Gato* g2;
	bool mul;
public:
	Ragdoll(int peso, QRect rectangulo, int X, int Y):peso(peso), rectangulo(rectangulo), X(X), Y(Y)
	{
		mul=false;
	}
	~Ragdoll(){}

	void Multi()
	{
		if (mul == false)
		{
			QRect r1 = (X, Y, 30, 30);
			QRect r2 = (X, Y, 30, 30);
			g1 = new Gato(10, r1, X, Y);
			g2 = new Gato(10, r2, X, Y);
			g1.setVel(velocidad);
			g2.setVel(velocidad);
			g1.setAng(angulo+10);
			g2.setAng(angulo-10);
			mul = true;
		}
	}
	
};

#endif