#include "function_tick_logictick.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

LogicTick::LogicTick() {

}

LogicTick::~LogicTick() {
  
}

void LogicTick::Update() {
  scene::scenemanager->GetScene()->BasicUpdate();
  scene::scenemanager->GetScene()->Update();
  drawbuffer_->SetRenderList(scene::scenemanager->GetScene()->GetRenderList());
}

// render::RenderList LogicTick::GetRenderList() {
//   renderlist_lock_.lock();
//   render::RenderList ret = renderlist_;
//   renderlist_lock_.unlock();
//   return ret;
// }

}
}
}