#ifndef PLATFORM_RHI_OPENGL_SHADER_H_
#define PLATFORM_RHI_OPENGL_SHADER_H_

#include "glad/glad.h"

#include "platform_rhi_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

class OpenGLShader : public RHI::Shader {
 public:
  OpenGLShader(
    std::vector<char>& vertex_shader_source,
    std::vector<char>& fregment_shader_source
  );
  ~OpenGLShader();
  void Use();
  void SetFloat();
  void SetInt();
  void SetVec3();
  void SetMat4();
 private:
  unsigned int id_;
};

}
}
}



#endif