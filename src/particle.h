#ifndef PARTICLE_H
#define PARTICLE_H

#include "header.h"
#include "vector3.h"

namespace framework {

class Particle {
public:
	Particle();
	void Init(GLubyte r, GLubyte g, GLubyte b, GLubyte a, float life);
	void Draw();
	void Update(float deltaTime);
public:
	GLuint mTexture;
	Vector3f mPosition;
	float mHalfSize;
	float mLifeTime, mLivingTime;
	GLubyte mColor[4];
};

}
#endif
