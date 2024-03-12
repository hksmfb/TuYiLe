#include "function_tick_rendertick.h"

namespace functionlayer {
namespace tick{

RenderTick::RenderTick() {

}

RenderTick::~RenderTick() {
  
}

void RenderTick::Update() {
  platformlayer::RHI::ClearColor(0,0,0,1);
  platformlayer::windowmanager->Update();
}

void RenderTick::UpdateDrawbuffer() {
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

}
}