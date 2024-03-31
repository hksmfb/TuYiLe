#include "function_render_pipeline.h"

namespace TuYiLe {
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

void RenderPipeline::ForwardRendering(RenderList& renderlist) {  
  std::map<std::shared_ptr<platformlayer::RHI::Shader>, std::list<RenderBase*>> shadertree;
  for (auto& render : renderlist.GetRenderList()) {
    shadertree[render->GetShader()].push_back(render);
  }
  for (auto& shadernode : shadertree) {
    shadernode.first->Use();
    for (auto& render : shadernode.second) {
      render->Draw();
    }
  }
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void RenderPipeline::DefferedShading(RenderList& renderlist) {
  
}

RenderPipeline* renderpipeline = nullptr;

}
}
}
}