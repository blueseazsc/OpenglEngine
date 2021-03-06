#ifndef MODEL_H
#define MODEL_H

#include "header.h"

namespace framework {

struct VertexData {
	float position[3];
	float normal[3];
	float texcoord[2];
};

class Model {
public:
	GLuint mTexture;
	Model();
	void Init(const char *modelPath);
	void Draw();
	void SetAmbientMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);
protected:
	VertexData *mVertexes;
	unsigned short *mIndexes;
	int mIndexCount;
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];
};
}
#endif
