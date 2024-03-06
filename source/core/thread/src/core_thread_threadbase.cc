#include "core_thread_threadbase.h"

namespace corelayer {
namespace threadpool {

ThreadBase::ThreadBase() {
  task_ = [](){};
  thread_ = std::thread(&ThreadBase::loop, this);
}

ThreadBase::~ThreadBase() {
  occupied_ = false;
  shouldclose_ = true;
  task_ = [](){};
  thread_.join();
}

template<typename Function, typename ... Args>
void ThreadBase::Run(Function&& func, Args&& ... args) {
  task_ = [func, args...](){func(args...);};
  occupied_ = true;
}

void ThreadBase::RunTask(std::function<void()> task) {
  task_ = task;
  occupied_ = true;
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
      task_();
      task_ = [](){};
      occupied_ = false;
    }
  }
}

}
}