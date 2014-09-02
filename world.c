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
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

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
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

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
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

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
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

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
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

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
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
				cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;
				cout << endl;
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

	// cout << gluErrorString(glGetError()) << endl;

	glDisableClientState(GL_VERTEX_ARRAY);
	// glDisableClientState(GL_NORMAL_ARRAY);
	// glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void removeCube(ChunkData chunk, int x, int y, int z)
{
	cout << "Aici incepe...\n";
	for (unsigned int i = 0; i < chunk.size; i++)
		if (i%24 == 0) { if (
				chunk.indices[i] == (unsigned int)((x * 16  * 16 + y * 16 + z) * 24)
				// chunk.indices[i + 1] == (unsigned int)((x + 1) * 24*24*24 + y * 24*24 + z * 24) &&
				// chunk.indices[i + 2] == (unsigned int)((x + 1) * 24*24*24 + y * 24*24 + (z + 1) * 24) &&
				// chunk.indices[i + 3] == (unsigned int)(x * 24*24*24 + y * 24*24 + (z + 1) * 24)
			)
		{
			cout << "DA\n\n\n\n\n\n\n\n\n\n\n";
			for (unsigned int j = i; j < chunk.size - 24; j++)
				chunk.indices[j] = chunk.indices[j + 24];
			chunk.size -= 24;
			break;
		}}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, chunk.indexHandler);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(chunk.indices), chunk.indices);
}

void addCube(ChunkData chunk, int x, int y, int z)
{
	GLuint ind2 = 1000000;
	bool exista = 0;
	for (unsigned int i = 0; i < chunk.size; i++)    // verific daca exista un cub deja aici
		if (i%24==0)
		{
			if (chunk.indices[i] == (unsigned int)((x * 16  * 16 + y * 16 + z) * 24) ) exista = 1;
				// ind[i+1] == et * 17*17 + ran * 17 + col + 1 &&
				// ind[i+2] >= et * 17*17 + (ran + 1) * 17 + col + 1 &&
				// ind[i+3] >= et * 17*17 + (ran + 1) * 17 + col) exista = 1;
		}
	if (exista) removeCube(chunk, x, y, z);

	for (unsigned int i = 0; i < chunk.size; i++)
		if (i%24==0) 
			{if (
				chunk.indices[i] > (unsigned int)((x * 16  * 16 + y * 16 + z) * 24)
				// ind[i+1] > et * 17*17 + ran * 17 + col + 1 &&
				// ind[i+2] > et * 17*17 + (ran + 1) * 17 + col + 1 &&
				// ind[i+3] > et * 17*17 + (ran + 1) * 17 + col 
				)
			 {ind2 = i; break;}
			}
	if (ind2 == 1000000) 
	{
	cout << "Pana aici\n";
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 1;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 2;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 3;
	
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 4;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 5;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 6;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 7;
			
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 8;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 9;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 10;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 11;
			
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 12;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 13;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 14;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 15;
			
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 16;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 17;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 18;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 19;
			
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 20;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 21;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 22;
	chunk.indices[chunk.size++] = (x * 16 * 16 + y * 16 + z) * 24 + 23;
	} else { 
	chunk.size += 24;
	for (unsigned int i = chunk.size; i >= ind2 + 24; i--)
		chunk.indices[i] = chunk.indices[i - 24];
	
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 1;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 2;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 3;
	
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 4;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 5;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 6;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 7;
			
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 8;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 9;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 10;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 11;
			
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 12;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 13;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 14;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 15;
			
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 16;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 17;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 18;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 19;
			
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 20;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 21;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 22;
	chunk.indices[ind2++] = (x * 16 * 16 + y * 16 + z) * 24 + 23; }



	cout << "Deci..." << chunk.size << "\n";





	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, chunk.indexHandler);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(chunk.indices), chunk.indices);
}
