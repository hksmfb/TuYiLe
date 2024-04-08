#include "platform_rhi_opengl_shader.h"

namespace TuYiLe{
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

void OpenGLShader::SetFloat(std::string name, float f) {
  glUniform1f(glGetUniformLocation(id_, name.c_str()), f);
}

void OpenGLShader::SetInt(std::string name, int i) {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), i);
}

void OpenGLShader::SetVec3(std::string name, glm::vec3 vec3) {
  glUniform3fv(glGetUniformLocation(id_, name.c_str()),3, glm::value_ptr(vec3));
}

void OpenGLShader::SetVec3(std::string name, float x, float y, float z) {
  glm::vec3 vec3 = glm::vec3(x, y, z);
  glUniform3fv(glGetUniformLocation(id_, name.c_str()),3, glm::value_ptr(vec3));
}

void OpenGLShader::SetMat4(std::string name, glm::mat4 mat4) {
  glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE,glm::value_ptr(mat4));
}

}
}
}
}