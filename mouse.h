#ifndef MOUSE_H
#define MOUSE_H
#include <stdio.h>
#include <stdbool.h>
#include <GL/glut.h>


extern int window_size_x, window_size_y;
extern GLint mouse_move[];
extern float mouse_speed;


void mouseMotion(int, int);


#endif
