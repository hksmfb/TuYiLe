#include "core_thread_threadbase.h"

namespace corelayer {
namespace threadpool {

ThreadBase::ThreadBase() {
  task_ = [](){};
  thread_ = std::thread(&ThreadBase::loop, this);
  thread_.detach();
}

ThreadBase::~ThreadBase() {
  occupied_ = false;
  shouldclose_ = true;
  task_ = [](){};
}

template<typename Function, typename ... Args>
void ThreadBase::Run(Function&& func, Args&& ... args) {
  task_ = [func, args...](){func(args...);};
  occupied_ = true;
}

void ThreadBase::RunTask(std::function<void()> task) {
  task_lock_.lock();
  task_ = task;
  occupied_ = true;
  task_lock_.unlock();
}

bool ThreadBase::IsOccupied() {
  return occupied_;
}

void ThreadBase::Close() {
  shouldclose_ = true;
}

void ThreadBase::loop() {
  while (!shouldclose_) {
    if (occupied_) {
      task_lock_.lock();
      task_();
      task_ = [](){};
      occupied_ = false;
      task_lock_.unlock();
    }
  }
}

}
}