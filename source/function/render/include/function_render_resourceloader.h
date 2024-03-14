#ifndef FUNCTION_RENDER_RESOURCELOADER_H_
#define FUNCTION_RENDER_RESOURCELOADER_H_

#include <string>
#include <functional>

#include "platform_data_datatype.h"
#include "platform_rhi_rhi.h"
#include "function_render_pipeline.h"
#include "core_guid_manager.h"
#include "resource_manager_resourcemanager.h"

namespace functionlayer {
namespace render {
namespace resourceloader{

void CreateShader(platformlayer::datatype::shadercode& shadercode);
void InitShader();
void CreateMesh(platformlayer::datatype::Mesh& mesh);
void InitMesh();

}
}
}

#endif