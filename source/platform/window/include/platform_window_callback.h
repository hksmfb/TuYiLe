#ifndef PLATFORM_WINDOW_CALLBACK_H_
#define PLATFORM_WINDOW_CALLBACK_H_

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "platform_input_manager.h"

namespace platformlayer {

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

}

#endif