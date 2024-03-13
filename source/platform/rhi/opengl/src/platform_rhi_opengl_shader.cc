#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLShader::OpenGLShader(
  std::string& vertex_shader_source,
  std::string& fragment_shader_source
) {
  printf("in\n");
  unsigned int vertex;
  printf("createshader\n");
  vertex = glCreateShader(GL_VERTEX_SHADER);
  char* vertexcode;
  printf("strcpy\n");
  strcpy(vertexcode, vertex_shader_source.c_str());
  glShaderSource(vertex, 1, &vertexcode, NULL);
  unsigned int fragment;
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  char* fragmentcode;
  strcpy(fragmentcode, fragment_shader_source.c_str());
  glShaderSource(fragment, 1, &fragmentcode, NULL);
  int success;
  char infoLog[512];
  printf("compile vertex\n");
  glCompileShader(vertex);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  };
  printf("compile fragment\n");
  glCompileShader(fragment);
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  };
  printf("create program\n");
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
  printf("out");
}

OpenGLShader::~OpenGLShader() {

}

void OpenGLShader::Use() {
  glUseProgram(id_);
}

}
}
}