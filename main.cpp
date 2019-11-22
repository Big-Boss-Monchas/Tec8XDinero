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

#define HEIGHT 720
#define WIDTH 1280

Cube cubito(0, 0, 0, 5, 5);
PrismRectangular mesita(0, 0, -5, 15, 15, 2);
float angle = 0.0;

void initializer(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // COLOR CANVAS
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

void idle_cb() {
	angle += 0.05;
	glutPostRedisplay();
}

void displayScreen(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(150, 150, 300, 300);

	cubito.drawFigureDice();
	mesita.drawFigureTable();

	glutSwapBuffers();
}

void teclado_cb(GLubyte key, GLint x, GLint y) {
	switch (key) {
	case 27:
		exit(1);
		break;
	case 'x':
		// aqu  se procesar a la tecla <x>
		glRotatef(5.0, 1.0, 0.0, 0.0);
		break;
	case 'y':
		// aqu  se procesar a la tecla <y>
		glRotatef(5.0, 0.0, 1.0, 0.0);
		break;
	case 'z':
		// aqu  se procesar a la tecla <z>
		glRotatef(5.0, 0.0, 0.0, 1.0);
		break;
	case 'e':
		// aqu  se procesar a la tecla <e>
		glRotatef(10.0, 1.0, 1.0, 1.0);
		break;
	case 'r':
		// aqu  se procesar a la tecla <r>
		glLoadIdentity();
		angle = 0.0;
		break;
	case 'a':
		// aqu  se procesar a la tecla <a>
		angle += 15;
		break;
	default:
		break;

	}
	glutPostRedisplay();

}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

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