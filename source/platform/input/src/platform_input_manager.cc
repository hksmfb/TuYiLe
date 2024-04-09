#include "platform_input_manager.h"
#include <iostream>
namespace TuYiLe{
namespace platformlayer {
namespace input {

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::SetWindowSize(int width, int height) {
  window_width_ = width;
  window_height_ = height;
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

float InputManager::GetMousePosxFixed() {
  return 2.0f*mousestatus_.GetPosx()/window_width_ - 1;
}

int InputManager::GetMousePosy() {
  return mousestatus_.GetPosy();
}

float InputManager::GetMousePosyFixed() {
  return 2.0f*mousestatus_.GetPosy()/window_height_ - 1;
}

InputManager* inputmanager = nullptr;

}
}
}