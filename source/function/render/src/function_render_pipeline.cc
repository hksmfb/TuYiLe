#include "function_render_pipeline.h"

namespace functionlayer {
namespace render {
namespace pipeline{

RenderPipeline::RenderPipeline() {

}

RenderPipeline::~RenderPipeline() {

}

void RenderPipeline::CreateShaderTask(std::function<void()> task) {
  create_shader_tasks_.push_back(task);
}

void RenderPipeline::InitShader() {
  for (auto& task : create_shader_tasks_) {
    task();
  }
}

void RenderPipeline::ForwardRendering(RenderList* renderlist) {

}

void RenderPipeline::DefferedShading(RenderList* renderlist) {
  
}

RenderPipeline* renderpipeline = nullptr;

}
}
}