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
  UpdateWindowSize();
  mousepos_.x = widthratio_*platformlayer::input::inputmanager->GetMousePosxFixed();
  mousepos_.y = heightratio_*platformlayer::input::inputmanager->GetMousePosyFixed();
  current_gui_->Update(mousepos_);
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

void GuiManager::UpdateWindowSize() {
  int windowwidth = platformlayer::window::windowmanager->GetWidth();
  int windowheight = platformlayer::window::windowmanager->GetHeight();
  int viewportwidth = platformlayer::RHI::GetViewportWidth()-platformlayer::RHI::GetViewportPosx();
  int viewportheight = platformlayer::RHI::GetViewportHeight()-platformlayer::RHI::GetViewportPosy();
  float wratio = (float)windowheight/viewportwidth;
  float hratio = (float)windowheight/viewportheight;
  if (widthratio_ != wratio) {
    widthratio_ = wratio;
  }
  if (heightratio_ != hratio) {
    heightratio_ = hratio;
  }
}

}
}
}