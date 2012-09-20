#include "mouse.h"


GLint mouse_move[2] = {0, 0};
GLint mouse_position[2] = {0, 0};
bool mouse;
int offset = 10;


void mouseMotion(int x, int y)
{
	if (mouse == true)
	{
		mouse_move[0] = x - mouse_position[0];
		mouse_move[1] = y - mouse_position[1];
		if (x < offset || x > window_size_x - offset || y < offset || y > window_size_y - offset)
		{
			glutWarpPointer(window_size_x / 2, window_size_y / 2);
			mouse_position[0] = window_size_x / 2;
			mouse_position[1] = window_size_y / 2;
			mouse = false;
		}
		else
		{
			mouse_position[0] = x;
			mouse_position[1] = y;
		}
	}
	else
		mouse = true;
	printf("(%d, %d)\n", mouse_move[0], mouse_move[1]);	
}
