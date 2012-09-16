#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>
#include <GL/glut.h>
#include "graphics.h"
#include "keyboard.h"
#include "llist.h"
#include "load_geo_obj.h"


int N;
GLfloat *vertices;
GLfloat *normals;
GLuint *indices;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 0, 0, 0, -100, 0, 1, 0);
	glPushMatrix();
	glTranslatev(position);
	glTranslatef(0, -100, 0);
	glRotatef(270, 1, 0, 0);
	glColor3f(1, 0.5, 0);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normals);
	glDrawElements(GL_TRIANGLES, N, GL_UNSIGNED_INT, indices);
	glPopMatrix();
	glutSwapBuffers();
}	


void testlist()
{
	LLIST l;
	llist_init(&l);
	struct test 
	{
		int a; 
		float b;
	};
	struct test *r, *s, *t;
	r = malloc(sizeof(struct test));
	s = malloc(sizeof(struct test));
	t = malloc(sizeof(struct test));
	r->a = 7;
	r->b = 7.781;
	llist_add_element(&l, r);
	s->a = 12;
	s->b = 0.341;
	llist_add_element(&l, s);
	t->a = 8;
	t->b = 25.8;
	llist_add_element(&l, t);
	printf("%d\n", l.len);
	struct test *x;
	void *i;
	for (i = llist_start(&l); llist_end(&l); i = llist_next(&l))
	{
 		x = (struct test *)i;
		printf("%d\n", x->a);
		printf("%f\n", x->b);
	}
	x = (struct test *)llist_get_element(&l, 0);
	printf("%d\n", x->a);
	printf("%f\n", x->b);
	llist_delete(&l);
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
	load_geo_obj("./Models/eiffel.obj");
	//testlist();
	draw(argc, argv);
	return 0;
}
