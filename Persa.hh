#ifndef PERSA_HH
#define PERSA_HH
#include "Gato.hh"

class Persa:
	public Gato
{
private:
	Objeto* BolaPelo=new Objeto(10, QRect Rect);
	double Vxb=0;
	double Vyb=0;
	int Xb=X;
	int Yb=Y;
	double timeb=0;
public:
	Persa(int peso, QRect rectangulo, int X, int Y):peso(peso), rectangulo(rectangulo), X(X), Y(Y){}
	~Persa();
	void moverBola()
	{
		Vxb=(1/8)*Vx*cos(0);
		Xb=Xb+Vxb*timet;
		Yb=Yb+Vyb*timet+0.5*g*pow(timet,2);
	}

	int Soltar()
	{
		BolaPelo.show();
		return true;
	}

	void comprobar()
	{
		if (t.isActive==true)
		{
			mover();
			moverBola();
			timet+=0.013;
			timeb+=0.013;
		}
	}

	/* data */
};