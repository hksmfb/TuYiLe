#include "function_render_renderlist.h"

namespace functionlayer {
namespace render {

RenderList::RenderList() {

}

RenderList::~RenderList() {

}

void RenderList::AppendRender(RenderBase* render) {
  
}

std::vector<RenderBase*> RenderList::GetRenderList() {
  std::vector<RenderBase*> ret;
  ret.insert(ret.end(),meshrenderlist_.begin(), meshrenderlist_.end());
  return ret;
}

}
}