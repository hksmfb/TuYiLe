#include "platform_rhi_rhi.h"

namespace platformlayer {
namespace RHI {

graphicinterface::GLInterface* interface = nullptr;

void SetViewport(int posx, int posy, int width, int height) {
  interface->SetViewport(posx, posy, width, height);
}

void ClearColor(int R, int G, int B, float Alpha) {
  interface->ClearColor(R, G, B, Alpha);
}

std::shared_ptr<Mesh> CreateMesh(datatype::Mesh mesh) {
  printf("todo\n");
  return nullptr;
}

std::shared_ptr<Shader> CreateShader(std::string vertex, std::string fragment) {
  printf("todo\n");
  // if (interface->GetInterfaceName() == std::string("OpenGL")) {
  //   return std::make_shared<graphicinterface::opengl::OpenGLShader>(vertex, fragment);
  // } else {
  //   return nullptr;
  // }
  return nullptr;
}

void AppendMeshBatch(datatype::Mesh mesh, std::shared_ptr<RHI::Mesh>* dest) {
  interface->AppendMesh(mesh, dest);
}

void CreateMeshBatch() {
  interface->CreateMeshBatch();
}

void AppendShaderBatch(datatype::shadercode shadercode, std::shared_ptr<Shader>* dest) {
  interface->AppendShader(shadercode, dest);
}

void CreateShaderBatch() {
  interface->CreateShaderBatch();
}

}
}