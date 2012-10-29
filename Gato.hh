#ifndef GATO_HH
#define GATO_HH
#include "Objeto.hh"

class Gato:
	public Objeto
{
protected:
	int X;
	int Y;
	int X0=10;
	int Y0=10;
	double velocidad;
	double angulo;
	double Vx=0;
	double Vy=0;
	double timet=0;
	QTimer t.start(13);
public:
	Gato(int peso, QRect rectangulo, int X, int Y):peso(peso), rectangulo(rectangulo), X(X), Y(Y){}
	~Gato(){}
	void setVel(double vel)
	{
		velocidad=vel;
	}
	void setAng(double ang)
	{
		angulo=ang;
	}
	void disparar()
	{
		vector<double> vals=m.CalcTiro(X0, Y0, X, Y);
		velocidad=vals[0];
		angulo=vals[1];
	}
	void mover()
	{
		Vx=velocidad*cos(angulo);
		Vy=velocidad*sen(angulo);
		X=X+Vx*timet;
		Y=Y+Vy*timet+0.5*g*pow(timet,2);
	}
	virtual void comprobar()
	{
		if (t.isActive==true)
		{
			mover();
			timet+=0.013;
		}
	}
};

#endif