#include "app.h"
#include "header.h"
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
	}
	virtual void render(double currentTime)
	{
		glClearColor(0.1f, 0.4f, 0.6f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw triangle
		glBegin(GL_TRIANGLES);
		glColor4ub(255, 0, 0, 255); glVertex3f(-0.2f, -0.2f, -2.5f);
		glColor4ub(0, 255, 0, 255); glVertex3f(0.2f, -0.2f, -2.5f);
		glColor4ub(0, 0, 255, 255); glVertex3f(0.f, 0.2f, -2.5f);
		glEnd();

		// draw axis
		glLineWidth(10.f);	
		glBegin(GL_LINES);
		glColor4ub(255, 0, 0, 255); glVertex3f(0.f, 0.f, -2.5f);
		glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.f, -2.5f);

		glColor4ub(0, 255, 0, 255); glVertex3f(0.f, 0.f, -2.5f);
		glColor4ub(0, 255, 0, 255); glVertex3f(0.f, 0.5f, -2.5f);

		glColor4ub(0, 0, 255, 255); glVertex3f(0.f, 0.f, -2.5f);
		glColor4ub(0, 0, 255, 255); glVertex3f(0.f, 0.f, -3.f);
		glEnd();
	}
private:
};

DECLARE_MAIN(Test);
