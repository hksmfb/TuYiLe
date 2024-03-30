#ifndef RESOURCE_MANAGER_ASSETMANAGER_H_
#define RESOURCE_MANAGER_ASSETMANAGER_H_

#include <memory>
#include <vector>

#include "core_guid_manager.h"
#include "resource_component_componentbase.h"

namespace resourcelayer {

class Asset {
 public:
  void AppendComponent(ComponentBase component);
  std::vector<ComponentBase>& GetComponentList();
 private:
  std::vector<ComponentBase> componentlist_;
};

class AssetManager {
  public:
    AssetManager();
    ~AssetManager();
    void LoadAsset();
  private:
    std::vector<std::shared_ptr<Asset>> assetlist_;
};

}

#endif