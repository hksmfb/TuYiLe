#include "platform_rhi_rhi.h"

namespace TuYiLe{
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
  return interface->CreateMesh(mesh);
}

std::shared_ptr<Shader> CreateShader(datatype::shadercode code) {
  interface->CreateShader(code);
  return interface->CreateShader(code);;
}

std::shared_ptr<Shader> CreateShader(std::string vertex, std::string fragment) {
  datatype::shadercode code;
  code.vertex_shader_code = vertex;
  code.fragment_shader_code = fragment;
  interface->CreateShader(code);
  return interface->CreateShader(code);;
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
}