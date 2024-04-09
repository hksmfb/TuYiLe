#include "function_scene_main.h"

namespace TuYiLe {
namespace functionlayer {
namespace scene {

MainScene::MainScene() {
  gui::GuiBase* newgui = new gui::GuiBase();
  gui::Block* rect = new gui::Block();
  gui::RectShape* shape = new gui::RectShape();
  shape->SetSize(0.5,0.5);
  gui::TriggerBase* trigger = new gui::RectTrigger();
  trigger->OnHover([](){printf("OOOOOOO\n");});
  trigger->OffHover([](){printf("-------\n");});
  trigger->SetTransform(shape->GetTransform());
  rect->SetShape(shape);
  rect->AppendTrigger(trigger);
  newgui->AppendBlockSet(rect);
  scenegui.AppendGui(newgui);
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
}