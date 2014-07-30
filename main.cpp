#include <iostream>                // comentariu
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include "vector.h"

using namespace std;

Vector eye;
Vector target;
Vector dir;

Vector res = createVector(0, 0, 0);
Vector jumpForce = createVector(0, 0, 0);

GLfloat DRAG_FORCE = 0.5;
GLfloat EYE_HEIGHT = 51.5;

GLfloat light_poz[] = { 10, 10, 10, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };
GLfloat angle = 0;
GLfloat globalAngleY = 225;
GLfloat globalAngleX = 0;
GLint width, height;

GLfloat SPEED = 0.2;

bool keyState[256] = {false};

typedef struct _cube
{
	int x, y, z;
} cube;

cube ****world;
bool visited[100][100][100];
char collision[130000];

void set_bit(int pos, char &a)
{
	a |= (1 << pos);
}

void clear_bit(int pos, char &a)
{
	a &= ~(1 << pos);
}

int get_bit(int pos, char a)
{
	a &= (1 << pos);
	return (a > 0);
}

void set_cube_at(int x, int y, int z)
{
	set_bit(x, collision[y + z * 1300]);
}

void clear_cube_at(int x, int y, int z)
{
	clear_bit(x, collision[y + z * 1300]);
}

int get_cube_at()
{
	return get_bit(x, collision[y + z * 1300]);
}


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
		jumpForce = createVector(0, 0.5, 0);
	}
	// if (res.x != 0 && res.y != 0 && res.z != 0) {
	// 	// Vector dragForce = rotateVector(res, 180, 0, 1, 0);
	// 	// dragForce = multiplyVector(dragForce, 0.5);

	// 	// res = addVectors(res, dragForce);
	// }


	if (eye.y > EYE_HEIGHT) {
		jumpForce = substractVectors(jumpForce, createVector(0, 0.07, 0));
	} else if (jumpForce.y != 0.5) {
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
	cout << res.x << " " << res.y << " " << res.z << "\n";

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

void draw_cube(cube c)
{
	glPushMatrix();
		glTranslatef(c.x, c.y, c.z);
		glutSolidCube(1);
	glPopMatrix();
}

void draw_temp_world()
{
	glColor3f(0.2, 0.2, 0.2);
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
	glPushMatrix();
		glTranslatef(0, 50, 0);
		glColor3f(1, 0, 1);
		glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);
			glVertex3f(0, 0, 0);
			glVertex3f(100, 0, 0);
			glVertex3f(100, 1, 0);
			glVertex3f(0, 1, 0);

			glNormal3f(-1, 0, 0);
			glVertex3f(100, 0, 0);
			glVertex3f(100, 0, 100);
			glVertex3f(100, 1, 100);
			glVertex3f(100, 1, 0);

			glNormal3f(0, 0, -1);
			glVertex3f(0, 0, 100);
			glVertex3f(100, 0, 100);
			glVertex3f(100, 1, 100);
			glVertex3f(0, 1, 100);

			glNormal3f(1, 0, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 100);
			glVertex3f(0, 1, 100);
			glVertex3f(0, 1, 0);


		glEnd();
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
	angle = angle + 0.001;
	if (angle > 360)
		angle = 360;
	move(angle);
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
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);

	eye = createVector(10, EYE_HEIGHT, 10);
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
	glutSpecialFunc(specialKeyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(motion);
	initialize();
	glutMainLoop();
	return 0;
}
