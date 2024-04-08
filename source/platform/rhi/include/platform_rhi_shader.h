#ifndef PLATFORM_RHI_SHADER_H_
#define PLATFORM_RHI_SHADER_H_

#include <vector>
#include <string>
#include <cstring>
#include <iostream>

#include "glm/glm.hpp"

namespace TuYiLe{
namespace platformlayer {
namespace RHI {

struct shadervariable {
  std::string name;
  union {
    float f;
    int i;
    float vec[4];
    glm::mat4 mat4 {};
  };
};

class Shader {
 public:
  // Shader();
  // ~Shader();
  virtual void Use() = 0;
  virtual void SetFloat(std::string name, float f) = 0;
  virtual void SetInt(std::string name, int i) = 0;
  virtual void SetVec3(std::string name, glm::vec3 vec3) = 0;
  virtual void SetVec3(std::string name, float x, float y, float z) = 0;
  virtual void SetMat4(std::string name, glm::mat4 mat4) = 0;
 protected:
  unsigned int id_;
};

}
}
}

#endif