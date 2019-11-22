#include "PrismRectangular.h"

#define VERTEXNUMBER 8
#define FACESNUMBER 6

PrismRectangular::PrismRectangular()
	{
		setOrigin(0, 0, 0);
		setColor(1);
		setBase(1);
		setLength(1);
		setHeight(1);
		setNumVertex(VERTEXNUMBER);
		calculateVertex();
	}

PrismRectangular::PrismRectangular(double _x, double _y, double _z)
	{
		setOrigin(_x, _y, _z);
		setColor(1);
		setBase(1);
		setLength(1);
		setHeight(1);
		setNumVertex(VERTEXNUMBER);
		calculateVertex();
	}

PrismRectangular::PrismRectangular(double _x, double _y, double _z, double _base, double _length, double _height)
	{
		setOrigin(_x, _y, _z);
		setColor(1);
		setBase(_base);
		setLength(_length);
		setHeight(_height);
		setNumVertex(VERTEXNUMBER);
		calculateVertex();
	}

PrismRectangular::PrismRectangular(double _x, double _y, double _z, double _base, double _length, double _height, int _col)
	{
		setOrigin(_x, _y, _z);
		setColor(_col);
		setBase(_base);
		setLength(_length);
		setHeight(_height);
		setNumVertex(VERTEXNUMBER);
		calculateVertex();
	}

