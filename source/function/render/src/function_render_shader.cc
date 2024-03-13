#include "function_render_shader.h"

namespace functionlayer {
namespace render {

void CreateShader(std::string& vertexshader, std::string& fragmentshader) {
  auto shaderprogram = platformlayer::RHI::CreateShader(vertexshader, fragmentshader);
  resourcelayer::resourcemanager->SetShaderProgram(shaderprogram);
}

}
}