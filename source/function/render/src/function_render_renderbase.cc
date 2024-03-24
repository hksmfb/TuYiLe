#include "function_render_renderbase.h"

namespace functionlayer {
namespace render {

corelayer::guid RenderBase::GetShader() {
  return shader_;
}

corelayer::guid RenderBase::GetMesh() {
  return mesh_;
}

corelayer::guid RenderBase::GetTexture() {
  return 0;
}

corelayer::guid RenderBase::GetNormal() {
  return 0;
}

}
}