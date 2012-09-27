#include "texture.h"


void texture_load(TEXTURE *self, char *filename)
{
	//self->texture = NULL;
	self->tex = SOIL_load_OGL_texture(filename, 
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (self->tex == 0)
		printf("error: '%s' not a valid texture file\n", filename);
}


void texture_bind(TEXTURE *self)
{
	glBindTexture(GL_TEXTURE_2D, self->tex);
}
