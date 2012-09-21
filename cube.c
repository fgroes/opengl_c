#include "cube.h"


void cube_draw(GEOMETRY *self, float size)
{
	int Nv = 24, Nf = 12;
	int order[6] = {0, 1, 2, 1, 3, 2};
	self->vertices = malloc(Nv * 3 * sizeof(GLfloat));
	self->normals = malloc(Nv * 3 * sizeof(GLfloat));
	self->faces = malloc(Nf * 3 * sizeof(GLuint));
	int i, j, k, l, n;
	for (i = 0; i < 3 * Nv; i++)
	{
		self->normals[i] = 0.0;
	}
	n = 0;
	// face orientation (drawing plane, horizontal, vertical)
	for (l = 0; l < 3; l++)
	{
		for (k = 0; k < 2; k++)
		{
			for (j = 0; j < 2; j++)
			{
				for (i = 0; i < 2; i++)
				{
					self->vertices[3 * n + (l + 3) % 3] = i * size;
					self->vertices[3 * n + (l + 4) % 3] = j * size;
					self->vertices[3 * n + (l + 5) % 3] = k * size;
					self->normals[3 * n + (l + 5) % 3] = powf(-1.0, k + 1) * 1.0;
					n++;
				}
			}
		}
	}
	for (l = 0; l < 3; l++)
	{
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < 6; i++)
			{
				self->faces[12 * l + 6 * k + i] = 8 * l + 4 * k + order[i];
			}
		}
	}
	self->vertex_num = Nv;
	self->face_num = Nf;
}
