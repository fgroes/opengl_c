#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <GL/glut.h>


extern GLfloat position[];
extern GLfloat speed;
extern bool keyStates[];


void keyPressed(unsigned char key, int x, int y);

void keyReleased(unsigned char key, int x, int y);

void timer(int n);


#endif
