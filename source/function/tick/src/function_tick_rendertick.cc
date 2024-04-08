#include "function_tick_rendertick.h"

namespace TuYiLe {
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
  render::pipeline::renderpipeline->ForwardRendering(*(drawbuffer_->GetLogicRenderList()));
  platformlayer::window::windowmanager->Update();
}

// void RenderTick::SetRenderList(render::RenderList renderlist) {
//   drawbuffer_[logic_status_index_] = renderlist;
// }

}
}
}