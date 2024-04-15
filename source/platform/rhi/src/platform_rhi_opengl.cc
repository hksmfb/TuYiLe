#include "platform_rhi_opengl.h"

namespace TuYiLe{
namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLInterface::OpenGLInterface() {
  interfacename_ = "OpenGL";
}

OpenGLInterface::~OpenGLInterface() {

}

void OpenGLInterface::WindowInit() {

}

void OpenGLInterface::ClearColor(int R, int G, int B, float Alpha) {
  glClearColor(R/255.0f, G/255.0f, B/255.0f, Alpha);
  glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLInterface::SetViewport(int posx, int posy, int width, int height) {
  glViewport(posx, posy, width, height);
  viewport_posx_ = posx;
  viewport_posy_ = posy;
  viewport_width_ = width;
  viewport_height_ = height;
}

int OpenGLInterface::GetViewportPosx() {
  return viewport_posx_;
}

int OpenGLInterface::GetViewportPosy() {
  return viewport_posy_;
}

int OpenGLInterface::GetViewportWidth() {
  return viewport_width_;
}

int OpenGLInterface::GetViewportHieght() {
  return viewport_width_;
}

std::shared_ptr<RHI::Mesh> OpenGLInterface::CreateMesh(datatype::Mesh mesh) {
  return std::make_shared<graphicinterface::opengl::OpenGLMesh>(mesh);
}

std::shared_ptr<RHI::Shader> OpenGLInterface::CreateShader(datatype::shadercode shadercode) {
  return std::make_shared<graphicinterface::opengl::OpenGLShader>(
    shadercode.vertex_shader_code, shadercode.fragment_shader_code
  );
}

}
}
}
}