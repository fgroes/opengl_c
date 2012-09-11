#include <stdio.h>
#include <GL/glut.h>
#include "graphics.h"


void init()
{
	printf("initialising opengl ... ");
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glClearColor(1, 1, 1, 1);
	//glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glLight(GL_LIGHT0, GL_POSITION, light_position);
	glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_NORMAL_ARRAY);
	printf("done\n");
}


void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}	


void glTranslatev(GLfloat *v)
{
	glTranslatef(v[0], v[1], v[2]);
}
