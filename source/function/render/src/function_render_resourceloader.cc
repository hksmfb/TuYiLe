#include "function_render_resourceloader.h"

namespace functionlayer {
namespace render {
namespace resourceloader{

void CreateShader(platformlayer::datatype::shadercode& shadercode) {
  platformlayer::RHI::AppendShaderBatch(shadercode);
}

void InitShader() {
  auto shaderlist = platformlayer::RHI::CreateShaderBatch();
  for (auto& shader : shaderlist) {
    resourcelayer::resourcemanager->SetShaderProgram(shader);
  }
}

void CreateMesh(platformlayer::datatype::Mesh& mesh) {
  platformlayer::RHI::AppendMeshBatch(mesh);
  // printf("CreateMesh\n");
}

void InitMesh() {
  auto meshlist = platformlayer::RHI::CreateMeshBatch();
  for (auto& mesh : meshlist) {
    resourcelayer::resourcemanager->SetLoadedMesh(mesh);
  }
}

}
}
}