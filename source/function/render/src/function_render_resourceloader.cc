#include "function_render_resourceloader.h"

namespace functionlayer {
namespace render {
namespace resourceloader{

corelayer::guid CreateShader(platformlayer::datatype::shadercode& shadercode) {
  auto guid = corelayer::guidmanager->RequestGUID();
  resourcelayer::resourcemanager->SetShader(guid, nullptr);
  platformlayer::RHI::AppendShaderBatch(shadercode, resourcelayer::resourcemanager->GetShaderAddress(guid));
  return guid;
}

void InitShader() {
  platformlayer::RHI::CreateShaderBatch();
}

void CreateMesh(platformlayer::datatype::Mesh& mesh) {
  auto guid = corelayer::guidmanager->RequestGUID();
  resourcelayer::resourcemanager->SetMesh(guid, nullptr);
  platformlayer::RHI::AppendMeshBatch(mesh, resourcelayer::resourcemanager->GetMeshAddress(guid));
  // printf("CreateMesh\n");
}

void InitMesh() {
  platformlayer::RHI::CreateMeshBatch();
}

}
}
}