#include "function_scene_scenebase.h"

namespace functionlayer {
namespace scene {

void SceneBase::Draw() {

}

void SceneBase::Update() {
  printf("scene update\n");
}

functionlayer::render::RenderList SceneBase::GetRenderList() {
  return renderlist_;
}

}
}