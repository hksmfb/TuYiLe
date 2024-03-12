#ifndef PLATFORM_RHI_SHADER_H_
#define PLATFORM_RHI_SHADER_H_

#include <vector>
#include <string>
#include <cstring>
#include <iostream>

namespace platformlayer {
namespace RHI {

class Shader {
 public:
  Shader();
  ~Shader();
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

#endif