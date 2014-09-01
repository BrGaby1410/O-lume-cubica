#include "world.h"

using namespace std;

ChunkData createChunk(GLfloat offsetX, GLfloat offsetY, GLfloat offsetZ)
{
	ChunkData result;
	Vertex vertices[24 * 16 * 16 * 16];
	unsigned int i, j, k;
	unsigned int count = 0;

	result.indices = new GLuint[24 * 16 * 16 * 16];

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			for (k = 0; k < 16; k++) {

				// fata de jos
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata de sus
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din stanga
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din dreapta
				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din spate
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din fata
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;
			}
		}
	}

	glGenBuffers(1, &(result.vboHandler));
	glBindBuffer(GL_ARRAY_BUFFER, result.vboHandler);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &(result.indexHandler));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, result.indexHandler);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(result.indices), result.indices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	result.size = sizeof(vertices) / sizeof(Vertex);
	cout << result.size << endl;

	return result;
}

void drawChunk(ChunkData chunk)
{
	glBindBuffer(GL_ARRAY_BUFFER, chunk.vboHandler);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, chunk.indexHandler);

	glEnableClientState(GL_VERTEX_ARRAY);
	// glEnableClientState(GL_NORMAL_ARRAY);
	// glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), 0);
	// glNormalPointer(GL_FLOAT, sizeof(Vertex), (char *) NULL + 3 * sizeof(GLfloat));
	// glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (char *) NULL + 6 * sizeof(GLfloat));

	glDrawElements(GL_QUADS, chunk.size, GL_UNSIGNED_INT, chunk.indices);
	// glDrawArrays(GL_QUADS, 0, chunk.size);

	cout << gluErrorString(glGetError()) << endl;

	glDisableClientState(GL_VERTEX_ARRAY);
	// glDisableClientState(GL_NORMAL_ARRAY);
	// glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
