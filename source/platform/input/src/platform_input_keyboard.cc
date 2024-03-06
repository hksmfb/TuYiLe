#include "platform_input_keyboard.h"

namespace platformlayer {
namespace input {

KeyBoard::KeyBoard() {
  for (int i = 0; i < keystatus_.size(); ++i) {
    keystatus_[i].scancode = i;
  }
}

KeyBoard::~KeyBoard() {

}

datatype::keystatus KeyBoard::GetKeyStatus(unsigned short scancode) {
  return keystatus_[scancode];
}

void KeyBoard::SetKey(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods) {
  keystatus_[scancode].key = key;
  keystatus_[scancode].scancode = scancode;
  keystatus_[scancode].action = action;
  keystatus_[scancode].mods = mods;
}

}
}