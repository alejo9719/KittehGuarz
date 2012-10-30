#ifndef GATO_HH
#define GATO_HH
#include "Objeto.hh"

class Gato:
	public Objeto
{
protected:
	int X;
	int Y;
	int X0;
	int Y0;
	double velocidad;
	double angulo;
	double Vx;
	double Vy;
	double timet;
	bool avanzar;
	//QTimer t.start(13);
	QGraphicsPixmapItem*  m_pic2;
public:
	Gato(QGraphicsItem* parent, QGraphicsScene* scene, int peso, int Xx, int Yy)
		:Objeto(parent, scene, peso),
		X0(Xx), Y0(Yy)
	{
		timet=0;
		velocidad = 100;
	    angulo = -0.76;
	    g = 9.8;
	    avanzar=false;
	    std::cout << "Construction of BounceBird\n";
	    QPixmap pmap("gato3.png");
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

	void paint(QPainter *painter, 
    	const QStyleOptionGraphicsItem *option, QWidget *widget)
	{
	  // QPixmap pmap("bird.png");
	  // painter->drawEllipse(this->boundingRect());
	  //m_pic->setPos(200,500);
	  m_pic->setPos(this->pos());
	  m_pic2->setPos(0, 480);
	}

	/*void disparar()
	{
		vector<double> vals=m.CalcTiro(X0, Y0, X, Y);
		velocidad=vals[0];
		angulo=vals[1];
	}*/
	void advance(int /*phase*/)
	{
		if(avanzar == true)
		{
			timet += 0.05;
			Vx=velocidad*cos(angulo);
			Vy=velocidad*sin(angulo);
			double xx=X0+Vx*timet;
			double yy=Y0+Vy*timet+0.5*g*pow(timet,2);
			this->setPos(xx, yy);
		}
	}
	/*virtual void comprobar()
	{
		if (t.isActive==true)
		{
			advance();
			timet+=0.05;
		}
	}*/
	 void mousePressEvent(QGraphicsSceneMouseEvent *event)
	 {
	     if (event->button() == Qt::LeftButton) {
	        avanzar=true;
	        std::cout << "Ahhhh!\n";
	        //this->advance(100);
	        //m_pic->setPos(this->pos());
	     } else {
	         // pass on other buttons to base class
	        QGraphicsItem::mousePressEvent(event);
	     }
	 }
};

#endif