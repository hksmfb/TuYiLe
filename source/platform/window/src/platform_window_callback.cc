#include "platform_window_callback.h"

namespace TuYiLe{
namespace platformlayer {
namespace window{

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width and 
  // height will be significantly larger than specified on retina displays.
  // when width is longer
  //glviewport(bottomleft.x, bottomleft.y, width, height);
  if (width >= height) {
      // glViewport((width-height)/2, 0, height, height);
      RHI::interface->SetViewport((width-height)/2, 0, height, height);
  } else { // when height is longer
      // glViewport(0, (height-width)/2, width, width);
      RHI::interface->SetViewport(0, (height-width)/2, width, width);
  }
  input::inputmanager->SetWindowSize(width, height);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
  input::inputmanager->SetMousePos(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  std::cout << button << ", " << action << ", " << mods << std::endl;
  input::inputmanager->SetMouseButton(button, button, action, mods);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  std::cout << key << ", " << scancode << ", " << action << ", " << mods << std::endl;
  input::inputmanager->SetKeyBoard(key, scancode, action, mods);
}

}
}
}