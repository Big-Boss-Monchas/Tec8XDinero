/*
* GRAFICACION - UNIDAD 3
* INTEGRANTES:
* IVAN FRANCO DELGADO
* JESUS EDUARDO SOSA DIAZ
* JOSUE TORRES AVALOS
*/

#include <GL/glut.h>
#include "Cube.h"
#include "PrismRectangular.h"
#include <ctime>
#include <cstdlib>

#define HEIGHT 720
#define WIDTH 1280

float float_rand(float, float);
void calculateVertex(void);
bool collision(void);

Cube cubito(5, 5, 7, 5, 5);
PrismRectangular mesita(0, 0, -2, 15, 15, 2);
float anglex = 0.0, angley = 0.0, anglez = 0.0;
bool rotate = false, roll = false;
float alto = 7.5, increment = 0.0;
bool zero = false;
float xmove = 0.0, ymove = 0.0, zmove = 0.0;
float anglerandomaux = 7.0, anglerandom = 0.0;
float moverandomaux = 5.0, moverandom = 0.0;
bool start = true, end = false;

void initializer(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // COLOR CANVAS
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

void idle_cb(int Value) {
	roll = true;
	
	anglex += anglerandom;
	//angley += anglerandom;
	//anglez += anglerandom;
	if (anglex > 360)
	{
		anglex -= 360;
		//angley -= 360;
		//anglez -= 360;
	}
	xmove -= moverandom;
	ymove -= moverandom;
	zmove -= moverandom;
	collision();
	glutPostRedisplay();
	if (collision())
	{
		roll = false;
		glutTimerFunc(1000, NULL, 0);

		end = true;
		return;
	}
	glutTimerFunc(10, idle_cb, 0);
}

bool collision() {
	for (size_t i = 0; i < 8; i++)
	{
		if (cubito.getVertexPos(i).getZ() < 0)
		{
			return true;
		}
	}
	return false;
}

void calculateVertex(void) {
	Vertex3d aux_pos[8];
	Vertex3d temp;
	for (size_t i = 0; i < 8; i++)
	{
		aux_pos[i] = cubito.getVertexPos(i);
	}
	/*for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = i+1; j < 8; j++)
		{
			if (aux_pos[j].getZ() < aux_pos[i].getZ())
			{
				temp = aux_pos[i];
				aux_pos[i] = aux_pos[j];
				aux_pos[j] = temp;
			}
		}
	}*/
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "lower vertex " << aux_pos[i].getZ() << std::endl;

	}
}

void displayScreen(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(150, 150, 300, 300);

	if (start)
	{
		glRotatef(-45, 1.0, 0.0, 0.0);
		glRotatef(45, 0.0, 0.0, 1.0);
		start = false;
	}

	mesita.drawFigureTable();
	glPushMatrix();

	if (roll && !end)
	{
		double x1 = cubito.getOrigin().getX(), y1 = cubito.getOrigin().getY(), z1 = cubito.getOrigin().getZ();
		//glTranslatef(x1 , y1, z1);
		
		//glRotatef(anglex, 1.0, 0.0, 0.0);
		//glRotatef(angley, 0.0, 1.0, 0.0);
		//glRotatef(anglez, 0.0, 0.0, 1.0);
		cubito.rotateFigureX(anglex);
		//cubito.rotateFigureY(angley);
		//cubito.rotateFigureZ(anglez);
		//glTranslatef(-x1, -y1, -z1);
		//glTranslatef(xmove, ymove, zmove);
		cubito.setOrigin(x1 - moverandom, y1- moverandom, z1 - moverandom);
		cubito.moveFigure(moverandomaux, moverandomaux, moverandomaux);

		increment += moverandom;
	}
	
	cubito.drawFigureDice();
	glPopMatrix();

	/*
		glPushMatrix();
		if (rotate)
		{
			glRotatef(anglex, 1.0, 0.0, 0.0);
			glRotatef(angley, 0.0, 1.0, 0.0);
			glRotatef(anglez, 0.0, 0.0, 1.0);
			rotate = false;
		}
		cubito.drawFigureDice();
		glPopMatrix();
		*/
	glutSwapBuffers();
}

void teclado_cb(GLubyte key, GLint x, GLint y) {
	switch (key) {
	case 27:
		exit(1);
		break;
	case 'x':
		// aqu  se procesar a la tecla <x>
		//glRotatef(5.0, 1.0, 0.0, 0.0);
		//rotate = true;
		//anglex += 5.0;
		//glutPostRedisplay();
		break;
	case 'y':
		// aqu  se procesar a la tecla <y>
		//rotate = true;
		//angley += 5.0;
		//glRotatef(5.0, 0.0, 1.0, 0.0);
		break;
	case 'z':
		// aqu  se procesar a la tecla <z>
		//rotate = true;
		//anglez += 5.0;
		glRotatef(5.0, 0.0, 0.0, 1.0);
		break;
	case 'e':
		if (end)
		{
			return;
		}
		anglerandom = 5.0;
		//anglerandom = (((float) rand() / (RAND_MAX)) + 1.0) * float_rand(3.0,7.0);
		moverandom = .3;
		moverandomaux = moverandom * (-1);
		//moverandom = ((((float)rand() / (RAND_MAX)) + 1.0) / 15.0);
		glutTimerFunc(1000, idle_cb, 0);
		
		break;
	case 'r':
		// aqu  se procesar a la tecla <r>
		glLoadIdentity();
		//angle = 0.0;
		break;
	case 'a':
		// aqu  se procesar a la tecla <a>
		//angle += 15;
		break;
	default:
		break;

	}
	//zero = true;
	glutPostRedisplay();

}

float float_rand(float min, float max) {
	float scale = rand() / (float)RAND_MAX;
	return min + scale * (max - min);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	srand(time(NULL));
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT); // ESTABLECE EL TAMANO DE LA VENTANA
	glutCreateWindow("CUBO 3D");

	initializer(); // INICIALIZA LA VENTANA
	glutDisplayFunc(displayScreen); // ACTUALIZA LA PANTALLA DE TRAZADO
	glutKeyboardFunc(teclado_cb);
	//glutIdleFunc(idle_cb);

	glutMainLoop(); // GENERA EL LOOP

	return 0;
}