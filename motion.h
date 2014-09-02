#ifndef __MOTION_H
#define __MOTION_H

#include <GL/glut.h>
#include "vector.h"

Vector eye;
Vector target;
Vector dir;

Vector res = createVector(0, 0, 0);
Vector jumpForce = createVector(0, 0, 0);

GLfloat DRAG_FORCE = 0.5;
GLfloat EYE_HEIGHT = 17.5;

GLfloat light_poz[] = { 10, 10, 10, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };
GLfloat globalAngleY = 225;
GLfloat globalAngleX = 0;
GLint width, height;

GLfloat SPEED = 0.2;

bool keyState[256] = {false};

#endif

void motion(int x, int y);
void move(GLfloat angle);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);

void motion(int x, int y)
{
	GLfloat angleX;
	GLfloat angleY;

	angleY = 90 - (x * (180 / (GLfloat) width));
	angleX = 90 - (y * (180 / (GLfloat) height));

	dir = substractVectors(target, eye);
	if (angleX + globalAngleX > 89)
	{
		angleX = 89 - globalAngleX;
		globalAngleX = 89;
	}
	else if (angleX + globalAngleX < -89)
	{
		angleX = -89 - globalAngleX;
		globalAngleX = -89;
	}
	else globalAngleX += angleX;
	dir = rotateVector(dir, angleY, 0, 1, 0);
	Vector dir2 = createVector(dir.x, 0, dir.z);
	dir2 = rotateVector(dir2, -90, 0, 1, 0);
	normalizeVector(dir2);
	dir = rotateVector(dir, angleX, dir2.x, 0, dir2.z);

	target = addVectors(eye, dir);



	if (x != width / 2 || y != height / 2) 
		glutWarpPointer(width / 2, height / 2);
	glutPostRedisplay();
}

void move(GLfloat angle)
{

	res = createVector(0, 0, 0);

	if (keyState['w'] == true) {
		dir = substractVectors(target, eye);
		dir.y = 0;
		normalizeVector(dir);
		dir = multiplyVector(dir, SPEED);
		res = addVectors(res, dir);
	}

	if (keyState['s'] == true) {
		dir = substractVectors(target, eye);
		dir.y = 0;
		normalizeVector(dir);
		dir = multiplyVector(dir, SPEED);
		res = substractVectors(res, dir);
	}

	if (keyState['a'] == true) {
		dir = substractVectors(target, eye);
		dir.y = 0;
		normalizeVector(dir);
		dir = multiplyVector(dir, SPEED);
		dir = rotateVector(dir, 90, 0, 1, 0);
		res = addVectors(res, dir);
	}

	if (keyState['d'] == true) {
		dir = substractVectors(target, eye);
		dir.y = 0;
		normalizeVector(dir);
		dir = multiplyVector(dir, SPEED);
		dir = rotateVector(dir, -90, 0, 1, 0);
		res = addVectors(res, dir);
	}


	if (keyState[32] == true && jumpForce.y == 0)
	{
		jumpForce = createVector(0, 0.5, 0);                   // 0.171
	}


	if (eye.y > EYE_HEIGHT) {
		jumpForce = substractVectors(jumpForce, createVector(0, 0.07, 0));           // 0.011
	} else if (jumpForce.y != 0.5) {                   // 0.171
		keyState[32] = false;
		res.y = 0;
		jumpForce = createVector(0, 0, 0);
		eye.y = EYE_HEIGHT;
	}

	res = multiplyVector(res, 0.9);
	if (jumpForce.y != 0)
		res = addVectors(res, jumpForce);
	else if (res.x != 0 || res.y != 0 || res.z != 0) {
		// res = addVectors(res, createVector(0, 0.5 * sin(angle * DEG_TO_RAD), 0));
	}

	eye = addVectors(eye, res);
	target = addVectors(target, res);
}

void keyboard(unsigned char key, int x, int y)
{
	// cout << eye.x << " " << eye.y << " " << eye.z << "\n";
	switch (key)
	{
		case 'w':
		case 'W':
			keyState['w'] = true;
			break;
		case 's':
		case 'S':
			keyState['s'] = true;
			break; 
		case 'a':
		case 'A':
			keyState['a'] = true;
			break;
		case 'd':
		case 'D':
			keyState['d'] = true;
			break;
		case 32:
			keyState[32] = true;
			break;
		case 27:
			exit(0);
	}
}

void specialKeyboard(int key, int x, int y)
{
	//cout << eye.x << " " << eye.y << " " << eye.z << "\n";
	switch (key)
	{
		case 27:
			exit(0);
	}
}


void keyboardUp(unsigned char key, int x, int y)
{
	//cout << eye.x << " " << eye.y << " " << eye.z << "\n";
	switch (key)
	{
		case 'w':
		case 'W':
			keyState['w'] = false;
			break;
		case 's':
		case 'S':
			keyState['s'] = false;
			break; 
		case 'a':
		case 'A':
			keyState['a'] = false;
			break;
		case 'd':
		case 'D':
			keyState['d'] = false;
			break;
	}
}
