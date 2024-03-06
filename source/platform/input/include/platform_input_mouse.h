#ifndef PLATFORM_INPUT_MOUSE_H_
#define PLATFORM_INPUT_MOUSE_H_

#include <array>

#include "platform_data_keystatus.h"

namespace platformlayer {
namespace input {

class Mouse {
 public:
  Mouse();
  ~Mouse();
  datatype::keystatus GetButtonStatus(unsigned short scancode);
  void SetButton(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods);
  void SetPos(int x, int y);
 private:
  int posx_;
  int posy_;
  std::array<datatype::keystatus, 64> buttonstatus_;
};

}
}

#endif