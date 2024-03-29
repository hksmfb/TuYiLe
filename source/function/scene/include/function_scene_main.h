#ifndef FUNCTION_SCENE_MAIN_H_
#define FUNCTION_SCENE_MAIN_H_

#include "function_scene_scenebase.h"
#include "function_render_resourceloader.h"
#include "platform_rhi_rhi.h"

namespace functionlayer {
namespace scene {

class MainScene : public SceneBase {
 public:
  MainScene();
  ~MainScene();
  void Update();
  void Draw();
 private:
  platformlayer::RHI::Mesh* mesh_;
  platformlayer::RHI::Shader* shader_;
};

}
}

#endif