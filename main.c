#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <GL/glut.h>
#include "graphics.h"
#include "keyboard.h"
#include "mouse.h"
#include "llist.h"
#include "geometry.h"
#include "init_geo.h"


void display()
{
	GEOMETRY *g;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 0, 0, 0, -100, 0, 1, 0);
	glLoadIdentity();
	glRotatef(mouse_move[0] * mouse_speed, 0, 1, 0);
	glTranslatev(position);
	for (g = llist_start(&list_geos); llist_end(&list_geos); g = llist_next(&list_geos))
	{
		glPushMatrix();
		geometry_draw((GEOMETRY *)g);
		glPopMatrix();
	}
	glutSwapBuffers();
}	


void draw(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(window_size_x, window_size_y);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("fps");
	init();
	mouse_init();
	glutSetCursor(GLUT_CURSOR_NONE);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);
	glutPassiveMotionFunc(mouseMotion);
	glutTimerFunc(refresh, timer, 0);
	glutMainLoop();
}


int main(int argc, char **argv)
{
	init_geo();
	draw(argc, argv);
	llist_delete(&list_geos);
	return 0;
}
