#ifndef PLATFORM_INPUT_MANAGER_H_
#define PLATFORM_INPUT_MANAGER_H_

#include "platform_input_keyboard.h"
#include "platform_input_mouse.h"

namespace platformlayer {

class InputManager {
 public:
  InputManager();
  ~InputManager();
  void SetKeyBoard(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods
  );
  void SetMouseButton(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods
  );
  void SetMousePos(int x, int y);
 private:
  input::Mouse mousestatus_;
  input::KeyBoard keyboardstatus_;
};

extern InputManager* inputmanager;

}

#endif