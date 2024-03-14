#include "function_render_resourceloader.h"

namespace functionlayer {
namespace render {

void CreateShader(std::string& vertexshader, std::string& fragmentshader) {
  std::string vert = vertexshader;
  std::string frag = fragmentshader;
  pipeline::renderpipeline->CreateShaderTask([vert, frag](){
    auto shaderprogram = platformlayer::RHI::CreateShader(vert, frag);
    resourcelayer::resourcemanager->SetShaderProgram(shaderprogram);
  });
  // printf("CreateShader\n");
}

void CreateMesh(platformlayer::datatype::Mesh& mesh) {
  platformlayer::datatype::Mesh m = mesh;
  pipeline::renderpipeline->CreateMeshTask([m](){
    auto loadedmesh = platformlayer::RHI::CreateMesh(m);
    resourcelayer::resourcemanager->SetLoadedMesh(loadedmesh);
  });
  // printf("CreateMesh\n");
}

}
}