#ifndef FUNCTION_RENDER_PIPELINE_H_
#define FUNCTION_RENDER_PIPELINE_H_

#include <functional>
#include <vector>
#include <map>

#include "core_thread_manager.h"
#include "function_render_renderlist.h"
#include "function_render_resourceloader.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {
namespace pipeline {

class RenderPipeline {
 public:
  RenderPipeline();
  ~RenderPipeline();
  void InitShader();
  void InitMesh();
  void ForwardRendering(RenderList& renderlist);
  void DefferedShading(RenderList& renderlist);
  void Shading();
 private:
  std::mutex create_shader_tasks_lock_;
  std::vector<std::function<void()>> create_shader_tasks_;
  std::mutex create_mesh_tasks_lock_;
  std::vector<std::function<void()>> create_mesh_tasks_;
};

extern RenderPipeline* renderpipeline;

}
}
}
}

#endif