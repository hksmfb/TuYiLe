#include "platform_window_callback.h"

namespace platformlayer {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width and 
  // height will be significantly larger than specified on retina displays.
  // when width is longer
  //glviewport(bottomleft.x, bottomleft.y, width, height);
  if (width >= height) {
      glViewport((width-height)/2, 0, height, height);
  } else { // when height is longer
      glViewport(0, (height-width)/2, width, width);
  }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
  inputmanager->SetMousePos(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  std::cout << button << ", " << action << ", " << mods << std::endl;
  inputmanager->SetMouseButton(button, button, action, mods);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  std::cout << key << ", " << scancode << ", " << action << ", " << mods << std::endl;
  inputmanager->SetKeyBoard(key, scancode, action, mods);
}

}