#include "world.h"

ChunkData createChunk(GLfloat offsetX, GLfloat offsetY, GLfloat offsetZ)
{
	ChunkData result;
	Vertex vertices[16 * 16 * 16 * 8];
	unsigned int i, j, k;
	unsigned int count = 0;

	result.indices = (GLuint *) malloc (24 * 16 * 16 * 16 * sizeof(GLuint));

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			for (k = 0; k < 16; k++) {

				// fata de jos
				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;

				// fata de sus
				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;

				// fata din stanga
				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;

				// fata din dreapta
				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;

				// fata din spate
				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;

				// fata din fata
				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0;
				vertices[count++].tv = 0;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 1;
				vertices[count++].tv = 1;

				indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0;
			}
		}
	}

	glGenBuffers(1, &(result.vboHandler));
	glBindBuffer(GL_ARRAY_BUFFER, result.vboHandler);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}