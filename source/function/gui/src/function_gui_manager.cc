#include "function_gui_manager.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

GuiManager::GuiManager() {

}

GuiManager::~GuiManager() {
  for (auto& gui : guilist_) {
    delete gui;
  }
}

void GuiManager::Update() {
  current_gui_->Update();
  current_renderlist_.clear();
  for (auto& render : current_gui_->GetAllRender()) {
    current_renderlist_.AppendRender(render);
  }
}

void GuiManager::AppendGui(GuiBase* gui) {
  current_gui_ = gui;
  guilist_.push_back(gui);
}

void GuiManager::SetCurrentGui(GuiBase* gui) {
  current_gui_ = gui;
}

void GuiManager::AppendBlockSet(Block* blockset) {

}

render::RenderList GuiManager::GetCurrentRenderList() {
  render::RenderList ret = current_renderlist_;
  return ret;
}


}
}
}