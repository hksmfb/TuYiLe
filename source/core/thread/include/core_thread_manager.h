#ifndef CORE_THREAD_MANAGER_H_
#define CORE_THREAD_MANAGER_H_

#include <vector>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <tuple>
#include <functional>
#include <deque>

#include <time.h>

#include "core_thread_pool.h"
#include "platform_time_timer.h"
#include "platform_rhi_rhi.h"

namespace TuYiLe{
namespace corelayer {
namespace thread {

class ThreadManager {
 public:
  ThreadManager();
  ~ThreadManager();
  template<typename Function, typename... Args> 
  void Run(Function&& func, Args&&... args);
  void AppendTask(std::function<void()> task);
  void SetRenderUpdate(std::function<void()> Run);
  void SetLogicUpdate(std::function<void()> Run);
  void UpdateThreadPool();
  bool IsOccupied();
 private:
  double current_time_ {0};
  double dt {1};
  threadpool::ThreadBase renderthread_;
  threadpool::ThreadBase logicthread_;
  std::deque<std::function<void()>> tasklist_;
  threadpool::ThreadPool threadpool_;
};

extern ThreadManager* threadmanager;

}
}
}

#endif