#ifndef PLATFORM_RHI_RHI_H_
#define PLATFORM_RHI_RHI_H_

#include <memory>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "platform_data_datatype.h"
#include "platform_rhi_glinterface.h"
#include "platform_rhi_opengl_mesh.h"
#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace RHI {

extern graphicinterface::GLInterface* interface;

void SetViewport(int posx, int posy, int width, int height);
void ClearColor(int R, int G, int B, float Alpha);
Mesh* CreateMesh(datatype::Mesh& mesh);
std::shared_ptr<Shader> CreateShader(std::string vertex, std::string fragment);

void DepthTest(bool b);
void WireframeMode(bool b);
void ClearScreen();
int GetViewportHeight();
int GetViewportWidth();

}
}

#endif