// g++ -g vbotest.cpp vector.cpp -lGL -lGLU -lglut -lGLEW -o rez -Wall

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include "vector.h"

using namespace std;

GLfloat light_poz[] = { 10, 10, 10, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };

float coord[17 * 17 * 17 * 3];
unsigned int ind[4 * 6 * 17 * 17 * 17];
int num_coord = 0;
int num_ind = 0;
unsigned int vbo, ind_buffer;


float f[] = {15, 15, 15,
			 16, 15, 15,
			 16, 15, 16,
			 15, 15, 16,
			 15, 16, 15,
			 16, 16, 15,
			 16, 16, 16,
			 15, 16, 16};
float col[] = {1, 0, 0, 1,
			   0, 1, 0, 1,
			   0, 0, 1, 1,
			   1, 1, 1, 1,};
unsigned int index[] = {0, 1, 2, 3,
						4, 5, 6, 7,
						1, 2, 6, 5,
						0, 3, 7, 4,
						0, 1, 5, 4,
						3, 2, 6, 7};
unsigned int VBO, IND;

			                               							   //           __________ 
			      						                               //          /|        /|      
				                                                       //         /_|_______/ |  
                                               						   //        |  |       | |  
                                                       				   //        |  |       | |  
										                               //        |  |_______|_| 
													                   //        | /        | /
														               //        |/_________|/

GLint width, height;
GLfloat angle = 0;

Vector eye;
Vector target;
Vector dir;

Vector res = createVector(0, 0, 0);
Vector jumpForce = createVector(0, 0, 0);

GLfloat DRAG_FORCE = 0.5;
GLfloat EYE_HEIGHT = 18;

GLfloat globalAngleY = 225;
GLfloat globalAngleX = 0;

GLfloat SPEED = 0.2;

bool keyState[255+1] = {false};

void motion(int x, int y);
void move(GLfloat angle);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void tick(int val);

typedef struct _Vertex
{
	float x, y, z, nx, ny, nz, tu, tv;
} Vertex;

Vertex vertices[16 * 16 * 16 * 8];

void Clear_cube(unsigned int et, unsigned int ran, unsigned int col)
{
	for (int i = 0; i < num_ind; i++)
		if (i%24 == 0) {if (
				ind[i] == et * 17*17 + ran * 17 + col &&                 // caut cubul dupa fata de jos
				ind[i + 1] == et * 17*17 + ran * 17 + col + 1 &&
				ind[i + 2] == et * 17*17 + (ran + 1) * 17 + col + 1 &&
				ind[i + 3] == et * 17*17 + (ran + 1) * 17 + col
			)
		{
			cout << "DA\n";
			for (int j = i; j < num_ind - 24; j++)
				ind[j] = ind[j + 24];
			num_ind = num_ind - 24;
			break;
		}}
	cout << num_ind << "\n";
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buffer);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(ind), ind);
}

