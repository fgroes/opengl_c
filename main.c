#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>
#include <GL/glut.h>
#include "graphics.h"
#include "keyboard.h"
#include "llist.h"
#include "geometry.h"
#include "init_geo.h"


void display()
{
	GEOMETRY *g;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 0, 0, 0, -100, 0, 1, 0);
	for (g = llist_start(&list_geos); llist_end(&list_geos); g = llist_next(&list_geos))
	{
		glPushMatrix();
		glTranslatev(position);
		geometry_draw((GEOMETRY *)g);
		glPopMatrix();
	}
	glutSwapBuffers();
}	


void draw(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("fps");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);
	glutTimerFunc(20, timer, 0);
	glutMainLoop();
}


int main(int argc, char **argv)
{
	init_geo();
	draw(argc, argv);
	llist_delete(&list_geos);
	return 0;
}
