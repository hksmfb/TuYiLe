#include "function_render_renderlist.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {

RenderList::RenderList() {

}

RenderList::~RenderList() {

}

void RenderList::clear() {
  renderlist_.clear();
  renderdatalist_.clear();
}

void RenderList::AppendRender(RenderBase* render) {
  renderlist_.push_back(render);
  renderdata newdata = render->GetRenderData();
  renderdatalist_.push_back(newdata);
}

std::vector<RenderBase*> RenderList::GetRenderList() {
  std::vector<RenderBase*> ret;
  ret.insert(ret.end(),renderlist_.begin(), renderlist_.end());
  return ret;
}

std::vector<renderdata> RenderList::GetRenderData() {
  return renderdatalist_;
}

}
}
}