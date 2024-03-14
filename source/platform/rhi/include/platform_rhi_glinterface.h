#ifndef PLATFORM_RHI_GLINTERFACE_H_
#define PLATFORM_RHI_GLINTERFACE_H_

#include <string>
#include <list>
#include <mutex>
#include <memory>

#include "glad/glad.h"
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "platform_window_manager.h"
#include "platform_data_datatype.h"
#include "platform_rhi_shader.h"
#include "platform_rhi_mesh.h"

namespace platformlayer {
namespace graphicinterface {

class GLInterface {
 public:
  virtual void WindowInit() = 0;
  virtual void ClearColor(int R, int G, int B, float Alpha) = 0;
  virtual void SetViewport(int posx, int posy, int width, int height) = 0;
  virtual std::shared_ptr<RHI::Mesh> CreateMesh(datatype::Mesh mesh) = 0;
  virtual std::shared_ptr<RHI::Shader> CreateShader(datatype::shadercode shadercode) = 0;
  std::string GetInterfaceName();
  void AppendShader(datatype::shadercode shadercode);
  std::list<datatype::shadercode> GetTempShaderSourceList();
  void AppendMesh(datatype::Mesh mesh);
  std::list<datatype::Mesh> GetTempMeshList();
 protected:
  std::string interfacename_ {"Vulkan"};
  std::mutex temp_shader_source_lock_;
  std::list<datatype::shadercode> temp_shader_source_list_;
  std::mutex temp_mesh_list_lock_;
  std::list<datatype::Mesh> temp_mesh_list_;
 private:
};

}
}

#endif