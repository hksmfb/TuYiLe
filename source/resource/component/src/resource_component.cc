#include "resource_component.h"

namespace resourcelayer {

Component::Component() {

}

Component::~Component() {

}

void Component::SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh) {
  mesh_ = mesh;
}

std::shared_ptr<platformlayer::RHI::Mesh> Component::GetMesh() {
  return mesh_;
}

void Component::SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader) {
  shader_ = shader;
}

std::shared_ptr<platformlayer::RHI::Shader> Component::Getshader() {
  return shader_;
}

}