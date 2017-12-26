#ifndef LIGHT_H
#define LIGHT_H

#include "header.h"

namespace framework {

class Light {
public:
	void SetAmbientColor(float r, float g, float b, float a);
	void SetDiffuseColor(float r, float g, float b, float a);
	void SetSpecularColor(float r, float g, float b, float a);
	void Enable();
	static void Disable();
protected:
	GLenum mLightIdentifier;
	Light();
};

class DirectionLight : public Light {
public:
	DirectionLight(GLenum light);
	void SetPosition(float x, float y, float z);
};

class PointLight : public Light {
public:
	PointLight(GLenum light);
	void SetPosition(float x, float y, float z);
	void SetConstAttenuation(float v);
	void SetLinearAttenuation(float v);
	void SetQuadricAttenuation(float v);
	void Update(float x, float y, float z);
protected:
	float mPosition[3];
};

class SpotLight : public PointLight {
public:
	SpotLight(GLenum light);
	void SetDirection(float x, float y, float z);
	void SetExponent(float v);
	void SetCutoff(float v);
};

}
#endif
