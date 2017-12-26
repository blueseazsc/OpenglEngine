#ifndef SKYBOX_H
#define SKYBOX_H

#include "header.h"

namespace framework {

class SkyBox {
public:
	enum {
		SKY_BOX_TEXTURE_COUNT = 6,
	};
	void Init(const char *imageDir);
	void DrawCommand();
	void Draw(float x, float y, float z);

protected:
	GLuint mTextures[SKY_BOX_TEXTURE_COUNT];
	GLuint mFastDrawCall;
};
}
#endif
