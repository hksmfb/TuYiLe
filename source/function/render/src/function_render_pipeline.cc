#include "function_render_pipeline.h"

namespace functionlayer {
namespace render {
namespace pipeline{

RenderPipeline::RenderPipeline() {

}

RenderPipeline::~RenderPipeline() {

}

void RenderPipeline::CreateShaderTask(std::function<void()> task) {
  printf("try create shader\n");
  create_shader_tasks_lock_.lock();
  printf("create shader\n");
  create_shader_tasks_.push_back(task);
  // std::cout << create_shader_tasks_.size() << std::endl;
  create_shader_tasks_lock_.unlock();
  printf("create shader complete\n");
}

void RenderPipeline::InitShader() {
  printf("init shader\n");
  resourceloader::InitShader();
  printf("init shader complete\n");
}

void RenderPipeline::CreateMeshTask(std::function<void()> task) {
  create_mesh_tasks_lock_.lock();
  create_mesh_tasks_.push_back(task);
  // printf("mesh task created\n");
  // std::cout << create_mesh_tasks_.size() << std::endl;
  create_mesh_tasks_lock_.unlock();
  // printf("create mesh out\n");
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