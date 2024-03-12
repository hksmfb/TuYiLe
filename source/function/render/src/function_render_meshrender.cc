#include "function_render_meshrender.h"

namespace functionlayer {
namespace render {

MeshRender::MeshRender() {

}

MeshRender::~MeshRender() {
  
}

void MeshRender::SetMesh(platformlayer::datatype::Mesh* mesh) {
  if (mesh_ != nullptr) {
    delete mesh_;
  }
  mesh_ = platformlayer::RHI::CreateMesh(*mesh);
}

void MeshRender::SetShader(platformlayer::RHI::Shader* shader) {
  shader_ = shader;
}

}
}