void Add_cube(unsigned int et, unsigned int ran, unsigned int col)
{
	GLint ind2 = -1;
	bool exista = 0;
	for (int i = 0; i < num_ind; i++)    // verific daca exista un cub deja aici
		if (i%24==0)
		{
			if (ind[i] == et * 17*17 + ran * 17 + col &&
				ind[i+1] == et * 17*17 + ran * 17 + col + 1 &&
				ind[i+2] >= et * 17*17 + (ran + 1) * 17 + col + 1 &&
				ind[i+3] >= et * 17*17 + (ran + 1) * 17 + col) exista = 1;
		}
	if (exista) Clear_cube(et,ran,col);

	for (int i = 0; i < num_ind; i++)
		if (i%24==0) 
			{if (
				ind[i] > et * 17*17 + ran * 17 + col &&                 // caut cubul dupa fata de jos
				ind[i+1] > et * 17*17 + ran * 17 + col + 1 &&
				ind[i+2] > et * 17*17 + (ran + 1) * 17 + col + 1 &&
				ind[i+3] > et * 17*17 + (ran + 1) * 17 + col )
			 {ind2 = i; break;}
			}
	if (ind2 == -1) 
	{
	cout << "Pana aici\n";
	ind[num_ind++] = et * 17*17 + ran * 17 + col;
	ind[num_ind++] = et * 17*17 + ran * 17 + col + 1;
	ind[num_ind++] = et * 17*17 + (ran + 1) * 17 + col + 1;
	ind[num_ind++] = et * 17*17 + (ran + 1) * 17 + col;
	
	ind[num_ind++] = (et + 1) * 17*17 + ran * 17 + col;
	ind[num_ind++] = (et + 1) * 17*17 + (ran + 1) * 17 + col;
	ind[num_ind++] = (et + 1) * 17*17 + (ran + 1) * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + ran * 17 + col + 1;
			
	ind[num_ind++] = et * 17*17 + ran * 17 + col + 1;
	ind[num_ind++] = et * 17*17 + (ran + 1) * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + (ran + 1) * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + ran * 17 + col + 1;
			
	ind[num_ind++] = et * 17*17 + ran * 17 + col;
	ind[num_ind++] = et * 17*17 + (ran + 1) * 17 + col;
	ind[num_ind++] = (et + 1) * 17*17 + (ran + 1) * 17 + col;
	ind[num_ind++] = (et + 1) * 17*17 + ran * 17 + col;
			
	ind[num_ind++] = et * 17*17 + ran * 17 + col;
	ind[num_ind++] = et * 17*17 + ran * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + ran * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + ran * 17 + col;
			
	ind[num_ind++] = et * 17*17 + (ran + 1) * 17 + col;
	ind[num_ind++] = et * 17*17 + (ran + 1) * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + (ran + 1) * 17 + col + 1;
	ind[num_ind++] = (et + 1) * 17*17 + (ran + 1) * 17 + col;
	} else { 
	num_ind = num_ind + 24;
	for (int i = num_ind; i >= ind2 + 24; i--)
		ind[i] = ind[i - 24];
	
	ind[ind2++] = et * 17*17 + ran * 17 + col;
	ind[ind2++] = et * 17*17 + ran * 17 + col + 1;
	ind[ind2++] = et * 17*17 + (ran + 1) * 17 + col + 1;
	ind[ind2++] = et * 17*17 + (ran + 1) * 17 + col;
	
	ind[ind2++] = (et + 1) * 17*17 + ran * 17 + col;
	ind[ind2++] = (et + 1) * 17*17 + (ran + 1) * 17 + col;
	ind[ind2++] = (et + 1) * 17*17 + (ran + 1) * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + ran * 17 + col + 1;
			
	ind[ind2++] = et * 17*17 + ran * 17 + col + 1;
	ind[ind2++] = et * 17*17 + (ran + 1) * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + (ran + 1) * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + ran * 17 + col + 1;
			
	ind[ind2++] = et * 17*17 + ran * 17 + col;
	ind[ind2++] = et * 17*17 + (ran + 1) * 17 + col;
	ind[ind2++] = (et + 1) * 17*17 + (ran + 1) * 17 + col;
	ind[ind2++] = (et + 1) * 17*17 + ran * 17 + col;
			
	ind[ind2++] = et * 17*17 + ran * 17 + col;
	ind[ind2++] = et * 17*17 + ran * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + ran * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + ran * 17 + col;
			
	ind[ind2++] = et * 17*17 + (ran + 1) * 17 + col;
	ind[ind2++] = et * 17*17 + (ran + 1) * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + (ran + 1) * 17 + col + 1;
	ind[ind2++] = (et + 1) * 17*17 + (ran + 1) * 17 + col; }



	cout << "Deci..." << num_ind << "\n";





	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buffer);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(ind), ind);
}

