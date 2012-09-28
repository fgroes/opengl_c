#include "math_adv.h"


static int N = 3;


void add(float *a, float *b, float *c)
{
	int i;
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];
}


void sub(float *a, float *b, float *c)
{
	int i;
	for (i = 0; i < N; i++)
		c[i] = a[i] - b[i];
}


void normalize(float *a)
{
	float c;
	int i;
	c = 1.0 / sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	for (i = 0; i < N; i++)
		a[i] *= c;
}


void cross(float *a, float *b, float *c)
{
	c[0] += a[1] * b[2] - a[2] * b[1];
	c[1] += a[2] * b[0] - a[0] * b[2];
	c[2] += a[0] * b[1] - a[1] * b[0];
}


void vertex_copy(float *x, float *y, int N)
{
	int i;
	for (i = 0; i < N; i++) 
		x[i] = y[i];
}
