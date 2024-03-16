#ifndef RESOURCE_MANAGER_RESOURCEMANAGER_H_
#define RESOURCE_MANAGER_RESOURCEMANAGER_H_

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

#include "core_thread_manager.h"
#include "core_guid_manager.h"
#include "platform_data_datatype.h"
#include "platform_rhi_shader.h"
#include "platform_rhi_mesh.h"

namespace resourcelayer {

class ResourceManager {
  public:
    ResourceManager();
    ~ResourceManager();
    void SetShaderProgram(std::shared_ptr<platformlayer::RHI::Shader> shader_program);
    void SetLoadedMesh(std::shared_ptr<platformlayer::RHI::Mesh> loaded_mesh);
    std::shared_ptr<platformlayer::RHI::Shader> getshader();
    std::shared_ptr<platformlayer::RHI::Mesh> getmesh();
  private:
    std::unordered_map<corelayer::guid, std::string> resource_handler_;
    std::unordered_map<corelayer::guid, platformlayer::datatype::Mesh*> meshlist_;
    std::unordered_map<corelayer::guid, platformlayer::datatype::Texture*> texturelist_;

    std::mutex shader_program_list_lock_;
    std::unordered_map<corelayer::guid, std::shared_ptr<platformlayer::RHI::Shader>> shader_program_list_;
    std::mutex loaded_mesh_list_lock_;
    std::unordered_map<corelayer::guid, std::shared_ptr<platformlayer::RHI::Mesh>> loaded_mesh_list_;
};

extern ResourceManager* resourcemanager;

}

#endif