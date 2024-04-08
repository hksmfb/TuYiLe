#include "resource_manager_resourcemanager.h"

namespace TuYiLe {
namespace resourcelayer {
namespace manager {

ResourceManager::ResourceManager() {
  
}

ResourceManager::~ResourceManager() {
  
}

void ResourceManager::InitBuildinResource() {
  LoadMesh(1000, mesh::Rect());
  LoadShader(3000, shader::Default());
}

void ResourceManager::SetShaderProgram(std::shared_ptr<platformlayer::RHI::Shader> shader_program) {
  auto guid = corelayer::guid::guidmanager->RequestGUID();
  shader_program_list_lock_.lock();
  shader_program_list_[guid] = shader_program;
  shader_program_list_lock_.unlock();
}

void ResourceManager::SetShader(corelayer::guid::guid id, std::shared_ptr<platformlayer::RHI::Shader> shader_program) {
  shader_program_list_[id] = shader_program;
}

std::shared_ptr<platformlayer::RHI::Shader>* ResourceManager::GetShaderAddress(corelayer::guid::guid id) {
  return &(shader_program_list_.at(id));
}

std::shared_ptr<platformlayer::RHI::Shader> ResourceManager::GetShader(corelayer::guid::guid id) {
  return shader_program_list_.at(id);
}

void ResourceManager::SetLoadedMesh(std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh) {
  auto guid = corelayer::guid::guidmanager->RequestGUID();
  loaded_mesh_list_lock_.lock();
  loaded_mesh_list_[guid] = loaded_mesh;
  loaded_mesh_list_lock_.unlock();
}

void ResourceManager::SetMesh(corelayer::guid::guid id, std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh) {
  loaded_mesh_list_[id] = loaded_mesh;
}

std::shared_ptr<platformlayer::RHI::Mesh>* ResourceManager::GetMeshAddress(corelayer::guid::guid id) {
  return &(loaded_mesh_list_.at(id));
}

std::shared_ptr<platformlayer::RHI::Mesh> ResourceManager::GetMesh(corelayer::guid::guid id) {
  return loaded_mesh_list_.at(id);
}

void ResourceManager::LoadMesh(corelayer::guid::guid id, platformlayer::datatype::Mesh mesh) {
  loaded_mesh_list_lock_.lock();
  loaded_mesh_list_[id] = nullptr;
  loaded_mesh_list_lock_.unlock();
  platformlayer::RHI::AppendMeshBatch(mesh, &loaded_mesh_list_[id]);
}

void ResourceManager::LoadShader(corelayer::guid::guid id, platformlayer::datatype::shadercode code) {
  shader_program_list_lock_.lock();
  shader_program_list_[id];
  shader_program_list_lock_.unlock();
  platformlayer::RHI::AppendShaderBatch(code, &shader_program_list_[id]);
}

ResourceManager* resourcemanager = nullptr;

}
}
}