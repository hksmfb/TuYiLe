#include "platform_input_mouse.h"

namespace TuYiLe{
namespace platformlayer {
namespace input {

Mouse::Mouse() {
  for (int i = 0; i < buttonstatus_.size(); ++i) {
    buttonstatus_[i].scancode = i;
  }
}

Mouse::~Mouse() {

}

datatype::keystatus Mouse::GetButtonStatus(unsigned short scancode) {
  return buttonstatus_[scancode];
}

void Mouse::SetButton(
  unsigned short key,
  unsigned short scancode,
  unsigned char action,
  unsigned char mods
) {
  buttonstatus_[scancode].key = key;
  buttonstatus_[scancode].scancode = scancode;
  buttonstatus_[scancode].action = action;
  buttonstatus_[scancode].mods = mods;
}

void Mouse::SetPos(int x, int y) {
  posx_ = x;
  posy_ = y;
}

int Mouse::GetPosx() {
  return posx_;
}

int Mouse::GetPosy() {
  return posy_;
}

}
}
}