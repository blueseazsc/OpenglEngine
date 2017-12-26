#include "app.h"
#include "header.h"
#include "util.h"
#include "skybox.h"
#include "model.h"
#include "ground.h"
#include "light.h"
#include "camera.h"

using namespace framework;
class Test:	public Application
{
public:
	Test() : light(GL_LIGHT0), light1(GL_LIGHT1), light2(GL_LIGHT2), light3(GL_LIGHT3) {}
	virtual void startup(double currentTime)
	{
		lastTime = currentTime;

		skyBox.Init("/Users/zhangsc/Downloads/final/MyApp/Res/");

		model.Init("/Users/zhangsc/Downloads/final/MyApp/Res/Sphere.obj");
		model.mTexture = CreateTexture2DFromBMP("/Users/zhangsc/Downloads/final/MyApp/Res/earth.bmp");
		model.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f);
		model.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
		model.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);

		ground.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f);
		ground.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
		ground.SetSpecularMaterial(0.0f, 0.0f, 0.0f, 1.0f);	

		light.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
		light.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
		light.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
		light.SetPosition(0.0f, 1.0f, 0.0f);

		light1.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
		light1.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
		light1.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
		light1.SetPosition(0.0f, 0.0f, 0.0f);
		light1.SetConstAttenuation(1.0f);
		light1.SetLinearAttenuation(0.2f);

		light2.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
		light2.SetDiffuseColor(0.1f, 0.4f, 0.6f, 1.0f);
		light2.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
		light2.SetPosition(0.0f, 0.0f, -30.0f);
		light2.SetConstAttenuation(1.0f);
		light2.SetLinearAttenuation(0.2f);

		light3.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
		light3.SetDiffuseColor(0.0f, 0.8f, 0.0f, 1.0f);
		light3.SetSpecularColor(1.0f, 0.0f, 0.0f, 1.0f);
		light3.SetPosition(10.0f, 50.0f, -30.0f);
		light3.SetDirection(0.0f, -1.0f, 0.0f);
		light3.SetExponent(5.0f);
		light3.SetCutoff(10.0f);

		camera.mViewportWidth = info.windowWidth;
		camera.mViewportHeight = info.windowHeight;
	}
	virtual void render(double currentTime)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.SwitchTo3D();
		camera.Update(currentTime - lastTime);
		lastTime = currentTime;

		skyBox.Draw(camera.mPos.x, camera.mPos.y, camera.mPos.z);

		// light.Enable();
		light1.Enable();
		light1.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);
		light2.Enable();
		light2.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);
		light3.Enable();
		light3.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);

		ground.Draw();
		model.Draw();

		camera.SwitchTo2D();
	}
    virtual void onKey(int key, int action)
    {
		bool value = false;
		switch (action) {
			case GLFW_PRESS:
				value = true;
				break;
			case GLFW_RELEASE:
				value = false;
				break;
			case GLFW_REPEAT:
				return;
				break;
		}

		switch (key) {
			case GLFW_KEY_A:
				break;
			case GLFW_KEY_D:
				break;
			case GLFW_KEY_W:
				break;
			case GLFW_KEY_S:
				break;
			default:
				break;
		}
    }
    virtual void onMouseButton(int button, int action)
    {
		switch (action) {
			case GLFW_PRESS:
				getMousePosition(lastMousePosX, lastMousePosY);
				rotateView = true;
				break;
			case GLFW_RELEASE:
				rotateView = false;
				break;
			default:
				break;
		}

    }

    virtual void onMouseMove(int x, int y)
    {
		if ( rotateView ) {
			float angleRotateByRight = (y - lastMousePosY)/ 1000.0f;
			float angleRotateByUp = (x - lastMousePosX) / 1000.0f;
			camera.Pitch(angleRotateByRight);
			camera.Yaw(angleRotateByUp);

			lastMousePosX = x;
			lastMousePosY = y;
		}
    }
private:
	Camera camera;
	SkyBox skyBox;
	Model model;
	Ground ground;

	DirectionLight light;
	PointLight light1;
	PointLight light2;
	SpotLight light3;
private:
	bool rotateView;
	int lastMousePosX;
	int lastMousePosY;
private:
	double lastTime;
};

DECLARE_MAIN(Test);
