#include "function_tick_tickmanager.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

TickManager::TickManager() {
  rendertick_.SetTick(30);
  logictick_.SetTick(30);
  corelayer::thread::threadmanager->SetLogicUpdate([this](){this->logictick_.Run();});
  corelayer::thread::threadmanager->SetRenderUpdate([this](){this->rendertick_.Run();});
}

TickManager::~TickManager() {

}

void TickManager::Run() {

}

void TickManager::LogicUpdate() {
  
}

void TickManager::SetMaxFps(int max_fps) {
  rendertick_.SetTick(max_fps);
}

void TickManager::SetMaxTick(int max_tick) {
  logictick_.SetTick(max_tick);
}

TickManager* tickmanager = nullptr;

}
}
}