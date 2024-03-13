#ifndef RESOURCE_COMPONENT_H_
#define RESOURCE_COMPONENT_H_

#include <memory>

#include "platform_rhi_mesh.h"
#include "platform_rhi_shader.h"

namespace resourcelayer {

class Component {
 public:
  Component();
  ~Component();
  void SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh);
  std::shared_ptr<platformlayer::RHI::Mesh> GetMesh();
  void SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader);
  std::shared_ptr<platformlayer::RHI::Shader> Getshader();
 private:
  std::shared_ptr<platformlayer::RHI::Mesh> mesh_;
  std::shared_ptr<platformlayer::RHI::Shader> shader_;
};

}


#endif