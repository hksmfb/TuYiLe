#include "function_scene_manager.h"

namespace functionlayer {
namespace scene {

SceneManager::SceneManager() {
  scene_ = new MainScene();
  //init console
  //regist func;
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

void SceneManager::RunCommand(std::string command) {
  //todo
  #ifdef DEVMOD
    std::cout << "SceneManager::RunCommand(" << command << ")\n";
  #endif
}

SceneManager* scenemanager = nullptr;

}
}