PrismRectangular::PrismRectangular(PrismRectangular& _prismrectangular)
	{
		Vertex3d pos = _prismrectangular.getOrigin();
		setOrigin(pos.getX(), pos.getY(), pos.getZ());
		setColor(_prismrectangular.getNumColor());
		setBase(_prismrectangular.getBase());
		setLength(_prismrectangular.getLength());
		setHeight(_prismrectangular.getHeight());
		setNumVertex(VERTEXNUMBER);
		calculateVertex();
	}

	void PrismRectangular::setColor(int _colorNumber)
	{
		numColor = _colorNumber;
		switch (_colorNumber)
		{
		case 1:
			colors[0].setRGB(1.0, 1.0, 0.0);	colors[1].setRGB(0.0, 1.0, 1.0);
			colors[2].setRGB(1.0, 0.0, 1.0);	colors[3].setRGB(1.0, 0.0, 0.0);
			colors[4].setRGB(0.0, 1.0, 0.0);	colors[5].setRGB(0.0, 0.0, 1.0);
			break;
		case 2:
			colors[0].setRGB(1.0, 0.0, 1.0);	colors[1].setRGB(1.0, 0.0, 0.0);
			colors[2].setRGB(0.0, 0.0, 0.75);	colors[3].setRGB(0.0, 1.0, 1.0);
			colors[4].setRGB(1.0, 0.75, 0.75);	colors[5].setRGB(0.75, 1.0, 1.0);
			break;
		case 3:
			colors[0].setRGB(0.5, 0.5, 0.5);	colors[1].setRGB(0.9, 0.8, 0.7);
			colors[2].setRGB(0.6, 0.5, 0.4);	colors[3].setRGB(1.0, 1.0, 0.75);
			colors[4].setRGB(0.75, 1.0, 1.0);	colors[5].setRGB(1.0, 0.75, 1.0);
			break;
		case 4:
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(1.0, 0.0, 0.0); }
			break;
		case 5:
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(0.0, 1.0, 0.0); }
			break;
		case 6:
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(0.0, 0.0, 1.0); }
			break;
		case 7:
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(1.0, 1.0, 0.0); }
			break;
		case 8:
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(1.0, 0.0, 1.0); }
			break;
		case 9:
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(0.0, 1.0, 1.0); }
			break;
		default:
			numColor = 0;
			for (int i = 0; i < FACESNUMBER; i++) { colors[i].setRGB(0.0, 0.0, 0.0); }
			break;
		}
	}

	void PrismRectangular::setBase(double _base)
	{
		if (_base > 0) { base = _base; }
		else { setBase(1); }
		assignProperties();
	}

	void PrismRectangular::setLength(double _length)
	{
		if (_length > 0) { length = _length; }
		else { setLength(1); }
		assignProperties();
	}

	void PrismRectangular::setHeight(double _height)
	{
		if (_height > 0) { height = _height; }
		else { setHeight(1); }
		assignProperties();
	}

	void PrismRectangular::assignProperties()
	{
		text[0] = Texture3d((char*)"Textures/1.bmp");
		text[1] = Texture3d((char*)"Textures/2.bmp");
		text[2] = Texture3d((char*)"Textures/3.bmp");
		text[3] = Texture3d((char*)"Textures/4.bmp");
		text[4] = Texture3d((char*)"Textures/5.bmp");
		text[5] = Texture3d((char*)"Textures/6.bmp");

		volume = calculateVolume();
		calculateVertex();
	}

	double PrismRectangular::getBase()	{ return base; }
	double PrismRectangular::getLength()  { return length; }
	double PrismRectangular::getHeight()	{ return height; }

	double PrismRectangular::calculateVolume() { return (getBase() * getLength() * getHeight()); }

	void PrismRectangular::setVertex(double _x1, double _x2, double _y1, double _y2, double _z1, double _z2)
	{
		vertexPos[0].setXYZ(_x1, _y1, _z1);
		vertexPos[1].setXYZ(_x2, _y1, _z1);
		vertexPos[2].setXYZ(_x2, _y2, _z1);
		vertexPos[3].setXYZ(_x1, _y2, _z1);
		vertexPos[4].setXYZ(_x1, _y1, _z2);
		vertexPos[5].setXYZ(_x2, _y1, _z2);
		vertexPos[6].setXYZ(_x2, _y2, _z2);
		vertexPos[7].setXYZ(_x1, _y2, _z2);

		vertex[0] = _x1;		vertex[1] = _y1;		vertex[2] = _z1;
		vertex[3] = _x2;		vertex[4] = _y2;		vertex[5] = _z2;

		for (size_t i = 0; i < FACESNUMBER; i++)
		{
			text[i].loadTexture();
		}
	}

	void PrismRectangular::calculateVertex()
	{
		double x1 = origin.getX() - (getBase() / 2);
		double x2 = x1 + getBase();
		double y1 = origin.getY() - (getLength() / 2);
		double y2 = y1 + getLength();
		double z1 = origin.getZ();
		double z2 = z1 + getHeight();
		setVertex(x1, x2, y1, y2, z1, z2);
	}

	void PrismRectangular::drawFigure()
	{
		Color aux_color = colors[0];
		glColor3f(aux_color.getR(), aux_color.getG(), aux_color.getB());
		glBegin(GL_POLYGON);
		glVertex3f(vertexPos[0].getX(), vertexPos[0].getY(), vertexPos[0].getZ());
		glVertex3f(vertexPos[1].getX(), vertexPos[1].getY(), vertexPos[1].getZ());
		glVertex3f(vertexPos[2].getX(), vertexPos[2].getY(), vertexPos[2].getZ());
		glVertex3f(vertexPos[3].getX(), vertexPos[3].getY(), vertexPos[3].getZ());
		glEnd();

		aux_color = colors[1];
		glColor3f(aux_color.getR(), aux_color.getG(), aux_color.getB());
		glBegin(GL_POLYGON);
		glVertex3f(vertexPos[0].getX(), vertexPos[0].getY(), vertexPos[0].getZ());
		glVertex3f(vertexPos[1].getX(), vertexPos[1].getY(), vertexPos[1].getZ());
		glVertex3f(vertexPos[5].getX(), vertexPos[5].getY(), vertexPos[5].getZ());
		glVertex3f(vertexPos[4].getX(), vertexPos[4].getY(), vertexPos[4].getZ());
		glEnd();

		aux_color = colors[2];
		glColor3f(aux_color.getR(), aux_color.getG(), aux_color.getB());
		glBegin(GL_POLYGON);
		glVertex3f(vertexPos[1].getX(), vertexPos[1].getY(), vertexPos[1].getZ());
		glVertex3f(vertexPos[2].getX(), vertexPos[2].getY(), vertexPos[2].getZ());
		glVertex3f(vertexPos[6].getX(), vertexPos[6].getY(), vertexPos[6].getZ());
		glVertex3f(vertexPos[5].getX(), vertexPos[5].getY(), vertexPos[5].getZ());
		glEnd();

		aux_color = colors[3];
		glColor3f(aux_color.getR(), aux_color.getG(), aux_color.getB());
		glBegin(GL_POLYGON);
		glVertex3f(vertexPos[2].getX(), vertexPos[2].getY(), vertexPos[2].getZ());
		glVertex3f(vertexPos[3].getX(), vertexPos[3].getY(), vertexPos[3].getZ());
		glVertex3f(vertexPos[7].getX(), vertexPos[7].getY(), vertexPos[7].getZ());
		glVertex3f(vertexPos[6].getX(), vertexPos[6].getY(), vertexPos[6].getZ());
		glEnd();

		aux_color = colors[4];
		glColor3f(aux_color.getR(), aux_color.getG(), aux_color.getB());
		glBegin(GL_POLYGON);
		glVertex3f(vertexPos[3].getX(), vertexPos[3].getY(), vertexPos[3].getZ());
		glVertex3f(vertexPos[0].getX(), vertexPos[0].getY(), vertexPos[0].getZ());
		glVertex3f(vertexPos[4].getX(), vertexPos[4].getY(), vertexPos[4].getZ());
		glVertex3f(vertexPos[7].getX(), vertexPos[7].getY(), vertexPos[7].getZ());
		glEnd();

		aux_color = colors[5];
		glColor3f(aux_color.getR(), aux_color.getG(), aux_color.getB());
		glBegin(GL_POLYGON);
		glVertex3f(vertexPos[4].getX(), vertexPos[4].getY(), vertexPos[4].getZ());
		glVertex3f(vertexPos[5].getX(), vertexPos[5].getY(), vertexPos[5].getZ());
		glVertex3f(vertexPos[6].getX(), vertexPos[6].getY(), vertexPos[6].getZ());
		glVertex3f(vertexPos[7].getX(), vertexPos[7].getY(), vertexPos[7].getZ());
		glEnd();
	}

	void PrismRectangular::drawFigureTable()
	{
		glEnable(GL_TEXTURE_2D);

		float x0 = vertex[0], y0 = vertex[1], z0 = vertex[2], x1 = vertex[3], y1 = vertex[4], z1 = vertex[5];
		float face[6][4][3] = { { {x0, y0, z0}, {x1, y0, z0}, {x1, y1, z0}, {x0, y1, z0} },
		  {{x0, y1, z1}, {x1, y1, z1}, {x1, y0, z1}, {x0, y0, z1}},    //back
		  {{x1, y0, z0}, {x1, y0, z1}, {x1, y1, z1}, {x1, y1, z0}},    //right
		  {{x0, y0, z0}, {x0, y1, z0}, {x0, y1, z1}, {x0, y0, z1}},    //left
		  {{x0, y1, z0}, {x1, y1, z0}, {x1, y1, z1}, {x0, y1, z1}},    //top
		  {{x0, y0, z0}, {x0, y0, z1}, {x1, y0, z1}, {x1, y0, z0}}    //bottom
		};

		for (int i = 0; i < 6; ++i) {
			//draw cube with texture images
			text[i].useTexture();
			glBindTexture(GL_TEXTURE_2D, text[i].texture);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0, 1.0); glVertex3fv(face[i][0]);
			glTexCoord2f(0.0, 1.0); glVertex3fv(face[i][1]);
			glTexCoord2f(-1.0, 0.0); glVertex3fv(face[i][2]);
			glTexCoord2f(0.0, 0.0); glVertex3fv(face[i][3]);
			glEnd();
		}

		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}

	void PrismRectangular::moveFigure(double _x, double _y, double _z)
	{
		origin.moveVertex3d(_x, _y, _z);
		calculateVertex();
	}

	void PrismRectangular::scaleFigure(double factor)
	{
		setBase(factor * getBase());
		setLength(factor * getLength());
		setHeight(factor * getHeight());
		calculateVertex();
	}
