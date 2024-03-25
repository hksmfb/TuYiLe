#include "function_tick_tickmanager.h"

namespace functionlayer {
namespace tick {

TickManager::TickManager() {
  rendertick_.SetTick(60);
  logictick_.SetTick(60);
  printf("init logic tick\n");
  corelayer::threadmanager->SetLogicUpdate([this](){printf("aa\n");this->logictick_.Run();});
  printf("init render tick\n");
  corelayer::threadmanager->SetRenderUpdate([this](){printf("bb\n");this->rendertick_.Run();});
  printf("tick init finish\n");
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