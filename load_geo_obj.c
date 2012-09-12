#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "load_geo_obj.h"


void load_test()
{
	N = 6;
	vertices = malloc(3 * N * sizeof(GLfloat));
	indices = malloc(N * sizeof(GLuint));
	GLfloat vtx[] = {0, 0, -3, 0, 1, -3, 1, 0.5, -3, -2, -2, -8, 2, -2, -8, 0, 2, -8};
	GLuint idx[] = {0, 1, 2, 3, 4, 5};
	int i;
	for (i = 0; i < 3 * N; i++)
		vertices[i] = vtx[i];
	for (i = 0; i < N; i++)
		indices[i] = idx[i];
}


void load_geo_obj(char *filename)
{
	load_test();
}
