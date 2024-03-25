#ifndef FUNCTION_SCENE_SCENEBASE_H_
#define FUNCTION_SCENE_SCENEBASE_H_

#include "function_render_renderlist.h"
#include "platform_file_filesystem.h"

namespace functionlayer {
namespace scene{

class SceneBase {
 public:
  void Draw();
  void Update();
  functionlayer::render::RenderList GetRenderList();
 protected:
  functionlayer::render::RenderList renderlist_;
 private:
};

}
}

#endif