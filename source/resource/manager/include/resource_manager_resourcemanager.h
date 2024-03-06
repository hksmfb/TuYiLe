#ifndef RESOURCE_MANAGER_RESOURCEMANAGER_H_
#define RESOURCE_MANAGER_RESOURCEMANAGER_H_

#include <vector>
#include <unordered_map>
#include <string>

#include "core_guid_manager.h"
#include "platform_data_datatype.h"

namespace resourcelayer {

class ResourceManager {
  public:
    ResourceManager();
    ~ResourceManager();
  private:
    std::unordered_map<corelayer::guid, std::string> resource_handler_;
    std::unordered_map<corelayer::guid, platformlayer::datatype::Mesh*> meshlist_;
    std::unordered_map<corelayer::guid, platformlayer::datatype::Texture*> texturelist_;
};

extern ResourceManager* resourcemanager;

}

#endif