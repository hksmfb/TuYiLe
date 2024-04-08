#ifndef PLATFORM_RHI_OPENGL_SHADER_H_
#define PLATFORM_RHI_OPENGL_SHADER_H_

#include "glad/glad.h"
#define GLM_FORCE_SIMD_AVX2
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "platform_rhi_shader.h"

namespace TuYiLe{
namespace platformlayer {
namespace graphicinterface {
namespace opengl {

class OpenGLShader : public RHI::Shader {
 public:
  OpenGLShader(
    std::string& vertex_shader_source,
    std::string& fragment_shader_source
  );
  ~OpenGLShader();
  void Use();
  void SetFloat(std::string name, float f);
  void SetInt(std::string name, int i);
  void SetVec3(std::string name, glm::vec3 vec3);
  void SetVec3(std::string name, float x, float y, float z);
  void SetMat4(std::string name, glm::mat4 mat4);
 private:
  
};

}
}
}
}


#endif