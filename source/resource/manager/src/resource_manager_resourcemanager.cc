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

std::shared_ptr<platformlayer::RHI::Shader>* ResourceManager::GetShaderAddress(corelayer::guid id) {
  return &(shader_program_list_.at(id));
}

std::shared_ptr<platformlayer::RHI::Shader> ResourceManager::GetShader(corelayer::guid id) {
  return shader_program_list_.at(id);
}

std::shared_ptr<platformlayer::RHI::Mesh>* ResourceManager::GetMeshAddress(corelayer::guid id) {
  return &(loaded_mesh_list_.at(id));
}

std::shared_ptr<platformlayer::RHI::Mesh> ResourceManager::GetMesh(corelayer::guid id) {
  return loaded_mesh_list_.at(id);
}

ResourceManager* resourcemanager = nullptr;

}