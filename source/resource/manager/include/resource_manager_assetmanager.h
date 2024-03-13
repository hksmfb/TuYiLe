#ifndef RESOURCE_MANAGER_ASSETMANAGER_H_
#define RESOURCE_MANAGER_ASSETMANAGER_H_

#include <memory>
#include <vector>

#include "core_guid_manager.h"
#include "resource_component.h"

namespace resourcelayer {

class Asset {
 public:
  void AppendComponent(Component component);
  std::vector<Component>& GetComponentList();
 private:
  std::vector<Component> componentlist_;
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