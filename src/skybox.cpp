#include "skybox.h"
#include "util.h"

using namespace framework;

void SkyBox::Init(const char *imageDir)
{
	const char *filename[SKY_BOX_TEXTURE_COUNT] = {
		"front.bmp",
		"back.bmp",
		"left.bmp",
		"right.bmp",
		"top.bmp",
		"bottom.bmp",
	};

	char path[256];

	for ( int i = 0; i < SKY_BOX_TEXTURE_COUNT; ++i ) 
	{
		memset(path, 0, 256);
		strcpy(path, imageDir);
		strcat(path, filename[i]);
		mTexture[i] = CreateTextureFromImage(path, false);
	}
	mFastDrawCall = CreateDisplayList([this]() -> void { DrawCommand(); } );
}
void SkyBox::DrawCommand()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture[0]);
	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);
	glTexCoord2f(0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
}
void SkyBox::Draw(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glCallList(mFastDrawCall);
	glPopMatrix();
}
