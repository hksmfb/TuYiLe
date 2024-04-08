#ifndef FUNCTION_RENDER_MESRENDER_H_
#define FUNCTION_RENDER_MESRENDER_H_

#include <memory>
#include <unordered_map>
#include <string>

#include "function_render_renderbase.h"
#include "platform_data_datatype.h"
#include "platform_rhi_rhi.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {
class MeshRender : public RenderBase{
 public:
  MeshRender();
  ~MeshRender();
  void SetTexture(platformlayer::datatype::Texture* texture);
  void Draw();
  void DrawInstance();
 private:
  platformlayer::datatype::Texture* texture_;
};

}
}
}

#endif