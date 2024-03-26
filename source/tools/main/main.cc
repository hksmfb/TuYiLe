#include "platform_window_manager.h"

#include "main.h"

int main() {
  GlobalVarInit();
  while (platformlayer::windowmanager->isRunning()) {
    auto time_point = std::chrono::steady_clock::now()+std::chrono::milliseconds(1000);
    std::this_thread::sleep_until(time_point);
    corelayer::threadmanager->UpdateThreadPool();
  }
  return 0;
}