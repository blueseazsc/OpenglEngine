#include "app.h"
#include "header.h"
#include "util.h"

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

		texture = CreateTextureFromImage("/Users/zhangsc/Downloads/final/MyApp/Res/earth.bmp", true);
	}
	virtual void render(double currentTime)
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw triangle
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_TRIANGLES);
		glColor4ub(255, 255, 255, 255); 
		glTexCoord2f(0.f, 0.f);
		glVertex3f(-0.2f, -0.2f, -2.5f);
		glTexCoord2f(1.f, 0.f);
		glVertex3f(0.2f, -0.2f, -2.5f);
		glTexCoord2f(0.5f, 1.f);
		glVertex3f(0.f, 0.2f, -2.5f);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);

		// draw axis
		glLineWidth(2.f);	
		glBegin(GL_LINES);
		glColor4ub(255, 0, 0, 255); 
		glVertex3f(0.f, 0.f, -2.5f);
		glVertex3f(0.5f, 0.f, -2.5f);

		glColor4ub(0, 255, 0, 255); 
		glVertex3f(0.f, 0.f, -2.5f);
		glVertex3f(0.f, 0.5f, -2.5f);

		glColor4ub(0, 0, 255, 255); 
		glVertex3f(0.f, 0.f, -2.5f);
		glVertex3f(0.f, 0.f, -3.f);
		glEnd();

	}
private:
	GLuint texture;
};

DECLARE_MAIN(Test);
