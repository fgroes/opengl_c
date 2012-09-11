#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
#include <GL/glut.h>
#include "graphics.h"
#include "keyboard.h"
#include "llist.h"


static GLfloat vertices[] = {0, 0, -3, 0, 1, -3, 1, 0.5, -3, -2, -2, -8, 2, -2, -8, 0, 2, -8};
static GLubyte indices[] = {0, 1, 2, 3, 4, 5};


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, 0, 0, 0, -100, 0, 1, 0);
	glPushMatrix();
	glTranslatev(position);
	glColor3f(1, 0.5, 0);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
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


int main(int argc, char **argv)
{
	testlist();
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
	return 0;
}
