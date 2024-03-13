#ifndef FUNCTION_RENDER_PIPELINE_H_
#define FUNCTION_RENDER_PIPELINE_H_

#include <functional>
#include <vector>

#include "function_render_renderlist.h"

namespace functionlayer {
namespace render {
namespace pipeline {

class RenderPipeline {
 public:
  RenderPipeline();
  ~RenderPipeline();
  void CreateShaderTask(std::function<void()> task);
  void InitShader();
  void ForwardRendering(RenderList* renderlist);
  void DefferedShading(RenderList* renderlist);
  void Shading();
 private:
  std::vector<std::function<void()>> create_shader_tasks_;
};

extern RenderPipeline* renderpipeline;

}
}
}

#endif