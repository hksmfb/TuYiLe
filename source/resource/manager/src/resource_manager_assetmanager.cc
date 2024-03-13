#include "resource_manager_assetmanager.h"

namespace resourcelayer {

void Asset::AppendComponent(Component component) {
  componentlist_.push_back(component);
}

std::vector<Component>& Asset::GetComponentList() {
  return componentlist_;
}

AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {
  
}

}