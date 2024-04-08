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
  std::map<
    corelayer::guid::guid,
    std::map<
      corelayer::guid::guid,
      std::list<renderdata>
    >
  > shadertree;
  for (auto& data : renderlist.GetRenderData()) {
    shadertree[data.shaderid][data.meshid].push_back(data);
  }
  for (auto& shaderid : shadertree) {
    auto shader = resourcelayer::manager::resourcemanager->GetShader(shaderid.first);
    shader->Use();
    for (auto& meshid : shaderid.second) {
      auto mesh = resourcelayer::manager::resourcemanager->GetMesh(meshid.first);
      for (auto& data : meshid.second) {
        for (int i = 0; i < data.floatlist.size(); ++i) {
          shader->SetFloat(data.floatname[i], data.floatlist[i]);
        }
        for (int i = 0; i < data.mat4name.size(); ++i) {
          shader->SetMat4(data.mat4name[i], data.mat4list[i]);
        }
        mesh->Draw();
      }
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