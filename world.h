#include <GL/glut.h>

typedef struct _vertex {
	GLfloat vx, vy, vz;
	GLfloat nx, ny, nz;
	GLfloat tu, tv;
} Vertex;

typedef struct _chunkData {
	GLuint *indices;
	GLuint vboHandler;
	GLuint indexHandler;
} ChunkData;

ChunkData createChunk(GLfloat offsetX, GLfloat offsetY, GLfloat offsetZ);