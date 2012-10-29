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
	QGraphicsPixmapItem*  m_pic2;
public:
	Gato(QGraphicsItem* parent, QGraphicsScene* scene, int peso, QRect rectangulo, int X, int Y)
		:peso(peso), rectangulo(rectangulo), X(X), Y(Y),
		QGraphicsItem(parent,scene),
	    m_dx(1.0), m_dy(1.0),
	    m_scene(scene),
	    m_pic(0),
	    m_pic2(0)
	{
		velocidad = 100;
	    angulo = -0.76;
	    g = 9.8;
	    avanzar=false;
	    std::cout << "Construction of BounceBird\n";
	    QPixmap pmap("bird.png");
	    QPixmap pmap2("Resortera.png");
	    m_pic = m_scene->addPixmap(pmap); 
	    m_pic2 = m_scene->addPixmap(pmap2);
	    this->setPos(20,500);
	}
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