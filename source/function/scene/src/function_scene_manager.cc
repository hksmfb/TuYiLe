#include "function_scene_manager.h"

namespace TuYiLe {
namespace functionlayer {
namespace scene {

SceneManager::SceneManager() {
  //init console
  //regist func;
}

void SceneManager::Init() {
  scene_ = new MainScene();
}

SceneManager::~SceneManager() {
  delete scene_;
}

void SceneManager::SetScene(SceneBase* scene) {
  //todo
  #ifdef DEVMOD
    std::cout << "SceneManager::SetScene()\n";
  #endif
}

void SceneManager::RegistSceneType(SceneBase* scene) {
  //todo
  #ifdef DEVMOD
    std::cout << "SceneManager::RegistSceneType()\n";
  #endif
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
}