#define GL_GLEXT_PROTOTYPE

#include <iostream>
#include <GL/glut.h>
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

GLfloat light_poz[] = { 10, 10, 10, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };

char* incarca(char* filename)
{
	FILE *fp = fopen(filename, "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* text = (char*) malloc(sizeof(char) * size);
	fread(text, sizeof(char) * size, 1, fp);
	fclose(fp);
	return text;
}

GLuint CreateShader(char* filename, GLenum shadertype)
{
	GLuint id = glCreateShader(shadertype);
	char *source = incarca(filename);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);
	return id;
}

void initialize()
{
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_POSITION, light_poz);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
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
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Load the identity matrix, clear all the previous transformations
	glLoadIdentity();
	// Set up the camera
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	// Set the drawing color to white
	glColor3f(0, 1, 1);


	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("O lume cubica");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initialize();
	glutMainLoop();
	return 0;
}