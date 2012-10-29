#ifndef OBJETO_HH
#define OBJETO_HH
#include <iostream>
#include <stdlib>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <math>

class Objeto
	: public QGraphicsItem

{
protected:
	QRect rectangulo;
	int peso;
	QImage imagen;
	float g;
	double m_dx;
    double m_dy;
    QGraphicsScene* const m_scene;

  	QGraphicsPixmapItem*  m_pic;
public:
	Objeto(QGraphicsItem* parent, QGraphicsScene* scene, int peso, QRect rectangulo)
		:peso(peso), rectangulo(rectangulo)
		QGraphicsItem(parent,scene),
	    m_dx(1.0), m_dy(1.0),
	    m_scene(scene),
	    m_pic(0),
	{
	  velocidad = 100;
	  angulo = -0.76;
	  g = 9.8;
	  avanzar=false;
	  std::cout << "Construction of BounceBird\n";
	  QPixmap pmap("bird.png");
	  m_pic = m_scene->addPixmap(pmap); 
	  this->setPos(20,500);
	}
	int getPeso()
	{
		return peso;
	}
	QRect getRect()
	{
		return rectangulo;
	}
	void show()
	{
		imagen.show();
	}
	QRectF boundingRect() const
	{
		return m_pic->boundingRect();
	}
	QPainterPath shape() const
	{
		QPainterPath p;
	    p.addEllipse(boundingRect());
	    // p.addPixmap(m_pic);
	    // std::cout << "in paint\n";
	    return p;
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
};

#endif