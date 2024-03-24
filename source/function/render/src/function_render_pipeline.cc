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

void RenderPipeline::ForwardRendering(RenderList& renderlist) {  
  struct meshnode {
    corelayer::guid mesh {0};
  };
  struct normalnode {
    corelayer::guid normal {0};
    std::list<std::list<meshnode>> meshlist;
  };
  struct texturenode {
    corelayer::guid texture {0};
    std::list<std::list<normalnode>> normallist;
  };
  struct shadernode {
    corelayer::guid shader {0};
    std::vector<std::list<texturenode>> texturelist;
  };
  std::list<shadernode> drawtree;
  auto list = renderlist.GetRenderList();
  for (auto& render : list) {
    for (auto& snode : drawtree) {
      if (render->GetShader() == snode.shader) {

      }
    }
    shadernode newshadernode;
    newshadernode.shader = render->GetShader();
    newshadernode.texturelist.push_back(render->GetTexture());
    newshadernode.texturelist.at(0);
    drawtree.push_back(newshadernode);
  }

  std::shared_ptr<platformlayer::RHI::Shader> shader = resourcelayer::resourcemanager->getshader();
  std::shared_ptr<platformlayer::RHI::Mesh> mesh = resourcelayer::resourcemanager->getmesh();
  if (shader != nullptr && mesh != nullptr) {
    shader->Use();
    mesh->Draw();
  }
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void RenderPipeline::DefferedShading(RenderList& renderlist) {
  
}

RenderPipeline* renderpipeline = nullptr;

}
}
}