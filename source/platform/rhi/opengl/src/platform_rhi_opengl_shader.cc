#include "platform_rhi_opengl_shader.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLShader::OpenGLShader(
  std::string& vertex_shader_source,
  std::string& fragment_shader_source
) {
  printf("opengl shader in\n");
  unsigned int vertex;
  printf("create opengl vertex shader\n");
  vertex = glCreateShader(GL_VERTEX_SHADER);
  size_t size = vertex_shader_source.size();
  char* vertexcode = (char*)vertex_shader_source.c_str();
  printf("set vertex source\n");
  glShaderSource(vertex, 1, &vertexcode, NULL);
  printf("set vertex source complete\n");
  unsigned int fragment;
  printf("create opengl fragment shader\n");
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  char* fragmentcode = (char*)fragment_shader_source.c_str();
  printf("set fragment source\n");
  glShaderSource(fragment, 1, &fragmentcode, NULL);
  printf("set fragment source complete\n");
  int success;
  char infoLog[512];
  printf("compile vertex\n");
  glCompileShader(vertex);
  printf("compile vertex complete\n");
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  };
  printf("compile fragment\n");
  glCompileShader(fragment);
  printf("compile fragment complete\n");
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
  printf("opengl shader out\n");
}

OpenGLShader::~OpenGLShader() {

}

void OpenGLShader::Use() {
  glUseProgram(id_);
}

}
}
}