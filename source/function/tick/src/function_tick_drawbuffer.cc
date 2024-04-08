#include "function_tick_drawbuffer.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

DrawBuffer::DrawBuffer() {
  time[0] = platformlayer::time::GetTime();
  time[1] = platformlayer::time::GetTime();
  time[2] = platformlayer::time::GetTime();
}

DrawBuffer::~DrawBuffer() {
  
}

void DrawBuffer::UpdateDrawbuffer() {
  if (logic_status_index_ == 0) {
    past_status_index_ = current_status_index_;
    current_status_index_ = logic_status_index_;
    logic_status_index_ = 1;
  } else if (logic_status_index_ == 1) {
    past_status_index_ = current_status_index_;
    current_status_index_ = logic_status_index_;
    logic_status_index_ = 2;
  } else if (logic_status_index_ == 2) {
    past_status_index_ = current_status_index_;
    current_status_index_ = logic_status_index_;
    logic_status_index_ = 0;
  } else {
    past_status_index_ = 0;
    current_status_index_ = 1;
    logic_status_index_ = 2;
  }
}

void DrawBuffer::SetRenderList(render::RenderList renderlist) {
  drawbuffer_[logic_status_index_] = renderlist;
}

render::RenderList* DrawBuffer::GetCurrentRenderList() {
  return &drawbuffer_[current_status_index_];
}

render::RenderList* DrawBuffer::GetPastRenderList() {
  return &drawbuffer_[past_status_index_];
}

render::RenderList*DrawBuffer:: GetLogicRenderList() {
  return &drawbuffer_[logic_status_index_];
}

}
}
}