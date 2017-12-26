#ifndef GROUND_H
#define GROUND_H

#include "header.h"

namespace framework {

class Ground {
public:
	void Draw();
	void SetAmbientMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);
protected:
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];
};
}
#endif 
