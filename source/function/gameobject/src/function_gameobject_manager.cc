#include "function_gameobject_manager.h"

namespace TuYiLe {
namespace functionlayer {
namespace gameobject {

GameObjectManager::GameObjectManager() {

}

GameObjectManager::~GameObjectManager() {

}

void GameObjectManager::SetGameObject(gouid id, std::shared_ptr<GameObjectBase> object) {
  golist_[id] = object;
}

gouid GameObjectManager::AppendGameObject(std::shared_ptr<GameObjectBase> object) {
  gouid ret = insert_point_;
  golist_[insert_point_] = object;
  UpdateInsertPoint();
  return ret;
}

std::shared_ptr<GameObjectBase> GameObjectManager::GetGameObject(gouid id) {
  return golist_.at(id);
}

gouid GameObjectManager::GetInsertPoint() {
  auto ret = insert_point_;
  UpdateInsertPoint();
  return ret;
}

void GameObjectManager::UpdateInsertPoint() {
  insert_point_ = next_insert_opint_;
  next_insert_opint_++;
  while (golist_.contains(next_insert_opint_)) {
    next_insert_opint_++;
  }
}

}
}
}