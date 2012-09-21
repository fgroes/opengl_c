#include "keyboard.h"


GLfloat position[3] = {0, 0, 0};
GLfloat speed = 1.0;
bool keyStates[256];
float deg2rad = M_PI / 180.0;
float refresh = 20.0;	// refresh rate for scene action


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
		GEOMETRY *g;
		g = malloc(sizeof(GEOMETRY));
		cube_draw(g, 2.0);
		geometry_translate(g, - position[0], - position[1] + cam_height, - position[2]);
		geometry_set_color(g, 1, 0, 0);
		llist_add_element(&list_geos, g);
	}
	glutPostRedisplay();
	glutTimerFunc(refresh, timer, 0);
}	
