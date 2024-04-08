#ifndef RESOURCE_MANAGER_RESOURCEMANAGER_H_
#define RESOURCE_MANAGER_RESOURCEMANAGER_H_

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

#include "core_thread_manager.h"
#include "core_guid_manager.h"
#include "platform_data_datatype.h"
#include "platform_rhi_mesh.h"
#include "resource_mesh_header.h"
#include "platform_rhi_shader.h"
#include "resource_shader_header.h"

namespace TuYiLe {
namespace resourcelayer {
namespace manager {

class ResourceManager {
 public:
  ResourceManager();
  ~ResourceManager();
  void InitBuildinResource();
  void SetShaderProgram(std::shared_ptr<platformlayer::RHI::Shader> shader_program);
  void SetLoadedMesh(std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh);
  void SetShader(corelayer::guid::guid id, std::shared_ptr<platformlayer::RHI::Shader> shader_program);
  std::shared_ptr<platformlayer::RHI::Shader>* GetShaderAddress(corelayer::guid::guid id);
  std::shared_ptr<platformlayer::RHI::Shader> GetShader(corelayer::guid::guid id);
  void SetMesh(corelayer::guid::guid id, std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh);
  std::shared_ptr<platformlayer::RHI::Mesh>* GetMeshAddress(corelayer::guid::guid id);
  std::shared_ptr<platformlayer::RHI::Mesh> GetMesh(corelayer::guid::guid id);
 private:
  void LoadMesh(corelayer::guid::guid id, platformlayer::datatype::Mesh mesh);
  void LoadShader(corelayer::guid::guid id, platformlayer::datatype::shadercode code);
  std::unordered_map<corelayer::guid::guid, std::string> resource_handler_;
  std::unordered_map<corelayer::guid::guid, platformlayer::datatype::Mesh*> meshlist_;
  std::unordered_map<corelayer::guid::guid, platformlayer::datatype::Texture*> texturelist_;

  std::mutex shader_program_list_lock_;
  std::unordered_map<corelayer::guid::guid, std::shared_ptr<platformlayer::RHI::Shader>> shader_program_list_;
  std::mutex loaded_mesh_list_lock_;
  std::unordered_map<corelayer::guid::guid, std::shared_ptr<platformlayer::RHI::Mesh>> loaded_mesh_list_;
};

extern ResourceManager* resourcemanager;

}
}
}

#endif