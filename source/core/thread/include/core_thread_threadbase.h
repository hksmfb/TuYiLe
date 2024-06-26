#ifndef CORE_THREAD_THREADBASE_H_
#define CORE_THREAD_THREADBASE_H_

#include <thread>
#include <functional>
#include <mutex>

#include "platform_window_manager.h"

namespace TuYiLe{
namespace corelayer {
namespace thread{
namespace threadpool {

class ThreadBase {
 public:
  ThreadBase();
  ~ThreadBase();
  template<typename Function, typename... Args> 
  void Run(Function&& func, Args&&... args);
  void RunTask(std::function<void()> task);
  bool IsOccupied();
  void Close();
 private:
  void loop();
  std::mutex task_lock_;
  std::function<void()> task_;
  bool shouldclose_ {false};
  bool occupied_ {false};
  std::thread thread_;
};

}
}
}
}

#endif