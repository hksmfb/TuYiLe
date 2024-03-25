#include "function_scene_manager.h"

namespace functionlayer {
namespace scene {

SceneManager::SceneManager() {
  scene_ = new MainScene();
}

SceneManager::SceneManager(SceneBase* scene) {
  scene_ = scene;
}

SceneManager::~SceneManager() {
  delete scene_;
}

SceneBase* SceneManager::GetScene() {
  return scene_;
}

SceneManager* scenemanager = nullptr;

}
}