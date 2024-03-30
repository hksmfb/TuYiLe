#ifndef FUNCTION_GAMEOBJECT_GAMEOBJECTBASE_H_
#define FUNCTION_GAMEOBJECT_GAMEOBJECTBASE_H_

#include "core_guid_manager.h"
#include "resource_manager_assetmanager.h"

namespace functionlayer {
namespace gameobject {

class GameObjectBase {
 public:
  void SetAsset(corelayer::guid id);
 private:
  corelayer::guid asset_id_;
  resourcelayer::asset::AssetBase* asset_ {nullptr};
};

}
}

#endif