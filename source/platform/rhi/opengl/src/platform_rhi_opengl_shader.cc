#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLShader::OpenGLShader(
  std::vector<char>& vertex_shader_source,
  std::vector<char>& fregment_shader_source
) {
  
}

OpenGLShader::~OpenGLShader() {

}

void OpenGLShader::Use() {
  glUseProgram(id_);
}

}
}
}