#ifndef FUNCTION_RENDER_RENDERLIST_H_
#define FUNCTION_RENDER_RENDERLIST_H_

#include <list>

#include "function_render_renderbase.h"
#include "function_render_meshrender.h"
#include "core_guid_manager.h"

namespace TuYiLe {
namespace functionlayer {
namespace render{

class RenderList {
public:
  RenderList();
  ~RenderList();
  void clear();
  void AppendRender(RenderBase* render);
  std::vector<RenderBase*> GetRenderList();
  std::list<MeshRender*>& GetMeshRenderList();
  std::vector<renderdata> GetRenderData();
  std::vector<corelayer::guid::guid> GetShaderList();
  std::vector<corelayer::guid::guid> GetMeshList();
private:
  std::vector<RenderBase*> renderlist_;
  std::vector<renderdata> renderdatalist_;
  std::list<MeshRender*> meshrenderlist_;
  std::vector<corelayer::guid::guid> shaderlist_;
  std::vector<corelayer::guid::guid> meshlist_;
};

}
}
}

#endif