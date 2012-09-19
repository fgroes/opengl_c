#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>
#include <GL/glut.h>
#include "graphics.h"
#include "keyboard.h"
#include "llist.h"
#include "geometry.h"


GEOMETRY g;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 0, 0, 0, -100, 0, 1, 0);
	glPushMatrix();
	glTranslatev(position);
	glTranslatef(0, -100, 0);
	glRotatef(270, 1, 0, 0);
	glColor3f(1, 0.5, 0);
	glVertexPointer(3, GL_FLOAT, 0, get_vertex_array(&g));
	glNormalPointer(GL_FLOAT, 0, get_normal_array(&g));
	glDrawElements(GL_TRIANGLES, get_num_face_coords(&g), GL_UNSIGNED_INT, get_index_array(&g));
	glPopMatrix();
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
	load_geo_obj(&g, "./Models/eiffel.obj");
	draw(argc, argv);
	return 0;
}
