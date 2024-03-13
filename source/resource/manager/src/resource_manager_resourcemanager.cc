#include "resource_manager_resourcemanager.h"

namespace resourcelayer {

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
  
}

void ResourceManager::SetShaderProgram(std::shared_ptr<platformlayer::RHI::Shader> shader_program) {
  auto guid = corelayer::guidmanager->RequestGUID();
  shader_program_list_[guid] = shader_program;
}

void ResourceManager::SetLoadedMesh(std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh) {
  auto guid = corelayer::guidmanager->RequestGUID();
  loaded_mesh_list_[guid] = loaded_mesh;
}

ResourceManager* resourcemanager = nullptr;

}