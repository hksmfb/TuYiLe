#include "shader_editor.h"

int main() {
  TuYiLe::GlobalVarInit();
  while (TuYiLe::platformlayer::window::windowmanager->isRunning()) {
    TuYiLe::corelayer::thread::threadmanager->UpdateThreadPool();
  }
  return 0;
}