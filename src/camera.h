#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

namespace framework {

class Camera {
public:
	Camera();
	void Update(float deltaTime);
	void Pitch(float angle);
	void Yaw(float angle);
	void RotateView(float angle, float x, float y, float z);
	void SwitchTo3D();
	void SwitchTo2D();
public:
	Vector3f mPos, mViewCenter, mUp;
	bool mbMoveLeft, mbMoveRight, mbMoveForward, mbMoveBack;
	int mViewportWidth, mViewportHeight;
};
}
#endif
