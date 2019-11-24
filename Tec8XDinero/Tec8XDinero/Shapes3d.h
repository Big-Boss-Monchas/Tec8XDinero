#pragma once

#include "Vertex3d.h"

class Shapes3d
{

protected:

	Vertex3d origin;
	int numColor;
	int numVertex;
	double perimeter;
	double area;
	double volume;

public:

	void setOrigin(double _x, double _y, double _z);
	void setNumVertex(int _numVertex);
	Vertex3d getOrigin();
	int getNumColor();
	int getNumVertex();
	double getVolume();
	~Shapes3d();
};

