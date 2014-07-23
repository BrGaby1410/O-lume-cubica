#include <iostream>                // comentariu
#include <GL/glut.h>

using namespace std;

GLfloat light_poz[] = { 10, 10, 10, 1 };
GLfloat white_light[] = { 1, 1, 1, 1 };

typedef struct _cube
{
	int x, y, z;
} cube;

cube ****world;
bool visited[100][100][100];

void draw_cube(cube c)
{
	glPushMatrix();
		glTranslatef(c.x, c.y, c.z);
		glutSolidCube(1);
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
	gluLookAt(10, 51.5, 10, 0, 51.5, 0, 0, 1, 0);
	// Set the drawing color to white
	glColor3f(0, 1, 1);
	
	draw_world(10, 51, 10);
	
	// Swap buffers in GPU
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	// Set the viewport to the full window size
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	// Load the projection matrix
	glMatrixMode(GL_PROJECTION);
	// Clear all the transformations on the projection matrix
	glLoadIdentity();
	// Set the perspective according to the window size
	gluPerspective(60, (GLdouble) width / (GLdouble) height, 0.1, 60000);
	// Load back the modelview matrix
	glMatrixMode(GL_MODELVIEW);
}

void initialize(void)
{
	// Set the background to black
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_POSITION, light_poz);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	world = (cube****) calloc (100, sizeof (cube***));
	for (int i = 0; i < 100; i++)
	{
		world[i] = (cube***) calloc (100, sizeof(cube**));
		for (int j = 0; j < 100; j++)
		{
			world[i][j] = (cube**) calloc (100, sizeof (cube*));
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				visited[i][j][k] = false;
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
	initialize();
	glutMainLoop();
	return 0;
}
