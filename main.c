#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
#include <GL/glut.h>
#include "llist.h"


GLfloat position[3] = {0, 0, 0};
GLfloat speed = 0.1;
bool keyStates[256];
static GLfloat vertices[] = {0, 0, -3, 0, 1, -3, 1, 0.5, -3, -2, -2, -8, 2, -2, -8, 0, 2, -8};
static GLubyte indices[] = {0, 1, 2, 3, 4, 5};


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

void testlist()
{
	LLIST l;
	llist_init(&l);
	struct test 
	{
		int a; 
		float b;
	};
	struct test r, s, t;
	r.a = 7;
	r.b = 7.781;
	llist_add_element(&l, &r);
	s.a = 12;
	s.b = 0.341;
	llist_add_element(&l, &s);
	t.a = 8;
	t.b = 25.8;
	llist_add_element(&l, &t);
	printf("%d\n", l.len);
	struct test *x;
	void *i;
	for (i = llist_start(&l); llist_end(&l); i = llist_get_next(&l))
	{
 		x = (struct test *)i;
		printf("%d\n", x->a);
		printf("%f\n", x->b);
	}
	llist_delete(&l);
}


int main(int argc, char **argv)
{
	testlist();
	/*
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
	*/
	return 0;
}
