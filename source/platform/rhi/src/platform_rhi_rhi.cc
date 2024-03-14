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
  if (interface->GetInterfaceName() == std::string("OpenGL")) {
    auto ret = std::make_shared<graphicinterface::opengl::OpenGLMesh>();
    ret->SetIndex(mesh.GetIndex());
    ret->SetVertex(mesh.GetVertex());
    return ret;
  } else {
    return nullptr;
  }
}

std::shared_ptr<Shader> CreateShader(std::string vertex, std::string fragment) {
  if (interface->GetInterfaceName() == std::string("OpenGL")) {
    return std::make_shared<graphicinterface::opengl::OpenGLShader>(vertex, fragment);
  } else {
    return nullptr;
  }
}

void AppendMeshBatch(datatype::Mesh mesh) {
  interface->AppendMesh(mesh);
}

std::list<std::shared_ptr<Mesh>> CreateMeshBatch() {
  std::list<std::shared_ptr<Mesh>> ret;
  auto meshlist = interface->GetTempMeshList();
  for (auto& mesh : meshlist) {
    ret.push_back(interface->CreateMesh(mesh));
  }
  return ret;
}

void AppendShaderBatch(datatype::shadercode shadercode) {
  interface->AppendShader(shadercode);
}

std::list<std::shared_ptr<Shader>> CreateShaderBatch() {
  std::list<std::shared_ptr<Shader>> ret;
  auto shaderlist = interface->GetTempShaderSourceList();
  for (auto& shader : shaderlist) {
    ret.push_back(interface->CreateShader(shader));
  }
  return ret;
}

}
}