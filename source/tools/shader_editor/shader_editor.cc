#include "shader_editor.h"

int main() {
  GlobalVarInit();
  while (platformlayer::windowmanager->isRunning()) {
    corelayer::threadmanager->UpdateThreadPool();
  }
  return 0;
}