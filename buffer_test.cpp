#define GL_GLEXT_PROTOTYPES
#include <iostream>
#include <GL/glut.h>
#include <GL/glext.h>

using namespace std;

GLfloat light_poz[] = { 105, 105, 105, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };

GLuint pixeli, indexi;

typedef struct _vertex
{
	GLint x, y, z;
} vertex;

void draw_cube(int x, int y, int z)
{
	glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidCube(1);
	glPopMatrix();
}

void metoda1()
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++) {
				glColor3f(i / 100, j / 100, k / 100);
				draw_cube(i, j, k);
			}
}

void metoda2()
{
	vertex * ceva;
	ceva = (vertex*) malloc (101*101*101 * sizeof(vertex));
	GLuint contor = 0;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 100; k++)
			{
				ceva[contor].x = i;
				ceva[contor].y = j;
				ceva[contor++].z = k;
			}
	glBufferData(GL_ARRAY_BUFFER, 101*101*101* sizeof(vertex), ceva, GL_STATIC_DRAW);
	free(ceva);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	GLuint * ordine;
	contor = 0;
	ordine = (GLuint*) malloc (100*100*100* 24 * sizeof(GLuint));
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
			{
				ordine[contor++] = i *101*101 + j * 101 + k;
				ordine[contor++] = i * 101*101 + j*101 + k + 1;
				ordine[contor++] = (i+1) * 101*101 + j*101 + k + 1;
				ordine[contor++] = (i+1) *101*101 + j * 101 + k;

				ordine[contor++] = i *101*101 + (j + 1) * 101 + k;
				ordine[contor++] = i * 101*101 + (j + 1)*101 + k + 1;
				ordine[contor++] = (i+1) * 101*101 + (j + 1) *101 + k + 1;
				ordine[contor++] = (i+1) *101*101 + (j + 1) * 101 + k;

				ordine[contor++] = i * 101*101 + j*101 + k ;
				ordine[contor++] = i * 101*101 + j*101 + k + 1;
				ordine[contor++] = i *101*101 + (j+1) * 101 + k + 1;
				ordine[contor++] = i * 101*101 + (j+1)*101 + k;

				ordine[contor++] = (i + 1) * 101*101 + j*101 + k ;
				ordine[contor++] = (i + 1)* 101*101 + j*101 + k + 1;
				ordine[contor++] = (i + 1) *101*101 + (j+1) * 101 + k + 1;
				ordine[contor++] = (i + 1)* 101*101 + (j+1)*101 + k;

				ordine[contor++] = i *101*101 + j * 101 + k;
				ordine[contor++] = i * 101*101 + (j + 1)*101 + k;
				ordine[contor++] = (i+1) * 101*101 + (j + 1)*101 + k;
				ordine[contor++] = (i+1) * 101*101 + j*101 + k;

				ordine[contor++] = i *101*101 + j * 101 + k + 1;
				ordine[contor++] = i * 101*101 + (j + 1)*101 + k + 1;
				ordine[contor++] = (i+1) * 101*101 + (j + 1)*101 + k + 1;
				ordine[contor++] = (i+1) * 101*101 + j*101 + k + 1;
			}

	glGenBuffers(1, &indexi);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexi);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 100*100*100* 24 * sizeof(GLuint), ordine, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, pixeli);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexi);

	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_INT, sizeof(vertex), (char*) NULL + 0);

	glDrawElements(GL_QUADS, 101 * 101 * 101, GL_INT, (char *) NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);

}

void reshape(int _width, int _height)
{
	glViewport(0, 0, (GLsizei) _width, (GLsizei) _height);
	// Load the projection matrix
	glMatrixMode(GL_PROJECTION);
	// Clear all the transformations on the projection matrix
	glLoadIdentity();
	// Set the perspective according to the window size
	gluPerspective(60, (GLdouble) _width / (GLdouble) _height, 0.1, 60000);
	// Load back the modelview matrix
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Load the identity matrix, clear all the previous transformations
	glLoadIdentity();
	// Set up the camera
	gluLookAt(105, 105, 105, 0, 0, 0, 0, 1, 0);
	glColor3f(1, 1, 1);
	metoda2();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_POSITION, light_poz);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);

	glGenBuffers(1, &pixeli);
	glBindBuffer(GL_ARRAY_BUFFER, pixeli);

}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}