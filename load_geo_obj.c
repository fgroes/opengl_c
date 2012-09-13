#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "load_geo_obj.h"
#include "math_adv.h"


void load_test()
{
	N = 6;
	vertices = malloc(3 * N * sizeof(GLfloat));
	indices = malloc(N * sizeof(GLuint));
	GLfloat vertex[] = {0, 0, -3, 0, 1, -3, 1, 0.5, -3, -2, -2, -8, 2, -2, -8, 0, 2, -8};
	GLuint index[] = {0, 1, 2, 3, 4, 5};
	int i;
	for (i = 0; i < 3 * N; i++)
		vertices[i] = vertex[i];
	for (i = 0; i < N; i++)
		indices[i] = index[i];
}


void load_geo_obj(char *filename)
{
	//load_test();
	int face_num = 0, vertex_num = 0;
	GLuint idx[3];
	GLfloat *vtx;
	char line_buffer[BUFSIZ];
	char type;
	FILE *file;
	file = fopen(filename, "r");
	if (file != NULL)
	{
		printf("loading file: %s\n", filename);
		while (fgets(line_buffer, sizeof(line_buffer), file))
		{
			sscanf(line_buffer, "%c", &type);
			if (type == 'v')
				vertex_num++;
			else if (type == 'f')
				face_num++;
		}
		fclose(file);
		printf("vertices loaded: %d\n", vertex_num);
		vertices = malloc(3 * vertex_num * sizeof(GLfloat));
		printf("faces loaded: %d\n", face_num);
		indices = malloc(3 * face_num * sizeof(GLuint));
		N = 3 * face_num;
	}
	else
		perror("file could not be opened\n");
	file = fopen(filename, "r");
	if (file != NULL)
	{
		int v = 0, f = 0;
		while (fgets(line_buffer, sizeof(line_buffer), file))
		{
			sscanf(line_buffer, "%c", &type);
			if (type == 'v')
			{
				vtx = vertices + 3 * v;
				sscanf(line_buffer, "%c %f %f %f", &type, vtx, vtx + 1, vtx + 2);
				v++;
			}
			else if (type == 'f')
			{
				sscanf(line_buffer, "%c %d %d %d", &type, &idx[0], &idx[1], &idx[2]);
				int i;
				for (i = 0; i < 3; i++) 
					indices[3 * f + i] = idx[i] - 1;
				f++;
			}
		}
		fclose(file);
	}
	else
		perror("file could not be opened\n");
	normals = malloc(3 * vertex_num * sizeof(GLfloat));
	GLfloat *nml;
	GLuint *fc;
	GLfloat a[3], b[3];
	int n, m;
	for (n = 0; n < vertex_num; n++)
	{
		nml = normals + 3 * n;
		for (m = 0; m < face_num; m++)
		{
			fc = indices + 3 * m;
			if (fc[0] == n || fc[1] == n || fc[2] == n)
			{
				sub(vertices + fc[0], vertices + fc[1], a);
				sub(vertices + fc[2], vertices + fc[1], b);
				normalize(a);
				normalize(b);
				cross(a, b, nml);
			}
		}
	}
}
