#include "app.h"
#include "header.h"
#include "util.h"
#include "skybox.h"

using namespace framework;
class Test:	public Application
{
public:
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

		texture = CreateTextureFromImage("/Users/zhangsc/Downloads/final/MyApp/Res/head.png", true);

		skyBox.Init("/Users/zhangsc/Downloads/final/MyApp/Res/");
	}
	virtual void render(double currentTime)
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		skyBox.Draw(0.f,0.f,0.f);
	}
private:
	GLuint texture;
	SkyBox skyBox;
};

DECLARE_MAIN(Test);
