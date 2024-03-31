#ifndef FUNCTION_GAMEOBJECT_MANAGER_H_
#define FUNCTION_GAMEOBJECT_MANAGER_H_

#include <vector>
#include <map>
#include <memory>

#include "function_gameobject_gameobjectbase.h"

namespace TuYiLe {
namespace functionlayer {
namespace gameobject {

typedef unsigned long long gouid;

class GameObjectManager {
 public:
  GameObjectManager();
  ~GameObjectManager();
  void SetGameObject(gouid id, std::shared_ptr<GameObjectBase> object);
  gouid AppendGameObject(std::shared_ptr<GameObjectBase> object);
  std::shared_ptr<GameObjectBase> GetGameObject(gouid id);
 private:
  gouid GetInsertPoint();
  void UpdateInsertPoint();
  gouid insert_point_ {0};
  gouid next_insert_opint_ {1};
  std::map<gouid, std::shared_ptr<GameObjectBase>> golist_;
};

}
}
}

#endif