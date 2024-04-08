#include "function_scene_scenebase.h"

namespace TuYiLe {
namespace functionlayer {
namespace scene {

void SceneBase::Init() {

}

void SceneBase::BasicUpdate() {
  scenegui.Update();
  renderlist_ = scenegui.GetCurrentRenderList();
}

void SceneBase::Update() {
  
}

void SceneBase::Draw() {

}

gameobject::gouid SceneBase::CreateGameObject(std::shared_ptr<gameobject::GameObjectBase> object) {
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
}