#include "function_scene_scenebase.h"

namespace functionlayer {
namespace scene {

void SceneBase::Draw() {

}

void SceneBase::Update() {
  
}

gameobject::gouid SceneBase::AppendGameObject(std::shared_ptr<gameobject::GameObjectBase> object) {
  return GOmanager_.AppendGameObject(object);
}

void SceneBase::SetGameObject(gameobject::gouid id, std::shared_ptr<gameobject::GameObjectBase> object) {
  GOmanager_.SetGameObject(id, object);
}

std::shared_ptr<gameobject::GameObjectBase> SceneBase::GetGameObject(gameobject::gouid id) {
  return GOmanager_.GetGameObject(id);
}

functionlayer::render::RenderList SceneBase::GetRenderList() {
  return renderlist_;
}

}
}