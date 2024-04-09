#ifndef PLATFORM_INPUT_MANAGER_H_
#define PLATFORM_INPUT_MANAGER_H_

#include "platform_input_keyboard.h"
#include "platform_input_mouse.h"

namespace TuYiLe{
namespace platformlayer {
namespace input {
  
class InputManager {
 public:
  InputManager();
  ~InputManager();
  void SetWindowSize(int width, int height);
  void SetKeyBoard(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods
  );
  datatype::keystatus GetKeyBoard(unsigned short scancode);
  void SetMouseButton(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods
  );
  datatype::keystatus GetMouseKey(unsigned short scancode);
  void SetMousePos(int x, int y);
  int GetMousePosx();
  float GetMousePosxFixed();
  int GetMousePosy();
  float GetMousePosyFixed();
 private:
  int window_width_ {1};
  int window_height_ {1};
  input::Mouse mousestatus_ {};
  input::KeyBoard keyboardstatus_ {};
};

extern InputManager* inputmanager;

}
}
}

#endif