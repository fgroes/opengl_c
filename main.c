#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
#include <GL/glut.h>


GLfloat position[3] = {0, 0, 0};
GLfloat speed = 0.1;
bool keyStates[256];


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
	//glEnableClientState(GL_VERTEX_ARRAY);
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
	glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, -3);
		glVertex3f(0, 1, -3);
		glVertex3f(1, 0.5, -3);
		glColor3f(1, 0.5, 0);
		glVertex3f(-2, -2, -8);
		glVertex3f(2, -2, -8);
		glVertex3f(0, 2, -8);
	glEnd();
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


int main(int argc, char **argv)
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
	return 0;
}
