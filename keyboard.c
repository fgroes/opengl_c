#include "keyboard.h"


GLfloat position[3] = {0, 0, 0};
GLfloat speed = 2.0;
bool keyStates[256];
float deg2rad = M_PI / 180.0;


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
	float angle = mouse_move[0] * mouse_speed * deg2rad;
	if (keyStates['w'])
	{
		position[0] -= speed * sin(angle);
		position[2] += speed * cos(angle);
	}
	if (keyStates['s'])
	{
		position[0] += speed * sin(angle);
		position[2] -= speed * cos(angle);
	}
	if (keyStates['d'])
	{
		position[0] -= speed * cos(angle);
		position[2] -= speed * sin(angle);
	}
	if (keyStates['a'])
	{
		position[0] += speed * cos(angle);
		position[2] += speed * sin(angle);
	}
	if (keyStates['b'])
	{
		cube_draw(position);
	}
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}	
