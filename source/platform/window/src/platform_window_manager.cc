#include "platform_window_manager.h"

namespace platformlayer {

// void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
//   std::cout << button << ", " << action << ", " << mods << std::endl;
// }

WindowManager::WindowManager(int width, int height, std::string title) {
  width_ = width;
  height_ = height;
  title_ = title;
  RHItype_ = RHI::interface->GetInterfaceName();
  if (RHItype_ == std::string("OpenGL")) {
    OpenGLInit();
  } else {
    VulkanInit();
  }
  
}

WindowManager::~WindowManager() {
  glfwTerminate();
}

void WindowManager::OpenGLInit() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  #endif
}

void WindowManager::VulkanInit() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

bool WindowManager::isRunning() {
  if (window_ == NULL || glfwWindowShouldClose(this->window_)) {
    return false;
  } else {
    return true;
  }
}

void WindowManager::dynamic_size(bool b) {
  if (b) {
    glfwSetFramebufferSizeCallback(this->window_, framebuffer_size_callback);
  } else {
    glfwSetFramebufferSizeCallback(this->window_, nullptr);
  }
}

void WindowManager::windowEvent() {
  glfwPollEvents();
}

void WindowManager::Update() {
  // CaptureMouse(functionlayer::controller->GetMouseCaputreStatus());
  glfwPollEvents();
  glfwSwapBuffers(window_);
}

void WindowManager::InitCurrentThreadContext() {
  this->window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL);
  if (this->window_ == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
  if (RHItype_ == std::string("OpenGL")) {
    glfwMakeContextCurrent(this->window_);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glViewport(0,0,width_, height_);
  }
  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
  glfwSetCursorPosCallback(window_, cursor_position_callback);
  glfwSetMouseButtonCallback(window_, mouse_button_callback);
  glfwSetKeyCallback(window_, key_callback);
  CaptureMouse(false);
}

void WindowManager::SetCurrentThreadContext() {
  glfwMakeContextCurrent(this->window_);
}

void WindowManager::ClearColor(float r, float g, float b, float a) {
  glClearColor(r,g,b,a);
  glClear(GL_COLOR_BUFFER_BIT);
}

// datatype::keystatus WindowManager::GetKeyStatus(int scancode) {
//   return keyboardstatus_.GetKeyStatus(scancode);
// }

int WindowManager::GetMouse() {
  return 0;
}

void WindowManager::CaptureMouse(char status) {
  if (status == 0) {
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  } else if (status == 1) {
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
  } else if (status == 2) {
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }
}

WindowManager* windowmanager = NULL;

}


