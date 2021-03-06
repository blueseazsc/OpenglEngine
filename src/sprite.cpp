#include "sprite.h"
#include "util.h"

using namespace framework;

void Sprite2D::SetImage(const char *imagePath) {
	mTexture = CreateTextureFromImage(imagePath);
}
void Sprite2D::SetRect(float x, float y, float width, float height) {
	mVertexes[0].x = x;
	mVertexes[0].y = y;
	mVertexes[1].x = x + width;
	mVertexes[1].y = y;
	mVertexes[2].x = x + width;
	mVertexes[2].y = y + height;
	mVertexes[3].x = x;
	mVertexes[3].y = y + height;
}
void Sprite2D::Draw() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glColor4ub(255, 255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(mVertexes[0].x, mVertexes[0].y, mVertexes[0].z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(mVertexes[1].x, mVertexes[1].y, mVertexes[1].z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(mVertexes[2].x, mVertexes[2].y, mVertexes[2].z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(mVertexes[3].x, mVertexes[3].y, mVertexes[3].z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
