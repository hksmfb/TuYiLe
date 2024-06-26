#include "function_render_resourceloader.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {
namespace resourceloader{

corelayer::guid::guid CreateShader(platformlayer::datatype::shadercode& shadercode) {
  auto guid = corelayer::guid::guidmanager->RequestGUID();
  resourcelayer::manager::resourcemanager->SetShader(guid, nullptr);
  platformlayer::RHI::AppendShaderBatch(shadercode, resourcelayer::manager::resourcemanager->GetShaderAddress(guid));
  return guid;
}

void InitShader() {
  platformlayer::RHI::CreateShaderBatch();
}

void CreateMesh(platformlayer::datatype::Mesh& mesh) {
  auto guid = corelayer::guid::guidmanager->RequestGUID();
  resourcelayer::manager::resourcemanager->SetMesh(guid, nullptr);
  platformlayer::RHI::AppendMeshBatch(mesh, resourcelayer::manager::resourcemanager->GetMeshAddress(guid));
}

void InitMesh() {
  platformlayer::RHI::CreateMeshBatch();
}

}
}
}
}