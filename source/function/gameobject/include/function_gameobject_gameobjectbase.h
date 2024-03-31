#ifndef FUNCTION_GAMEOBJECT_GAMEOBJECTBASE_H_
#define FUNCTION_GAMEOBJECT_GAMEOBJECTBASE_H_

#include "core_guid_manager.h"
#include "resource_manager_assetmanager.h"

namespace TuYiLe {
namespace functionlayer {
namespace gameobject {

class GameObjectBase {
 public:
  void SetAsset(corelayer::guid::guid id);
 private:
  corelayer::guid::guid asset_id_;
  resourcelayer::asset::AssetBase* asset_ {nullptr};
};

}
}
}

#endif