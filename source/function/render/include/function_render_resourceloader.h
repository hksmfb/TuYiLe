#ifndef FUNCTION_RENDER_RESOURCELOADER_H_
#define FUNCTION_RENDER_RESOURCELOADER_H_

#include <string>
#include <functional>

#include "platform_data_datatype.h"
#include "platform_rhi_rhi.h"
#include "function_render_pipeline.h"
#include "resource_manager_resourcemanager.h"

namespace functionlayer {
namespace render {

void CreateShader(std::string& vertexshader, std::string& fragmentshader);
void CreateMesh(platformlayer::datatype::Mesh& mesh);

}
}

#endif