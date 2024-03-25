#include "function_render_meshrender.h"

namespace functionlayer {
namespace render {

MeshRender::MeshRender() {

}

MeshRender::~MeshRender() {
  
}

void MeshRender::Draw() {
  mesh_->Draw();
}

}
}