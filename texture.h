#ifndef TEXTURE_H
#define TEXTURE_H
#include <stdio.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>


struct texture
{
	GLuint tex;
};

typedef struct texture TEXTURE;


void texture_load(TEXTURE *, char *filename);


#endif
