#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLShader::OpenGLShader(
  std::string& vertex_shader_source,
  std::string& fragment_shader_source
) {
  unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
  char* vertexcode = (char*)vertex_shader_source.c_str();
  glShaderSource(vertex, 1, &vertexcode, NULL);
  unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
  char* fragmentcode = (char*)fragment_shader_source.c_str();
  glShaderSource(fragment, 1, &fragmentcode, NULL);
  int success;
  char infoLog[512];
  glCompileShader(vertex);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  };
  glCompileShader(fragment);
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  };
  id_ = glCreateProgram();
  glAttachShader(id_, vertex);
  glAttachShader(id_, fragment);
  glLinkProgram(id_);
  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id_, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

OpenGLShader::~OpenGLShader() {
  glDeleteProgram(id_);
}

void OpenGLShader::Use() {
  glUseProgram(id_);
}

}
}
}