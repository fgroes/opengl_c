#include "mouse.h"


GLint mouse_move[2] = {0, 0};
float mouse_speed = 0.5;
GLint mouse_position[2] = {0, 0};
bool warped = false;	// to ignore mouse event produced by glutWarpPointer
int offset = 10;


void mouse_init()
{
	mouse_move[0] = - window_size_x / 2;
	mouse_move[1] = - window_size_y / 2;
}


void mouseMotion(int x, int y)
{
	if (warped == false)
	{
		mouse_move[0] += x - mouse_position[0];
		mouse_move[1] += y - mouse_position[1];
		if (x < offset || x > window_size_x - offset || y < offset || y > window_size_y - offset)
		{
			glutWarpPointer(window_size_x / 2, window_size_y / 2);
			mouse_position[0] = window_size_x / 2;
			mouse_position[1] = window_size_y / 2;
			warped = true;
		}
		else
		{
			mouse_position[0] = x;
			mouse_position[1] = y;
		}
	}
	else
		warped = false;
}
