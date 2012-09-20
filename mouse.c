#include "mouse.h"


GLint mouse_position[2] = {0, 0};
bool mouse;


void mouseMotion(int x, int y)
{
	if (mouse == true)
	{
		mouse_position[0] = x - mouse_position[0];
		mouse_position[1] = y - mouse_position[1];
		if (x < 10 || x > 790 || y < 10 || y > 590)
			glutWarpPointer(400, 300);
			mouse = false;
	}
	else
		mouse = true;
	//printf("(%d, %d)\n", mouse_position[0], mouse_position[1]);	
}
