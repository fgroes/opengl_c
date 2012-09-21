#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <stdio.h>
#include <GL/glut.h>


extern int window_size_x, window_size_y;


void init();

void reshape(int, int);

void glTranslatev(GLfloat *);


#endif
