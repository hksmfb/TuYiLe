#ifndef FUNCTION_RENDER_RESOURCELOADER_H_
#define FUNCTION_RENDER_RESOURCELOADER_H_

#include <string>
#include <functional>

#include "platform_data_datatype.h"
#include "platform_rhi_rhi.h"
#include "function_render_pipeline.h"
#include "core_guid_manager.h"
#include "resource_manager_resourcemanager.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {
namespace resourceloader{

corelayer::guid::guid CreateShader(platformlayer::datatype::shadercode& shadercode);
std::shared_ptr<platformlayer::RHI::Shader> GetShader(corelayer::guid::guid guid);
void InitShader();
void CreateMesh(platformlayer::datatype::Mesh& mesh);
std::shared_ptr<platformlayer::RHI::Mesh> GetMesh(corelayer::guid::guid guid);
void InitMesh();

}
}
}
}

#endif