#include "shader_editor.h"

int main() {
  GlobalVarInit();
  while (platformlayer::windowmanager->isRunning()) {
    corelayer::thread::threadmanager->UpdateThreadPool();
  }
  return 0;
}