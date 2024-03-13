#include "function_render_pipeline.h"

namespace functionlayer {
namespace render {
namespace pipeline{

RenderPipeline::RenderPipeline() {

}

RenderPipeline::~RenderPipeline() {

}

void RenderPipeline::CreateShaderTask(std::function<void()> task) {
  printf("push task\n");
  create_shader_tasks_.push_back(task);
  printf("push task finish\n");
}

void RenderPipeline::InitShader() {
  for (auto& task : create_shader_tasks_) {
    printf("run init shader:\n");
    task();
    printf("init shader finish\n");
  }
  create_shader_tasks_.clear();
}

void RenderPipeline::ForwardRendering(RenderList* renderlist) {
  printf("runing fowardrendering\n");
}

void RenderPipeline::DefferedShading(RenderList* renderlist) {
  
}

RenderPipeline* renderpipeline = nullptr;

}
}
}