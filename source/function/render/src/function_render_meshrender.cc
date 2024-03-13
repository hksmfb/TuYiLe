#include "function_render_meshrender.h"

namespace functionlayer {
namespace render {

MeshRender::MeshRender() {

}

MeshRender::~MeshRender() {
  
}

void MeshRender::SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh) {
  mesh_ = mesh;
}

void MeshRender::SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader) {
  shader_ = shader;
}

}
}