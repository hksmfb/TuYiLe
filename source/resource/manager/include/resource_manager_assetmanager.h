#ifndef RESOURCE_MANAGER_ASSETMANAGER_H_
#define RESOURCE_MANAGER_ASSETMANAGER_H_

#include <vector>

#include "core_guid_manager.h"

namespace resourcelayer {

class Asset {
  public:
    Asset();
    ~Asset();
  private:
    std::vector<corelayer::guid> meshlist_;
    std::vector<corelayer::guid> texturelist_;
};

class AssetManager {
  public:
    AssetManager();
    ~AssetManager();
    void LoadAsset();
  private:
    std::vector<Asset*> assetlist_;
};

}

#endif