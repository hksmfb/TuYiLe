#ifndef FUNCTION_SCENE_MANAGER_H_
#define FUNCTION_SCENE_MANAGER_H_

#include "function_scene_main.h"
#include "function_console_console.h"

namespace TuYiLe {
namespace functionlayer {
namespace scene {

class SceneManager {
 public:
  SceneManager();
  SceneManager(SceneBase* scene);
  ~SceneManager();
  void SetScene(SceneBase* scene);
  SceneBase* GetScene();
  void RunCommand(std::string command);
 private:
  console::Console* console {nullptr};
  SceneBase* scene_ {nullptr};
};

extern SceneManager* scenemanager;

}
}
}

#endif