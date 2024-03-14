#include "function_render_pipeline.h"

namespace functionlayer {
namespace render {
namespace pipeline{

RenderPipeline::RenderPipeline() {

}

RenderPipeline::~RenderPipeline() {

}

void RenderPipeline::InitShader() {
  resourceloader::InitShader();
}

void RenderPipeline::InitMesh() {
  resourceloader::InitMesh();
}

void RenderPipeline::ForwardRendering(RenderList* renderlist) {
  printf("runing fowardrendering\n");
  std::shared_ptr<platformlayer::RHI::Shader> shader = resourcelayer::resourcemanager->getshader();
  std::shared_ptr<platformlayer::RHI::Mesh> mesh = resourcelayer::resourcemanager->getmesh();
  if (shader != nullptr && mesh != nullptr) {
    printf("draw\n");
    shader->Use();
    mesh->Draw();
  }
}

void RenderPipeline::DefferedShading(RenderList* renderlist) {
  
}

RenderPipeline* renderpipeline = nullptr;

}
}
}