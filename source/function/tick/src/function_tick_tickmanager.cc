#include "function_tick_tickmanager.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

TickManager::TickManager() {
  rendertick_.SetDrawBuffer(&drawbuffer_);
  logictick_.SetDrawBuffer(&drawbuffer_);
}

TickManager::~TickManager() {

}

void TickManager::Run() {
  corelayer::thread::threadmanager->SetLogicUpdate([this](){this->logictick_.Run();});
  corelayer::thread::threadmanager->SetRenderUpdate([this](){this->rendertick_.Run();});
}

void TickManager::SetMaxFps(int max_fps) {
  rendertick_.SetTick(max_fps);
}

void TickManager::SetMaxTick(int max_tick) {
  logictick_.SetTick(max_tick);
}

void TickManager::SetRenderList(render::RenderList renderlist) {
  drawbuffer_.SetRenderList(renderlist);
  printf("count:\n");
  for (auto i : renderlist.GetRenderData()) {
    printf("render\n");
  }
  printf("end cunt\n");
}

TickManager* tickmanager = nullptr;

}
}
}