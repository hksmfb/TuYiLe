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
  std::shared_ptr<platformlayer::RHI::Shader> shader = resourcelayer::resourcemanager->getshader();
  std::shared_ptr<platformlayer::RHI::Mesh> mesh = resourcelayer::resourcemanager->getmesh();
  if (shader != nullptr && mesh != nullptr) {
    shader->Use();
    mesh->Draw();
  }
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void RenderPipeline::DefferedShading(RenderList* renderlist) {
  
}

RenderPipeline* renderpipeline = nullptr;

}
}
}