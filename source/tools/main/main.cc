#include "platform_window_manager.h"

#include "main.h"

int main() {
  GlobalVarInit();
  while (platformlayer::windowmanager->isRunning()) {
    corelayer::threadmanager->UpdateThreadPool();
  }
  return 0;
}