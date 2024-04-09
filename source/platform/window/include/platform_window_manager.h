#ifndef PLATFORM_WINDOW_MANAGER_H_
#define PLATFORM_WINDOW_MANAGER_H_

#include <string>
#include <vector>
#include <array>
#include <iostream>

#include "glad/glad.h"
// #define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "platform_window_callback.h"

namespace TuYiLe{
namespace platformlayer {
namespace window {

class WindowManager {
 public:
  WindowManager(int width, int height, std::string title);
  ~WindowManager();
  void Init();
  void GlInterfaceInit(std::string GL);
  GLFWwindow* GetGLFWwindow();
  void SetSize(int widht, int height);
  int GetWidth();
  int GetHeight();
  /**
   * @brief check if window is running.
   * @return bool.
  */
  bool isRunning();
  /**
   * @brief set window to dynamic size.
  */
  void dynamic_size(bool b);
  /**
   * @brief process window event.
  */
  void windowEvent();
  /**
   * @brief update window (process window event).
  */
  void Update();
  /**
   * @brief input process.
  */
  void InputProcess();
  void InitCurrentThreadContext();
  void SetCurrentThreadContext();
  // /**
  //  * @brief get key from keyboard.
  //  * @param GLFW_KEY
  //  * @return glfw key status.
  // */
  // datatype::keystatus GetKeyStatus(int scancode);
  int GetMouse();
  /**
   * @brief clear window color.
   * @param float red
   * @param float green
   * @param float blue
   * @param float alpha
  */
  void ClearColor(float r, float g, float b, float a);
  /**
   * @brief run window process
  */
  void run();

 private:
  void OpenGLInit();
  void VulkanInit();
  void CaptureMouse(char status);
  std::string RHItype_ {"Vulkan"};
  GLFWwindow* window_;
  int width_ {640};
  int height_ {640};
  std::string title_;
  double mousex_ {0};
  double mousey_ {0};
};

extern WindowManager* windowmanager;

}
}
}

#endif