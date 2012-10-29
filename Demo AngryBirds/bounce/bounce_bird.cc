#include <iostream>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "bounce_bird.h"

BounceBird::BounceBird(QGraphicsItem* parent, QGraphicsScene* scene)
	: QGraphicsItem(parent,scene),
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

void BounceBird::advance(int /* phase*/)
{
  if(avanzar == true)
  { 
    timet += 0.05;
    Vx=velocidad*cos(angulo);
    Vy=velocidad*sin(angulo);
    double xx=20+Vx*timet;
    double yy=500+Vy*timet+0.5*g*pow(timet,2);
    this->setPos(xx, yy);

    /*if (x() + m_dx + (boundingRect().width() * 0.5) > m_scene->width()) 
      m_dx = -std::abs(m_dx);
    else 
      if (x() + m_dx - (boundingRect().width() * 0.5) < 0.0) 
        m_dx = std::abs(m_dx);
    if (y() + m_dy + (boundingRect().height() * 0.5) > m_scene->height()) 
      m_dy = -std::abs(m_dy);
    else 
      if (y() + m_dy - (boundingRect().width() * 0.5) < 0.0) 
        m_dy = std::abs(m_dy);
    this->setPos(x() + m_dx, y() + m_dy);*/

  }
  // std::cout << "in advance" << std::endl;
}

bool BounceBird::getadvance()
{
  return avanzar;
}

QRectF BounceBird::boundingRect() const
{
  // return QRectF(-16.0,-16.0,32.0,32.0);
  return m_pic->boundingRect();
}

void BounceBird::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // QPixmap pmap("bird.png");
  // painter->drawEllipse(this->boundingRect());
  //m_pic->setPos(200,500);
  m_pic->setPos(this->pos());
  m_pic2->setPos(0, 480);
}

QPainterPath BounceBird::shape() const
{
  QPainterPath p;
  p.addEllipse(boundingRect());
  // p.addPixmap(m_pic);
  // std::cout << "in paint\n";
  return p;
}

 void BounceBird::mousePressEvent(QGraphicsSceneMouseEvent *event)
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
