#include "util.h"
#include <SOIL.h>

namespace framework {

GLuint CreateTextureFromImage(const char *imgFilePath, bool invertY) 
{
	unsigned int flags = SOIL_FLAG_POWER_OF_TWO;
	if ( invertY )
		flags |= SOIL_FLAG_INVERT_Y;

	return SOIL_load_OGL_texture(imgFilePath, 0, 0, flags);
}

GLuint CreateDisplayList(std::function<void()> func)
{
	GLuint displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);
	func();
	glEndList();
	return displayList;
}

}

