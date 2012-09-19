#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "math_adv.h"
#include "geometry.h"


void load_geo_obj(GEOMETRY *self, char *filename)
{
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
				self->vertex_num++;
			else if (type == 'f')
				self->face_num++;
		}
		fclose(file);
		printf("vertices loaded: %d\n", self->vertex_num);
		self->vertices = malloc(3 * self->vertex_num * sizeof(GLfloat));
		printf("faces loaded: %d\n", self->face_num);
		self->indices = malloc(3 * self->face_num * sizeof(GLuint));
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
				vtx = self->vertices + 3 * v;
				sscanf(line_buffer, "%c %f %f %f", &type, vtx, vtx + 1, vtx + 2);
				v++;
			}
			else if (type == 'f')
			{
				sscanf(line_buffer, "%c %d %d %d", &type, &idx[0], &idx[1], &idx[2]);
				int i;
				for (i = 0; i < 3; i++) 
					self->indices[3 * f + i] = idx[i] - 1;
				f++;
			}
		}
		fclose(file);
	}
	else
		perror("file could not be opened\n");
	self->normals = malloc(3 * self->vertex_num * sizeof(GLfloat));
	GLfloat *nml;
	GLuint *fc;
	GLfloat a[3], b[3];
	int n, m;
	for (n = 0; n < self->vertex_num; n++)
	{
		nml = self->normals + 3 * n;
		for (m = 0; m < self->face_num; m++)
		{
			fc = self->indices + 3 * m;
			if (fc[0] == n || fc[1] == n || fc[2] == n)
			{
				sub(self->vertices + fc[0], self->vertices + fc[1], a);
				sub(self->vertices + fc[2], self->vertices + fc[1], b);
				normalize(a);
				normalize(b);
				cross(a, b, nml);
			}
		}
	}
}


int get_num_face_coords(GEOMETRY *self)
{
	return 3 * self->face_num;	
}


int get_num_vertices(GEOMETRY *self)
{
	return self->vertex_num;	
}


int get_num_faces(GEOMETRY *self)
{
	return self->face_num;	
}


GLfloat *get_vertex_array(GEOMETRY *self)
{
	return self->vertices;
}


GLfloat *get_normal_array(GEOMETRY *self)
{
	return self->normals;
}


GLuint *get_index_array(GEOMETRY *self)
{
	return self->indices;
}
