#include "Vertex3d.h"

Vertex3d::Vertex3d()
{
	setX(0);
	setY(0);
	setZ(0);
}

Vertex3d::Vertex3d(double _x, double _y, double _z)
{
	setX(_x);
	setY(_y);
	setZ(_z);
}

// GETTERS & SETTERS --------------------
double Vertex3d::getX()
{
	return x;
}

double Vertex3d::getY()
{
	return y;
}

double Vertex3d::getZ()
{
	return z;
}

void Vertex3d::setX(double _x)
{
	x = _x;
}

void Vertex3d::setY(double _y)
{
	y = _y;
}

void Vertex3d::setZ(double _z)
{
	z = _z;
}

// METODO ASIGNA LAS TRES COORDENADAS A LA VEZ
void Vertex3d::setXYZ(double _x, double _y, double _z)
{
	setX(_x);
	setY(_y);
	setZ(_z);
}

// METODO PARA MOVER LA COORDENADA DEL VERTICE
void Vertex3d::moveVertex3d(double _x, double _y, double _z)
{
	setX(getX() + _x);
	setY(getY() + _y);
	setZ(getZ() + _z);
}

Vertex3d::~Vertex3d()
{
}