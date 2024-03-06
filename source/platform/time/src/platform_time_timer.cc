#include "platform_time_timer.h"

namespace platformlayer {

double GetTime() {
  return glfwGetTime();
}
int GetSystemTime() {
  return 0;
}

}