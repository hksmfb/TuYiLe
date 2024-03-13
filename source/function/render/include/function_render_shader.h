#ifndef FUNCTION_RENDER_SHADER_H_
#define FUNCTION_RENDER_SHADER_H_

#include <string>
#include <functional>

#include "platform_rhi_rhi.h"
#include "resource_manager_resourcemanager.h"

namespace functionlayer {
namespace render {

void CreateShader(std::string& vertexshader, std::string& fragmentshader);

}
}

#endif