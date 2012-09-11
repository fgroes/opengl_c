#include <GL/glut.h>
#include <stdbool.h>
#include "keyboard.h"


GLfloat position[3] = {0, 0, 0};
GLfloat speed = 0.1;
bool keyStates[256];


void keyPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;
}


void keyReleased(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}


void timer(int n)
{
	if (keyStates['w'])
		position[2] += speed;
	if (keyStates['s'])
		position[2] -= speed;
	if (keyStates['d'])
		position[0] -= speed;
	if (keyStates['a'])
		position[0] += speed;
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}	
