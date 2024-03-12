#include "function_scene_manager.h"

namespace functionlayer {
namespace scene {

SceneManager::SceneManager() {
  scene_ = new MainScene();
}

SceneManager::~SceneManager() {

}

SceneManager* scenemanager = nullptr;

}
}