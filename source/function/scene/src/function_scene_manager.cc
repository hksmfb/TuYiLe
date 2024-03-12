#include "function_scene_manager.h"

namespace functionlayer {
namespace scene {

SceneManager::SceneManager() {
  scene_ = new MainScene();
}

SceneManager::~SceneManager() {

}

SceneBase* SceneManager::GetScene() {
  return scene_;
}

SceneManager* scenemanager = nullptr;

}
}