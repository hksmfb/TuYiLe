#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLShader::OpenGLShader() {

}

OpenGLShader::~OpenGLShader() {

}

void OpenGLShader::Use() {
  glUseProgram(id_);
}

}
}
}