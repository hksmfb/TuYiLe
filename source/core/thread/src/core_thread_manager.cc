#include "core_thread_manager.h"

namespace TuYiLe{
namespace corelayer {
namespace thread {

ThreadManager::ThreadManager() {
  current_time_ = platformlayer::time::GetTime();
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
    platformlayer::window::windowmanager->InitCurrentThreadContext();
    platformlayer::window::windowmanager->SetCurrentThreadContext();
    int width = platformlayer::window::windowmanager->GetWidth();
    int height = platformlayer::window::windowmanager->GetHeight();
    platformlayer::RHI::SetViewport(0, 0, width, height);
  });
  while (renderthread_.IsOccupied()) {}
  renderthread_.RunTask(Run);
}

void ThreadManager::SetLogicUpdate(std::function<void()> Run) {
  logicthread_.RunTask(Run);
}

void ThreadManager::UpdateThreadPool() {
  double time = current_time_ - platformlayer::time::GetTime();
  if (time > dt) {
    
  }
}

ThreadManager* threadmanager = NULL;

}
}
}