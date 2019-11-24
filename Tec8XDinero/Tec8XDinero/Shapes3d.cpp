#include "Shapes3d.h"

// ESTABLECE EL ORIGEN DE LA FIGURA
void Shapes3d::setOrigin(double _x, double _y, double _z)
{
	origin.setX(_x);
	origin.setY(_y);
	origin.setZ(_z);
}

Vertex3d Shapes3d::getOrigin() { return origin; }
int Shapes3d::getNumColor() { return numColor; }
int Shapes3d::getNumVertex() { return numVertex; }
double Shapes3d::getVolume() { return volume; }
void Shapes3d::setNumVertex(int _numVertex) { numVertex = _numVertex; }

Shapes3d::~Shapes3d()
{
}