void makeV()
{
	int count = 0;
	for (int j = 0; j < 17; j++) // etaj
		for (int k = 0; k < 17; k++) // rand
			for (int i = 0; i < 17; i++) // coloana
			{
				coord[num_coord++] = i;  
				coord[num_coord++] = j;                    
				coord[num_coord++] = k;
				vertices[count].x = i;
				vertices[count].y = j;
				vertices[count].z = k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;                                        
			}                  
	// coord[num_coord++] = 100;
	// coord[num_coord++] = 8;
	// coord[num_coord++] = 8;

	for (int i = 0; i < 16; i++) // etaj                               
		for (int j = 0; j < 16; j++) // rand                           
			for (int k = 0; k < 16; k++) // coloana                    
			{                         
				// fata de jos
				ind[num_ind++] = i * 17*17 + j * 17 + k;
				ind[num_ind++] = i * 17*17 + j * 17 + k + 1;
				ind[num_ind++] = i * 17*17 + (j + 1) * 17 + k + 1;
				ind[num_ind++] = i * 17*17 + (j + 1) * 17 + k;
				// fata de sus
				ind[num_ind++] = (i + 1) * 17*17 + j * 17 + k;
				ind[num_ind++] = (i + 1) * 17*17 + (j + 1) * 17 + k;
				ind[num_ind++] = (i + 1) * 17*17 + (j + 1) * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + j * 17 + k + 1;
				// fata din dreapta
				ind[num_ind++] = i * 17*17 + j * 17 + k + 1;
				ind[num_ind++] = i * 17*17 + (j + 1) * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + (j + 1) * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + j * 17 + k + 1;
				// fata din stanga
				ind[num_ind++] = i * 17*17 + j * 17 + k;
				ind[num_ind++] = i * 17*17 + (j + 1) * 17 + k;
				ind[num_ind++] = (i + 1) * 17*17 + (j + 1) * 17 + k;
				ind[num_ind++] = (i + 1) * 17*17 + j * 17 + k;
				// fata din spate
				ind[num_ind++] = i * 17*17 + j * 17 + k;
				ind[num_ind++] = i * 17*17 + j * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + j * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + j * 17 + k;
				// fata din fata
				ind[num_ind++] = i * 17*17 + (j + 1) * 17 + k;
				ind[num_ind++] = i * 17*17 + (j + 1) * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + (j + 1) * 17 + k + 1;
				ind[num_ind++] = (i + 1) * 17*17 + (j + 1) * 17 + k;
			}
	// ind[num_ind++] = 4096
	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 

	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 

	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 

	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 

	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 

	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 
	// ind[num_ind++] = 
		// for (int i = 0; i < num_ind; i++)
		// 	{cout << ind[i] << " ";
		// 	 if (i%4==3) cout << "\n";
		// 	 if (i%24==23) cout << "\n";}
		// cout << "\n";
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

	eye = createVector(18, EYE_HEIGHT, 18);
	target = createVector(0, 18, 0);

	makeV();
	cout << "AAA" << endl;
	glGenBuffers(1, &vbo);
	cout << "BBB" << endl;
	glGenBuffers(1, &ind_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), ind, GL_DYNAMIC_DRAW);
	// glBufferSubData(GL_ARRAY_BUFFER, sizeof(f), sizeof(col), col);


	// glGenBuffers(1, &vbo);
	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_DYNAMIC_DRAW);

	// glGenBuffers(1, &ind_buffer);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buffer);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), ind, GL_DYNAMIC_DRAW);

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
	glColor3f(1, 0.3, 0);

	glutSolidCube(1);
	
	// glEnableClientState(GL_VERTEX_ARRAY);
	//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ind_buffer);
	// 	glVertexPointer(3, GL_FLOAT, 3 * sizeof(float), 0);
	// 	glDrawElements(GL_QUADS, num_coord, GL_UNSIGNED_INT, ind);
	// 	glBindBuffer(GL_ARRAY_BUFFER,0);       
	//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	// glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buffer);

	if (keyState['e'] == true) 
	{
		// elimin cuburi
		cout << "EEEE\n";
		for (int i = 10; i <= 15; i++)
			for (int j = 0; j <= 15; j++)
				for (int k = 0; k <= 15; k++)
					Clear_cube(i,j,k);
	}

	if (keyState['r'] == true) 
	{
		// elimin cuburi
		cout << "RRRR\n";
		for (int i = 5; i <= 9; i++)
			for (int j = 0; j <= 15; j++)
				for (int k = 0; k <= 15; k++)
					Clear_cube(i,j,k);
	}

	if (keyState['t'] == true) 
	{
		// elimin cuburi
		cout << "TTTT\n";
		for (int i = 2; i <= 4; i++)
			for (int j = 0; j <= 15; j++)
				for (int k = 0; k <= 15; k++)
					Clear_cube(i,j,k);
	}

	if (keyState['q'] == true)
	{
		// adaug cuburi
		glColor3f(0,1,0);
		cout << "QQQQ\n";
		for (int i = 10; i <= 15; i++)
			{Add_cube(i, 7, 1);
			 Add_cube(i, 7, 6);
			 Add_cube(i, 7, 9);
			 Add_cube(i, 7, 11);}
		for (int i = 2; i<= 14; i++)
			{
				if (i!=5 && i != 10 && i!= 11) Add_cube(10, 7, i);
			}
		Add_cube(15,7,7);
		Add_cube(15,7,8);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	// glEnableClientState(GL_COLOR_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, 0);
	// glColorPointer(4, GL_FLOAT, 0, col);

	glDrawElements(GL_QUADS, num_ind , GL_UNSIGNED_INT, 0); // nr de indexi

	glDisableClientState(GL_VERTEX_ARRAY);
	// glDisableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glutSwapBuffers();
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


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("O lume cubica");
	glewInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1, tick, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMotionFunc(motion);
	// glutPassiveMotionFunc(motion);
	initialize();
	glutMainLoop();
	return 0;
}

// ===========================================================================================================










































void tick(int val)
{
	angle = angle + 0.001;
	if (angle > 360)
		angle = 360;
	move(angle);
	glutPostRedisplay();
	glutTimerFunc(1, tick, val + 1);
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
		jumpForce = createVector(0, 0.5, 0);                   // 0.171
	}
	// if (res.x != 0 && res.y != 0 && res.z != 0) {
	// 	// Vector dragForce = rotateVector(res, 180, 0, 1, 0);
	// 	// dragForce = multiplyVector(dragForce, 0.5);

	// 	// res = addVectors(res, dragForce);
	// }


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
//	cout << res.x << " " << res.y << " " << res.z << "\n";
	// cout << eye.x << " " << eye.y << " " << eye.z << "\n";
	// cout << jumpForce.y << "\n\n";

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
		case 'e':
		case 'E':
			keyState['e'] = true;
			break;
		case 'r':
		case 'R':
			keyState['r'] = true;
			break;
		case 't':
		case 'T':
			keyState['t'] = true;
			break;
		case 'q':
		case 'Q':
			keyState['q'] = true;
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
		case 'e':
		case 'E':
			keyState['e'] = false;
			break;
		case 'r':
		case 'R':
			keyState['r'] = false;
			break;
		case 't':
		case 'T':
			keyState['t'] = false;
			break;
		case 'q':
		case 'Q':
			keyState['q'] = false;
			break;	
	}
}