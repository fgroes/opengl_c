#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <stdbool.h>


struct geometry
{
	GLfloat *vertices, *normals;
	GLuint *indices;
	int vertex_num, face_num;
};

typedef struct geometry GEOMETRY;


void load_geo_obj(GEOMETRY *, char *);

int get_num_face_coords(GEOMETRY *);

int get_num_vertices(GEOMETRY *);

int get_num_faces(GEOMETRY *);

GLfloat *get_vertex_array(GEOMETRY *);

GLfloat *get_normal_array(GEOMETRY *);

GLuint *get_index_array(GEOMETRY *);


#endif
