#include "cube.h"


void cube_draw(float *position)
{
	GEOMETRY *g;
	g = malloc(sizeof(GEOMETRY));
	int Nv = 24, Nf = 12;
	float size = 2.0;
	int order[6] = {0, 1, 2, 1, 3, 2};
	GLfloat *vertices = malloc(Nv * 3 * sizeof(GLfloat));
	GLfloat *normals = malloc(Nv * 3 * sizeof(GLfloat));
	GLuint *faces = malloc(Nf * 3 * sizeof(GLuint));
	int i, j, k, l, n;
	for (i = 0; i < 3 * Nv; i++)
	{
		normals[i] = 0.0;
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
					vertices[3 * n + (l + 3) % 3] = i * size;
					vertices[3 * n + (l + 4) % 3] = j * size;
					vertices[3 * n + (l + 5) % 3] = k * size;
					normals[3 * n + (l + 5) % 3] = powf(-1.0, k + 1) * 1.0;
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
				faces[12 * l + 6 * k + i] = 8 * l + 4 * k + order[i];
			}
		}
	}
	g->vertices = vertices;
	g->normals = normals;
	g->faces = faces;
	g->vertex_num = Nv;
	g->face_num = Nf;
	geometry_rotate(g, 0, 1, 0, 0);
	geometry_translate(g, - position[0], - position[1] - 4.0, - position[2]);
	geometry_set_color(g, 1, 0, 0);	
	llist_add_element(&list_geos, g);	
}
