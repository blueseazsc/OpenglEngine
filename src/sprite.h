#ifndef SPRITE_H
#define SPRITE_H

#include "header.h"
#include "vector3.h"

namespace framework {

class Sprite2D {
public:
	void SetImage(const char *imagePath);
	void SetRect(float x, float y, float width, float height);
	void Draw();
protected:
	GLuint mTexture;
	Vector3f mVertexes[4];
};
}
#endif
