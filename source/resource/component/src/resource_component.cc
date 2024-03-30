#include "resource_component_componentbase.h"

namespace resourcelayer {

ComponentBase::ComponentBase() {

}

ComponentBase::~ComponentBase() {

}

void ComponentBase::SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh) {
  mesh_ = mesh;
}

std::shared_ptr<platformlayer::RHI::Mesh> ComponentBase::GetMesh() {
  return mesh_;
}

void ComponentBase::SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader) {
  shader_ = shader;
}

std::shared_ptr<platformlayer::RHI::Shader> ComponentBase::Getshader() {
  return shader_;
}

}