#include "world.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ASSERT(x)
#include "std_image.h"

using namespace std;

ChunkData createChunk(GLfloat offsetX, GLfloat offsetY, GLfloat offsetZ)
{
	ChunkData result;
	Vertex vertices[24 * 16 * 16 * 16];
	unsigned int i, j, k;
	unsigned int count = 0;
	unsigned int count2 = 0;

	result.indices = new GLuint[24 * 16 * 16 * 16];
	result.textures = new TextureData[2];
	result.textureID = new GLuint[2];

	result.cubes = new char[16 * 16 * 16];

	result.textureID[0] = 0;
	result.textures[0] = loadTextureFromFile("data/textures/oak.jpg");
	result.textureID[1] = 16 * 16 * 15;
	result.textures[1] = loadTextureFromFile("data/textures/grass_cube.jpg");
	result.texturesNumber = 2;

	for (j = 0; j < 16; j++) {
		for (k = 0; k < 16; k++) {
			for (i = 0; i < 16; i++) {

				result.cubes[count2++] = 1;

				// result.textures[count2] = &t;
				// result.textureID[count2++] = 

				// fata de jos
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 1;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = -1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata de sus
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 1;
				vertices[count].nz = 0;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0.34;
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
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = -1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din dreapta
				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0.75;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 1;
				vertices[count].ny = 0;
				vertices[count].nz = 0;
				vertices[count].tu = 0.75;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din spate
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0.75;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 0.75;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = -1;
				vertices[count].tu = 1;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				// fata din fata
				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0.65;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i + 1;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0.5;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;

				result.indices[count] = count;
				vertices[count].vx = offsetX + i;
				vertices[count].vy = offsetY + j + 1;
				vertices[count].vz = offsetZ + k + 1;
				vertices[count].nx = 0;
				vertices[count].ny = 0;
				vertices[count].nz = 1;
				vertices[count].tu = 0.25;
				vertices[count++].tv = 0.34;
				// cout << vertices[count - 1].vx << " " << vertices[count - 1].vy << " " << vertices[count - 1].vz << endl;
				// cout << count << endl;
			}
		}
	}


	// cout << glGenBuffers << "\n";
	glGenBuffers(1, &(result.vboHandler));
	// cout << "AAA" << endl;
	glBindBuffer(GL_ARRAY_BUFFER, result.vboHandler);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &(result.indexHandler));
	// cout << "BBBB" << endl;
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
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), 0);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), (char *) NULL + 3 * sizeof(GLfloat));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (char *) NULL + 6 * sizeof(GLfloat));

	if (chunk.texturesNumber == 1) {
		loadMaterial(chunk.textures[0]);
		glDrawElements(GL_QUADS, chunk.size, GL_UNSIGNED_INT, chunk.indices);
	} else {
		unsigned int i;
		for (i = 0; i < chunk.texturesNumber - 1; i++) {
			loadMaterial(chunk.textures[i]);
			glDrawElements(GL_QUADS, chunk.textureID[i + 1] - chunk.textureID[i], GL_UNSIGNED_INT, chunk.indices + chunk.textureID[i]);		
		}
		loadMaterial(chunk.textures[i]);
		glDrawElements(GL_QUADS, chunk.size - chunk.textureID[i], GL_UNSIGNED_INT, chunk.indices + chunk.textureID[i]);
	}
	

	// glDrawArrays(GL_QUADS, 0, chunk.size);

	// cout << gluErrorString(glGetError()) << endl;

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void removeCube(ChunkData &chunk, int x, int y, int z)
{
	GLuint *cubePointer = chunk.indices + (24 * (16 * 16 * y + 16 * z + x));
	memset(cubePointer, 0, 24 * sizeof(GLuint));

	chunk.cubes[24 * (16 * 16 * y + 16 * z + x)] = 0;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, chunk.indexHandler);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(chunk.indices), chunk.indices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void addCube(ChunkData &chunk, int x, int y, int z)
{
	GLuint *cubePointer = chunk.indices + (24 * (16 * 16 * y + 16 * z + x));

	if (cubePointer[0] * cubePointer[1] != 0) {
		removeCube(chunk, x, y, z);
	}

	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 1;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 2;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 3;
	
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 4;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 5;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 6;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 7;
			
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 8;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 9;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 10;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 11;
			
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 12;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 13;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 14;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 15;
			
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 16;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 17;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 18;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 19;
			
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 20;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 21;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 22;
	chunk.indices[chunk.size++] = (y * 16 * 16 + z * 16 + x) * 24 + 23;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, chunk.indexHandler);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(chunk.indices), chunk.indices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void drawChunks(ChunkData *chunks, int size)
{
	for (int i = 0; i < size; ++i) {
		drawChunk(chunks[i]);
	}
}

TextureData loadTextureFromFile(const char *fileName)
{
	TextureData result;
	int n;

	result.texData = stbi_load(fileName, &result.width, &result.height, &n, 3);

	return result;
}

void loadMaterial(TextureData data)
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 
			data.width, 
			data.height, 0, GL_RGB, GL_UNSIGNED_BYTE, 
			data.texData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}