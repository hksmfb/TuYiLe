#include "platform_input_manager.h"

namespace TuYiLe{
namespace platformlayer {
namespace input {

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::SetKeyBoard(
  unsigned short key,
  unsigned short scancode,
  unsigned char action,
  unsigned char mods
) {
  keyboardstatus_.SetKey(key, scancode, action, mods);
}

datatype::keystatus InputManager::GetKeyBoard(unsigned short scancode) {
  return keyboardstatus_.GetKeyStatus(scancode);
}

void InputManager::SetMouseButton(
  unsigned short key,
  unsigned short scancode,
  unsigned char action,
  unsigned char mods
) {
  mousestatus_.SetButton(key, scancode, action, mods);
}

datatype::keystatus InputManager::GetMouseKey(unsigned short scancode) {
  return mousestatus_.GetButtonStatus(scancode);
}

void InputManager::SetMousePos(int x, int y) {
  mousestatus_.SetPos(x, y);
}

int InputManager::GetMousePosx() {
  return mousestatus_.GetPosx();
}

int InputManager::GetMousePosy() {
  return mousestatus_.GetPosy();
}

InputManager* inputmanager = nullptr;

}
}
}