#pragma once
#include "Shapes3d.h"
#include "Color.h"
#include "Texture3d.h"

class PrismRectangular : public Shapes3d
{
private:

	// ------- CLASE HIJA / PRISM RECTANGULAR -----------------------------
	Texture3d text[6];
	Vertex3d vertexPos[8];		// NUMERO DE VERTICES
	Color colors[6];			// NUMERO DE COLORES DE CARAS
	double base;				// DIMENSION DEL LADO DE BASE
	double length;				// DIMENSION DEL ANCHO
	double height;				// DIMENSION DE ALTURA DE PRISMA
	double vertex[6];

public:
	PrismRectangular();
	PrismRectangular(double _x, double _y, double _z);
	PrismRectangular(double _x, double _y, double _z, double _base, double _length, double _height);
	PrismRectangular(double _x, double _y, double _z, double _base, double _length, double _height, int _col);
	PrismRectangular(PrismRectangular& _prismRectangular);
	void setColor(int _colorNumber);
	void setBase(double _base);
	void setLength(double _length);
	void setHeight(double _height);
	void assignProperties();
	double getBase();
	double getLength();
	double getHeight();
	double calculateVolume();
	void setVertex(double _x1, double _x2, double _y1, double _y2, double _z1, double _z2);
	void calculateVertex();
	void drawFigure();
	void drawFigureTable();
	void moveFigure(double _x, double _y, double _z);
	void scaleFigure(double _factor);
};

