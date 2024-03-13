#ifndef FUNCTION_RENDER_RENDERLIST_H_
#define FUNCTION_RENDER_RENDERLIST_H_

#include <list>

#include "function_render_renderbase.h"
#include "function_render_meshrender.h"

namespace functionlayer {
namespace render{

class RenderList {
public:
  RenderList();
  ~RenderList();
  void AppendRender(RenderBase* render);
  std::list<RenderBase*>& GetRenderList();
  std::list<MeshRender*>& GetMeshRenderList();
private:
  std::list<RenderBase*> renderlist_;
  std::list<MeshRender*> meshrenderlist_;
};

}
}

#endif