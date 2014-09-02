#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include "vector.h"
#include "motion.h"
#include "world.h"

using namespace std;

ChunkData *chunk;

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
	
	glColor3f(1, 0, 0);
	drawChunks(chunk, 9);

	glutSwapBuffers();
}

void tick(int val)
{
	move(0);
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
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);

	glEnable(GL_TEXTURE_2D);
	loadTextureFromFile("data/textures/grass_cube.jpg");

	eye = createVector(20, EYE_HEIGHT, 20);
	target = createVector(0, 0, 0);

	cout << "Creating chunk... " << flush;
	
	chunk = new ChunkData[9];
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; j++) {
			chunk[3 * i + j] = createChunk(i * 16, 0, j * 16);
	}

	removeCube(chunk[0], 10, 15, 8);
	removeCube(chunk[0], 0, 15, 0);
	for (int i = 0; i < 16; i++)
		removeCube(chunk[0], 8, i, 10);

	cout << "Done!" << "\n" << flush;
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("O lume cubica");

	glewExperimental = 1;

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		cout << glewGetErrorString(err) << "\n";
		return -1;
	}

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1, tick, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(motion);
	initialize();
	glutMainLoop();
	return 0;
}
