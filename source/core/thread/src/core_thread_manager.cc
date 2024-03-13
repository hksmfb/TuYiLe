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
  renderthread_.RunTask([](){
    platformlayer::windowmanager->InitCurrentThreadContext();
    platformlayer::windowmanager->SetCurrentThreadContext();
    int width = platformlayer::windowmanager->GetWidth();
    int height = platformlayer::windowmanager->GetHeight();
    platformlayer::RHI::SetViewport(0, 0, width, height);
  });
  while (renderthread_.IsOccupied()) {}
  renderthread_.RunTask(Run);
}

void ThreadManager::UpdateThreadPool() {
  double time = current_time_ - platformlayer::GetTime();
  if (time > dt) {
    
  }
}

ThreadManager* threadmanager = NULL;

}