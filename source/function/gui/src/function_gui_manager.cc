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

void GuiManager::UpdateWindowSize() {
  int windowwidth = platformlayer::window::windowmanager->GetWidth();
  int windowheight = platformlayer::window::windowmanager->GetHeight();
  int viewportwidth = platformlayer::RHI::GetViewportWidth()-platformlayer::RHI::GetViewportPosx();
  int viewportheight = platformlayer::RHI::GetViewportHeight()-platformlayer::RHI::GetViewportPosy();
  bool change = false;
  window_height_ = window_height_ == windowheight ? windowheight : windowheight;
  window_width_ = window_width_ == windowwidth ? windowwidth : windowwidth;
  viewport_height_ = viewport_height_ == viewportheight ? viewportheight : viewportheight;
  viewport_width_ = viewportwidth == viewportwidth ? viewportwidth : viewportwidth;
}

}
}
}