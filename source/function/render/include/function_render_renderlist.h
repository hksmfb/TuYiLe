#ifndef FUNCTION_RENDER_RENDERLIST_H_
#define FUNCTION_RENDER_RENDERLIST_H_

#include <list>

#include "function_render_renderbase.h"
#include "function_render_meshrender.h"
#include "core_guid_manager.h"

namespace functionlayer {
namespace render{

class RenderList {
public:
  RenderList();
  ~RenderList();
  void AppendRender(RenderBase* render);
  std::vector<corelayer::guid> GetShaderList();
  std::vector<RenderBase*> GetRenderList();
  std::list<MeshRender*>& GetMeshRenderList();
  std::vector<corelayer::guid> GetShaderList();
  std::vector<corelayer::guid> GetMeshList();
private:
  std::vector<RenderBase*> renderlist_;
  std::list<MeshRender*> meshrenderlist_;
  std::vector<corelayer::guid> shaderlist_;
  std::vector<corelayer::guid> meshlist_;
};

}
}

#endif