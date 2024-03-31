#include "platform_time_timer.h"

namespace TuYiLe{
namespace platformlayer {
namespace time {
  
double GetTime() {
  return glfwGetTime();
}
int GetSystemTime() {
  return 0;
}

}
}
}