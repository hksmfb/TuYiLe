#ifndef PLATFORM_INPUT_KEYBOARD_H_
#define PLATFORM_INPUT_KEYBOARD_H_

#include <array>

#include "platform_data_keystatus.h"

namespace platformlayer {
namespace input {

class KeyBoard {
 public:
  KeyBoard();
  ~KeyBoard();
  datatype::keystatus GetKeyStatus(unsigned short scancode);
  void SetKey(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods
  );
 private:
  std::array<datatype::keystatus, 256> keystatus_;
};

}
}

#endif