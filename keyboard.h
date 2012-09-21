#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdbool.h>
#include <math.h>
#include <GL/glut.h>
#include "mouse.h"
#include "geometry.h"
#include "cube.h"


extern GLfloat position[];
extern GLfloat speed;
extern bool keyStates[];
extern float refresh;


void keyPressed(unsigned char, int, int);

void keyReleased(unsigned char, int, int);

void timer(int);


#endif
