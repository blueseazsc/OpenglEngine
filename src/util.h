#ifndef UTILS_H
#define UTILS_H

#include "header.h"

namespace framework {

GLuint CreateTextureFromImage(const char *imgFilePath, bool invertY);
GLuint CreateDisplayList(std::function<void()> func);
}
#endif
