#ifndef FUNCTION_RENDER_RENDERLIST_H_
#define FUNCTION_RENDER_RENDERLIST_H_

#include <list>

#include "function_render_renderbase.h"

namespace functionlayer {
namespace render{

class RenderList {
public:
  RenderList();
  ~RenderList();
  void AppendRender(RenderBase* render);
private:
  std::list<RenderBase*> renderlist_;
};

}
}

#endif