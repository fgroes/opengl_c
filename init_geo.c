#include "init_geo.h"


LLIST list_geos;	


void init_geo()
{
	llist_init(&list_geos);
	GEOMETRY *g;
	g = malloc(sizeof(GEOMETRY));
	geometry_load_geo_obj(g, "./Models/eiffel.obj");
	geometry_move_minimum(g, 2);
	geometry_translate(g, 0, cam_height, 0);
	geometry_rotate(g, 270, 1, 0, 0);
	geometry_set_color(g, 1, 0.5, 0);
	llist_add_element(&list_geos, g);
	TEXTURE t;
	texture_load(&t, "HeNe.bmp");
	texture_bind(&t);
	/*
	g = malloc(sizeof(GEOMETRY));
	geometry_load_geo_obj(g, "./Models/eiffel.obj");
	geometry_translate(g, 0, 0, 0);
	geometry_rotate(g, 90, 1, 0, 0);
	geometry_set_color(g, 0, 0.5, 1.0);
	llist_add_element(&list_geos, g);
	*/
}
