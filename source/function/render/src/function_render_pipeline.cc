#include "function_render_pipeline.h"

namespace functionlayer {
namespace render {
namespace pipeline{

RenderPipeline::RenderPipeline() {

}

RenderPipeline::~RenderPipeline() {

}

void RenderPipeline::CreateShaderTask(std::function<void()> task) {
  create_shader_tasks_lock_.lock();
  create_shader_tasks_.push_back(task);
  std::cout << create_shader_tasks_.size() << std::endl;
  create_shader_tasks_lock_.unlock();
}

void RenderPipeline::InitShader() {
  create_shader_tasks_lock_.lock();
  for (auto& task : create_shader_tasks_) {
    task();
  }
  create_shader_tasks_.clear();
  create_shader_tasks_lock_.unlock();
}

void RenderPipeline::CreateMeshTask(std::function<void()> task) {
  create_mesh_tasks_lock_.lock();
  create_mesh_tasks_.push_back(task);
  std::cout << create_mesh_tasks_.size() << std::endl;
  create_mesh_tasks_lock_.unlock();
}

void RenderPipeline::InitMesh() {
  create_mesh_tasks_lock_.lock();
  for (auto& task : create_mesh_tasks_) {
    task();
  }
  create_mesh_tasks_.clear();
  create_mesh_tasks_lock_.unlock();
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