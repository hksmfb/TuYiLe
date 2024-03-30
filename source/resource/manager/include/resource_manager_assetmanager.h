#ifndef RESOURCE_MANAGER_ASSETMANAGER_H_
#define RESOURCE_MANAGER_ASSETMANAGER_H_

#include <memory>
#include <vector>

#include "core_guid_manager.h"
#include "resource_asset_assetbase.h"
#include "resource_component_componentbase.h"

namespace resourcelayer {
namespace manager {

class AssetManager {
  public:
    AssetManager();
    ~AssetManager();
    void LoadAsset();
  private:
    std::vector<std::shared_ptr<asset::AssetBase>> assetlist_;
};

}
}

#endif