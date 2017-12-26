#include "app.h"
#include "header.h"
#include "util.h"
#include "skybox.h"
#include "model.h"
#include "ground.h"
#include "light.h"

using namespace framework;
class Test:	public Application
{
public:
	Test() : light(GL_LIGHT0), light1(GL_LIGHT1), light2(GL_LIGHT2), light3(GL_LIGHT3) {}
	virtual void startup()
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);
		gluPerspective(50.f, (float)info.windowWidth / (float)info.windowHeight, 0.1f, 1000.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

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
	}
	virtual void render(double currentTime)
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		skyBox.Draw(0.f,0.f,0.f);

		light.Enable();
		// light1.Enable();
		// light1.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);
		// light2.Enable();
		// light2.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);
		// light3.Enable();
		// light3.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);

		ground.Draw();
		model.Draw();
	}
private:
	SkyBox skyBox;
	Model model;
	Ground ground;

	DirectionLight light;
	PointLight light1;
	PointLight light2;
	SpotLight light3;
};

DECLARE_MAIN(Test);
