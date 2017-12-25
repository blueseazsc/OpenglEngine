#include "util.h"

using namespace framework;

GLuint CreateTextureFromImage(const char *imgFilePath, bool invertY) 
{
	unsigned int flags = SOIL_FLAG_POWER_OF_TWO;
	if ( invertY )
		flags |= SOIL_FLAG_INVERT_Y;

	return SOIL_load_OGL_texture(imgFilePath, 0, 0, flags);
}
