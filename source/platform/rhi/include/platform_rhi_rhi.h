#ifndef PLATFORM_RHI_RHI_H_
#define PLATFORM_RHI_RHI_H_

#include <array>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "platform_rhi_glinterface.h"
#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace RHI {

extern graphicinterface::GLInterface* interface;

void SetViewport(int posx, int posy, int width, int height);
void ClearColor(int R, int G, int B, float Alpha);
Shader* CreateShader(std::string vertex, std::string fragment);

void DepthTest(bool b);
void WireframeMode(bool b);
void ClearScreen();
int GetViewportHeight();
int GetViewportWidth();

}
}

#endif