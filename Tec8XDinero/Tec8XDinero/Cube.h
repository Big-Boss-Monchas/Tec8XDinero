#pragma once

#include "Color.h"
#include "Shapes3d.h"
#include "Texture3d.h"

#define VERTEXNUMBER 8
#define FACESNUMBER 6

class Cube : public Shapes3d
{

private:
	Texture3d text[6];
	Vertex3d vertexPos[8];			// NUMERO DE VERTICES
	Color colors[6];				// NUMERO DE COLORES DE CARAS
	double dimension;
	double vertex[6];

public:

	Cube();
	Cube(double _x, double _y, double _z);
	Cube(double _x, double _y, double _z, double _dim);
	Cube(double _x, double _y, double _z, double _dim, int _col);
	Cube(Cube& _cube);
	void setVertex(double _x1, double _x2, double _y1,
		double _y2, double _z1, double _z2);
	void setColor(int _colorNumber);
	void loadVertex();
	void setVertexposX(double _pos, int _index);
	void setVertexposY(double _pos, int _index);
	void setVertexposZ(double _pos, int _index);
	void setDimension(double _dimension);
	double getDimension();
	Vertex3d getVertexPos(int _num);
	void calculateVertex();
	void assignProperties();
	double calculateVolume();
	void drawFigure();
	void drawFigureDice();
	void moveFigure(double _x, double _y, double _z);
	void scaleFigure(double _factor);
	void rotateFigureX(double _angle);
	void rotateFigureY(double _angle);
	void rotateFigureZ(double _angle);
	~Cube();
};

