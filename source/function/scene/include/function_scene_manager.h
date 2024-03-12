#ifndef FUNCTION_SCENE_MANAGER_H_
#define FUNCTION_SCENE_MANAGER_H_

#include "function_scene_main.h"

namespace functionlayer {
namespace scene {

class SceneManager {
 public:
  SceneManager();
  ~SceneManager();
 private:
  SceneBase* scene_;
};

extern SceneManager* scenemanager;

}
}

#endif