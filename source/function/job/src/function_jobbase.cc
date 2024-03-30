#include "function_job_jobbase.h"

// namespace corelayer {

// Job::Job() {
// finish_ = false;
// }

// Job::~Job() {

// }

// template<typename Function, typename... Args> 
// void Job::SetJob(Function&& func, Args&&... args) {
//   auto* finish = &finish_;
//   std::function<void()> task = [finish, func, args...](){
//     func(args...);
//     *finish = true;
//   };
//   threadpool.run(task);
// }

// bool Job::IsFinished() {
//   return finish_;
// }

// }