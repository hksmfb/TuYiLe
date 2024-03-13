#include "resource_manager_resourcemanager.h"

namespace resourcelayer {

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
  
}

void ResourceManager::SetShaderProgram(std::shared_ptr<platformlayer::RHI::Shader> shaderprogram) {
  auto guid = corelayer::guidmanager->RequestGUID();
  shader_program_list_[guid] = shaderprogram;
}

ResourceManager* resourcemanager = nullptr;

}