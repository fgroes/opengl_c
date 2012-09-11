#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <GL/glut.h>


extern GLfloat position[];
extern GLfloat speed;
extern bool keyStates[];


void keyPressed(unsigned char, int, int);

void keyReleased(unsigned char, int, int);

void timer(int);


#endif
