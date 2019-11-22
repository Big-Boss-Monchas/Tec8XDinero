#pragma once

class Vertex3d
{

private:
	double x;
	double y;
	double z;

public:
	Vertex3d();
	Vertex3d(double _x, double _y, double _z);
	double getX();
	double getY();
	double getZ();
	void setX(double _x);
	void setY(double _y);
	void setZ(double _z);
	void setXYZ(double _x, double _y, double _z);
	void moveVertex3d(double _x, double _y, double _z);
	~Vertex3d();
};