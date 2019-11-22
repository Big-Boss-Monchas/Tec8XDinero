#pragma once

class Color
{

private:
	float colorR;
	float colorG;
	float colorB;

public:
	Color();
	Color(float _r, float _g, float _b);
	float getR();
	float getG();
	float getB();
	void setR(float _r);
	void setG(float _g);
	void setB(float _b);
	void setRGB(float _r, float _g, float _b);
	~Color();
};