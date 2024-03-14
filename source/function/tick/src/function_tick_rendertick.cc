#include "function_tick_rendertick.h"

namespace functionlayer {
namespace tick{

RenderTick::RenderTick() {

}

RenderTick::~RenderTick() {
  
}

void RenderTick::Update() {
  platformlayer::RHI::ClearColor(100,100,100,1);
  render::pipeline::renderpipeline->InitShader();
  render::pipeline::renderpipeline->InitMesh();
  render::pipeline::renderpipeline->ForwardRendering(&drawbuffer_[current_status_index_]);
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