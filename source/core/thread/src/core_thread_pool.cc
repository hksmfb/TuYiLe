#include "core_thread_pool.h"

namespace TuYiLe{
namespace corelayer {
namespace thread{
namespace threadpool{

ThreadPool::ThreadPool() {
  max_thread_num_ = std::thread::hardware_concurrency();
  // for (int i = 0; i < 2; ++i) {
  //   threadlist_.push_back(new ThreadBase());
  // }
}

ThreadPool::~ThreadPool() {
  for (auto thread : threadlist_) {
    delete thread;
  }
}

void ThreadPool::update() {
  while(true) {
    for (auto thread : threadlist_) {
      if (!(thread->IsOccupied()) && tasklist_.size() > 0) {
        thread->RunTask(*(tasklist_.begin()));
        tasklist_.pop_front();
      }
      if (tasklist_.size() == 0) {
        DeleteThread();
        break;
      }
    }
    if (tasklist_.size() > 0) {
      AppendThread();
    }
  }
}

int ThreadPool::GetSize() {
  return threadlist_.size();
}

int ThreadPool::NumThreadsOccupied() {
  int count = 0;
  for (auto thread : threadlist_) {
    if (thread->IsOccupied()) {
      ++count;
    }
  }
  return count;
}

void ThreadPool::ShrinkTo(int num_threads) {
  int count = threadlist_.size()-num_threads;
  for (auto thread : threadlist_) {
    if (count > 0 && !(thread->IsOccupied())) {
      delete thread;
      --count;
    }
  }
  while(count > 0) {

    --count;
  }
}
void ExpandTo(int num_threads);

void ThreadPool::AppendThread() {
  if (threadlist_.size() < max_thread_num_-2) {
    threadlist_.push_back(new ThreadBase());
  }
}

void ThreadPool::DeleteThread() {
  if (threadlist_.size() > 1) {
    for (auto thread : threadlist_) {
      if (!(thread->IsOccupied())) {
        delete thread;
        break;
      }
    }
  }
}

template<typename Function, typename ... Args>
void ThreadPool::Run(Function&& func, Args&& ... args) {
  std::function<void()> task = [func, args...](){func(args...);};
  tasklist_.push_back(task);
}

}
}
}
}