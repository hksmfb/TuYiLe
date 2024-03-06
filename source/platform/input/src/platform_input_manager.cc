#include "platform_input_manager.h"

namespace platformlayer {

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::SetKeyBoard(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods) {
  keyboardstatus_.SetKey(key, scancode, action, mods);
}

void InputManager::SetMouseButton(
    unsigned short key,
    unsigned short scancode,
    unsigned char action,
    unsigned char mods) {
  mousestatus_.SetButton(key, scancode, action, mods);
}

void InputManager::SetMousePos(int x, int y) {
  mousestatus_.SetPos(x, y);
}

InputManager* inputmanager = nullptr;

}