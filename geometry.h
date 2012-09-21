#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "math_adv.h"
#include "graphics.h"


extern float cam_height;


struct geometry
{
	GLfloat *vertices, *normals;
	GLuint *faces;
	int vertex_num, face_num;
	float color[3], translation[3], rotation[4];
};

typedef struct geometry GEOMETRY;


void geometry_load_geo_obj(GEOMETRY *, char *);

void geometry_move_minimum(GEOMETRY *, int);

int geometry_get_num_face_coords(GEOMETRY *);

int geometry_get_num_vertices(GEOMETRY *);

int geometry_get_num_faces(GEOMETRY *);

GLfloat *geometry_get_vertex_array(GEOMETRY *);

GLfloat *geometry_get_normal_array(GEOMETRY *);

GLuint *geometry_get_face_array(GEOMETRY *);

void geometry_set_color(GEOMETRY *, float, float, float);

void geometry_translate(GEOMETRY *, float, float, float);

void geometry_rotate(GEOMETRY *, float, float, float, float);

void geometry_draw(GEOMETRY *);


#endif
