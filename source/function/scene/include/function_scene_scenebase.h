#ifndef FUNCTION_SCENE_SCENEBASE_H_
#define FUNCTION_SCENE_SCENEBASE_H_

#include "function_render_renderlist.h"
#include "platform_file_filesystem.h"
#include "function_gameobject_manager.h"
#include "function_gui_manager.h"
#include "function_hud_manager.h"

namespace TuYiLe {
namespace functionlayer {
namespace scene{

class SceneBase {
 public:
  void Init();
  void BasicUpdate();
  void Update();
  void Draw();
  gameobject::gouid CreateGameObject(std::shared_ptr<gameobject::GameObjectBase> object);
  void SetGameObject(gameobject::gouid id, std::shared_ptr<gameobject::GameObjectBase> object);
  std::shared_ptr<gameobject::GameObjectBase> GetGameObject(gameobject::gouid id);
  render::RenderList GetRenderList();
 protected:
  gui::GuiManager scenegui {};
  render::RenderList renderlist_;
 private:  
  gameobject::GameObjectManager GOmanager_ {};
};

}
}
}

#endif