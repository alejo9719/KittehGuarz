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

{
protected:
	QRect rectangulo;
	int peso;
	QImage imagen;
	float g=9.8;
public:
	Objeto(int peso, QRect rectangulo):peso(peso), rectangulo(rectangulo){}
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
};

#endif