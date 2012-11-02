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
	int poder;
	int countiempo;
	double velocidad;
	double angulo;
	double Vx;
	double Vy;
	double xx;
	double yy;
	double timet;
	bool avanzar;
	QLineF LineOne;
	QLineF LineTwo;
	//QTimer t.start(13);
	QGraphicsPixmapItem*  m_pic2;
public:
	Gato(QGraphicsItem* parent, QGraphicsScene* scene, int peso, int Xx, int Yy)
		:Objeto(parent, scene, peso),
		X0(Xx), Y0(Yy)
	{
		countiempo=0;
		timet=0;
		velocidad = 100;
	    angulo = -0.75;
	    g = 9.8;
	    avanzar=false;
	    std::cout << "KITTEH GUARZ\n";
	    QPixmap pmap("gato4.png");
	    QPixmap pmap2("Resortera.png");
	    m_pic = m_scene->addPixmap(pmap); 
	    m_pic2 = m_scene->addPixmap(pmap2);
	    this->setPos(80,500);
	    poder=0;
	}
	~Gato(){}
	QLineF generateLine(QPointF startPos,QPointF endPos)
	{
    	if(startPos.x() <endPos.x())
        	return QLineF(startPos,endPos);
    	else
        	return QLineF(endPos,startPos);
	}
	void setVel(double vel)
	{
		velocidad=vel;
	}
	void setAng(double ang)
	{
		angulo=ang;
	}
	void setIMG(QPixmap pmap)
	{
		m_scene->removeItem(m_pic);
		m_pic = m_scene->addPixmap(pmap);
	}

	void paint(QPainter *painter, 
    	const QStyleOptionGraphicsItem *option, QWidget *widget)
	{
	  // QPixmap pmap("bird.png");
	  // painter->drawEllipse(this->boundingRect());
	  //m_pic->setPos(200,500);
	  m_pic->setPos(this->pos());
	  m_pic2->setPos(60, 480);
	  //m_scene->removeLine(asdasdasd);
	  LineOne=generateLine(m_pic2->pos(), m_pic->pos());
	  //m_scene->addLine(asdasdasd);
	}

	/*void disparar()
	{
		vector<double> vals=m.CalcTiro(X0, Y0, X, Y);
		velocidad=vals[0];
		angulo=vals[1];
	}*/
	virtual void advance(int /*phase*/)
	{
		//if(avanzar == true && velocidad>15)
		if(avanzar == true)
		{
			Vx=velocidad*cos(angulo);
			Vy=velocidad*sin(angulo);
			std::cout<<poder<<std::endl;
			timet += 0.05;
			xx=X0+Vx*timet;
			yy=Y0+Vy*timet+0.5*g*pow(timet,2);
			this->setPos(xx, yy);
			if (y() + m_dy + (boundingRect().height() * 0.5) > (m_scene->height())-40)
			{
      			velocidad=velocidad/1.3;
      			X0=xx;
      			Y0=yy;
      			timet=0;
      		}
		}
		if (avanzar==true && velocidad<=10)
		{
			countiempo++;
			if (countiempo>=200)
			{
				m_scene->removeItem(m_pic);
				this->~Gato();
				//this->setPos(1000,770);
			}
		}
	}
	virtual void power()
	{
		std::cout<<"";
	}
	/*virtual void comprobar()
	{
		if (t.isActive==true)
		{
			advance();
			timet+=0.05;
		}
	}*/
	void avnz()
	{
		avanzar=true;
	}
	void mousePressEvent(QGraphicsSceneMouseEvent *event)
	{
	    if (event->button() == Qt::LeftButton) {
	     	/*int xg=event->pos().x();
	     	int yg=event->pos().y();
	     	this->setPos(xg, yg);
	     	X0=event->pos().x();
	     	Y0=event->pos().y();*/
	        avnz();
	        poder++;
	        //this->advance(100);
	        //m_pic->setPos(this->pos());
	        if (poder==2)
	        {
	        	std::cout<<"AHHHHHH!";
	        	power();
	        }
	    } else {
	         // pass on other buttons to base class
	        QGraphicsItem::mousePressEvent(event);
	    }
	}
};

#endif