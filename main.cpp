#include <iostream>                // comentariu
#include <GL/glut.h>
#include <math.h>
#include "vector.h"

using namespace std;

Vector eye;
Vector target;
Vector dir;

GLfloat light_poz[] = { 10, 10, 10, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };
GLfloat angle = 0;
GLint width, height;

typedef struct _cube
{
	int x, y, z;
} cube;

cube ****world;
bool visited[100][100][100];

void motion(int x, int y)
{
	GLfloat angleX;
	GLfloat angleY;

	angleY = 90 - (x * (180 / (GLfloat) width));
	angleX = 90 - (y * (180 / (GLfloat) height));

	dir = substractVectors(target, eye);
	dir = rotateVector(dir, angleY, 0, 1, 0);
	target = addVectors(eye, dir);

	if (x != width / 2 || y != height / 2) 
		glutWarpPointer(width / 2, height / 2);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	cout << eye.x << " " << eye.y << " " << eye.z << "\n";
	switch (key)
	{
		case 'w':
		case 'W':
			dir = substractVectors(target, eye);
			normalizeVector(dir);
			eye = addVectors(eye, dir);
			target = addVectors(target, dir);
			break;
		case 's':
		case 'S':
			dir = substractVectors(target, eye);
			normalizeVector(dir);
			eye = substractVectors(eye, dir);
			target = substractVectors(target, dir);
			break; 
		case 'a':
		case 'A':
			dir = substractVectors(target, eye);
			normalizeVector(dir);
			dir = rotateVector(dir, 90, 0, 1, 0);
			eye = addVectors(eye, dir);
			target = addVectors(target, dir);
			break;
		case 'd':
		case 'D':
			dir = substractVectors(target, eye);
			normalizeVector(dir);
			dir = rotateVector(dir, -90, 0, 1, 0);
			eye = addVectors(eye, dir);
			target = addVectors(target, dir);
			break;
	}
}

void draw_cube(cube c)
{
	glPushMatrix();
		glTranslatef(c.x, c.y, c.z);
		glutSolidCube(1);
	glPopMatrix();
}

void draw_temp_world()
{
	glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(0, 50, 0);
		glVertex3f(0, 50, 100);
		glVertex3f(100, 50, 100);
		glVertex3f(100, 50, 0);
	glEnd();
	glColor3f(1,0,0);
	glPushMatrix();
		glTranslatef(15,52,15);
		glutSolidCube(2);
	glPopMatrix();
}

void draw_world(int x, int y, int z)
{
	if (x >= 100 || x < 0 ||
		y >= 100 || y < 0 ||
		z >= 100 || z < 0)
		return;

	if (visited[x][y][z])
		return;

	visited[x][y][z] = true;

	if (world[x][y][z] != 0) {
		draw_cube(*world[x][y][z]);
		return;
	}

	draw_world(x - 1, y - 1, z - 1);
	draw_world(x - 1, y - 1, z);
	draw_world(x - 1, y - 1, z + 1);
	draw_world(x, y - 1, z - 1);
	draw_world(x, y - 1, z);
	draw_world(x, y - 1, z + 1);
	draw_world(x + 1, y - 1, z - 1);
	draw_world(x + 1, y - 1, z);
	draw_world(x + 1, y - 1, z + 1);

	draw_world(x - 1, y + 1, z - 1);
	draw_world(x - 1, y + 1, z);
	draw_world(x - 1, y + 1, z + 1);
	draw_world(x, y + 1, z - 1);
	draw_world(x, y + 1, z);
	draw_world(x, y + 1, z + 1);
	draw_world(x + 1, y + 1, z - 1);
	draw_world(x + 1, y + 1, z);
	draw_world(x + 1, y + 1, z + 1);

	draw_world(x - 1, y, z - 1);
	draw_world(x - 1, y, z);
	draw_world(x - 1, y, z + 1);
	draw_world(x, y, z - 1);
	draw_world(x, y, z + 1);
	draw_world(x + 1, y, z - 1);
	draw_world(x + 1, y, z);
	draw_world(x + 1, y, z + 1);
}

void display(void)
{
	// Clear the color buffer, restore the background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Load the identity matrix, clear all the previous transformations
	glLoadIdentity();
	// Set up the camera
	gluLookAt(eye.x, eye.y, eye.z, target.x, target.y, target.z, 0, 1, 0);
	// Set the drawing color to white
	glColor3f(0, 1, 1);
	
	// for (int i = 0; i < 100; i++)
	// 	for (int j = 0; j < 100; j++)
	// 		for (int k = 0; k < 100; k++)
	// 			visited[i][j][k] = false;

	// draw_world(10, 51, 10);
	draw_temp_world();
	
	// Swap buffers in GPU
	glutSwapBuffers();
}

void tick(int val)
{
	glutPostRedisplay();
	glutTimerFunc(1, tick, val + 1);
}

void reshape(int _width, int _height)
{
	// Set the viewport to the full window size
	glViewport(0, 0, (GLsizei) _width, (GLsizei) _height);
	// Load the projection matrix
	glMatrixMode(GL_PROJECTION);
	// Clear all the transformations on the projection matrix
	glLoadIdentity();
	// Set the perspective according to the window size
	gluPerspective(60, (GLdouble) _width / (GLdouble) _height, 0.1, 60000);
	// Load back the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	width = _width;
	height = _height;
}

void initialize(void)
{
	// Set the background to black
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_POSITION, light_poz);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT, GL_AMBIENT);

	eye = createVector(10, 51.5, 10);
	target = createVector(0, 51.5, 0);

	world = (cube****) calloc (100, sizeof (cube***));
	for (int i = 0; i < 100; i++)
	{
		world[i] = (cube***) calloc (100, sizeof(cube**));
		for (int j = 0; j < 100; j++)
		{
			world[i][j] = (cube**) calloc (100, sizeof (cube*));
			for (int k = 0; k < 100; k++)
				 visited[i][j][k] = false;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				world[i][j][k] = (cube*) malloc (sizeof(cube));
				(*world[i][j][k]).x = i;
				(*world[i][j][k]).y = j;
				(*world[i][j][k]).z = k;
			}
		}
	}
}

int main(int argc, char *argv[])
{
//	cout << "\n\n Yay! Pot lucra si pe Ubuntu! \n\n\n";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("O lume cubica");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1, tick, 0);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(motion);
	initialize();
	glutMainLoop();
	return 0;
}
