#include "Color.h"

Color::Color()
{
	colorR = 1.0;
	colorG = 1.0;
	colorB = 1.0;
}

Color::Color(float _r, float _g, float _b)
{
	setR(_r);
	setG(_g);
	setB(_b);
}

float Color::getR()
{
	return colorR;
}

float Color::getG()
{
	return colorG;
}

float Color::getB()
{
	return colorB;
}

// SI EL VALOR ENVIADO ES MENOR A 0 O MAYOR A 1 
// LE ES ASIGNADO EL VALOR DE 1.0 POR DEFECTO
void  Color::setR(float _r)
{
	if (_r >= 0 && _r <= 1)
	{
		colorR = _r;
	}
	else
	{
		colorR = 1.0;
	}
}

void Color::setG(float _g)
{
	if (_g >= 0 && _g <= 1)
	{
		colorG = _g;
	}
	else
	{
		colorG = 1.0;
	}
}

void Color::setB(float _b)
{
	if (_b >= 0 && _b <= 1)
	{
		colorB = _b;
	}
	else
	{
		colorB = 1.0;
	}
}

// METODO DE ASIGNACION DE LOS 3 COLORES A LA VEZ
void Color::setRGB(float _r, float _g, float _b)
{
	setR(_r);
	setG(_g);
	setB(_b);
}

Color::~Color()
{
}