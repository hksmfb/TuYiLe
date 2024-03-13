#include "function_render_shader.h"

namespace functionlayer {
namespace render {

void CreateShader(std::string& vertexshader, std::string& fragmentshader) {
  printf("render shader in\n");
  std::string vert = vertexshader;
  std::string frag = fragmentshader;
  pipeline::renderpipeline->CreateShaderTask([vert, frag](){
    printf("rhi create shader\n");
    auto shaderprogram = platformlayer::RHI::CreateShader(vert, frag);
    printf("rhi create shader finish\n");
    resourcelayer::resourcemanager->SetShaderProgram(shaderprogram);
  });
  printf("render shader out\n");
}

}
}