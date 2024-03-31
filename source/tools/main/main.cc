#include "platform_window_manager.h"

#include "main.h"

int main() {
  TuYiLe::GlobalVarInit();
  while (TuYiLe::platformlayer::window::windowmanager->isRunning()) {
    auto time_point = std::chrono::steady_clock::now()+std::chrono::milliseconds(1000);
    std::this_thread::sleep_until(time_point);
    TuYiLe::corelayer::thread::threadmanager->UpdateThreadPool();
  }
  return 0;
}