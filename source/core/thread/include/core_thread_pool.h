#ifndef CORE_THREAD_POOL_H_
#define CORE_THREAD_POOL_H_

#include <vector>
#include <deque>
#include <thread>

#include "core_thread_threadbase.h"

namespace TuYiLe{
namespace corelayer {
namespace thread{
namespace threadpool{

class ThreadPool {
 public:
  ThreadPool();
  ~ThreadPool();
  int GetSize();
  int NumThreadsOccupied();
  void ShrinkTo(int num_threads);
  void ExpandTo(int num_threads);
  void AppendThread();
  void DeleteThread();
  template<typename Function, typename ... Args>
  void Run(Function&& func, Args&& ... args);
 private:
  void update();
  unsigned int max_thread_num_;
  std::vector<ThreadBase*> threadlist_;
  std::deque<std::function<void()>> tasklist_;
  // std::thread updatethread_;
};

}
}
}
}

#endif