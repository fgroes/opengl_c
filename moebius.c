#include "moebius.h"


void moebius_parametrization(float *cartesian, float radius, float angle)
{
	cartesian[0] = cos(angle) * (1 + radius / 2 * cos(angle / 2));
	cartesian[1] = sin(angle) * (1 + radius / 2 * cos(angle / 2));
	cartesian[2] = radius / 2 * sin(angle / 2);
}


float *moebius_draw(int radius_num, int angle_num)
{
	int i, j;
	float r, a;
	float moebius = malloc(3 * radius_num * angle_num * sizeof(float));
	for (i = 0; i < radius_num; i++)
	{
		for (j = 0; j < angle_num; j++)
		{
			r = -1.0 + 2.0 / (radius_num - 1) * i;
			a = 2 * M_PI / angle_num * j;
			moebius_parametrization(moebius + 3 * radius_num * i + 3 * j, r, a);
		}
}
