#include "function_scene_main.h"

namespace functionlayer {
namespace scene {

MainScene::MainScene() {

}

MainScene::~MainScene() {

}

void MainScene::Update() {
  
}

void MainScene::Draw() {
  shader_->Use();
  mesh_->Draw();
}

}
}