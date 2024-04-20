#include "function_scene_main.h"

namespace TuYiLe {
namespace functionlayer {
namespace scene {

MainScene::MainScene() {
  gui::GuiBase* newgui = new gui::GuiBase();
  gui::Block* rect = new gui::Block();
  printf("0\n");
  gui::RectShape* shape = new gui::RectShape();
  shape->SetSize(0.5,0.5);
  printf("1\n");
  gui::TriggerBase* trigger = new gui::RectTrigger();
  trigger->OnHover([](){printf("OOOOOOO\n");});
  trigger->OffHover([](){printf("-------\n");});
  trigger->OnClick([](){printf("*******");});
  printf("2\n");
  trigger->GetLocalTrans().SetScale(0.5,0.5,1);
  printf("4\n");
  rect->SetShape(shape);
  printf("5\n");
  rect->AppendTrigger(trigger);
  printf("6\n");
  newgui->AppendBlockSet(rect);
  printf("7\n");
  scenegui.AppendGui(newgui);
  printf("3\n");
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