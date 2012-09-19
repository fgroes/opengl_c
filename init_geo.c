#include "init_geo.h"


void init_geo()
{
	geometry_load_geo_obj(&g, "./Models/eiffel.obj");
	geometry_translate(&g, 0, -100, 0);
	geometry_rotate(&g, 270, 1, 0, 0);
	geometry_set_color(&g, 1, 0.5, 0);
}
