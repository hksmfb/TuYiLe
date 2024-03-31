#include "function_render_renderbase.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {

void RenderBase::SetShader(corelayer::guid::guid id) {
  shaderid_ = id;
  shader_ = resourcelayer::manager::resourcemanager->GetShader(id);
}

void RenderBase::SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader) {
  shaderid_ = 0;
  shader_ = shader;
}

corelayer::guid::guid RenderBase::GetShaderId() {
  return shaderid_;
}

std::shared_ptr<platformlayer::RHI::Shader> RenderBase::GetShader() {
  return shader_;
}

void RenderBase::SetMesh(corelayer::guid::guid id) {
  meshid_ = id;
  mesh_ = resourcelayer::manager::resourcemanager->GetMesh(id);
}

void RenderBase::SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh) {
  meshid_ = 0;
  mesh_ = mesh;
}

corelayer::guid::guid RenderBase::GetMeshId() {
  return meshid_;
}

std::shared_ptr<platformlayer::RHI::Mesh> RenderBase::GetMesh() {
  return mesh_;
}

corelayer::guid::guid RenderBase::GetTexture() {
  return 0;
}

corelayer::guid::guid RenderBase::GetNormal() {
  return 0;
}

}
}
}