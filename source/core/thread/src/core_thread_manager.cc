#include "core_thread_manager.h"

namespace corelayer {

ThreadManager::ThreadManager() {
  current_time_ = platformlayer::GetTime();
}

ThreadManager::~ThreadManager() {

}

template<typename Function, typename ... Args>
void ThreadManager::Run(Function&& func, Args&& ... args) {
  tasklist_.push_back([func, args...](){func(args...);});
}

void ThreadManager::AppendTask(std::function<void()> task) {
  tasklist_.push_back(task);
}

void ThreadManager::SetRenderUpdate(std::function<void()> Run) {
  printf("set render update start\n");
  renderthread_.RunTask([](){
    platformlayer::windowmanager->InitCurrentThreadContext();
    platformlayer::windowmanager->SetCurrentThreadContext();
    int width = platformlayer::windowmanager->GetWidth();
    int height = platformlayer::windowmanager->GetHeight();
    platformlayer::RHI::SetViewport(0, 0, width, height);
  });
  printf("render init finish\n");
  while (renderthread_.IsOccupied()) {}
  printf("render run task\n");
  renderthread_.RunTask(Run);
  printf("set render update finish\n");
}

void ThreadManager::SetLogicUpdate(std::function<void()> Run) {
  logicthread_.RunTask([](){
    
  });
  while (logicthread_.IsOccupied()) {}
  renderthread_.RunTask(Run);
  printf("set logic update finish\n");
}

void ThreadManager::UpdateThreadPool() {
  double time = current_time_ - platformlayer::GetTime();
  if (time > dt) {
    
  }
}

ThreadManager* threadmanager = NULL;

}