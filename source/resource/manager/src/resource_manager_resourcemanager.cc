#include "resource_manager_resourcemanager.h"

namespace resourcelayer {

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
  
}

void ResourceManager::SetShaderProgram(std::shared_ptr<platformlayer::RHI::Shader> shader_program) {
  auto guid = corelayer::guidmanager->RequestGUID();
  shader_program_list_lock_.lock();
  shader_program_list_[guid] = shader_program;
  shader_program_list_lock_.unlock();
}

void ResourceManager::SetLoadedMesh(std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh) {
  auto guid = corelayer::guidmanager->RequestGUID();
  loaded_mesh_list_lock_.lock();
  loaded_mesh_list_[guid] = loaded_mesh;
  loaded_mesh_list_lock_.unlock();
}

std::shared_ptr<platformlayer::RHI::Shader> ResourceManager::getshader() {
  for (auto shader : shader_program_list_) {
    return shader.second;
  }
  return nullptr;
}
std::shared_ptr<platformlayer::RHI::Mesh> ResourceManager::getmesh() {
  for (auto mesh : loaded_mesh_list_) {
    return mesh.second;
  }
  return nullptr;
}

ResourceManager* resourcemanager = nullptr;

}