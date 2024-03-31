#ifndef FUNCTION_RENDER_RENDERBASE_H_
#define FUNCTION_RENDER_RENDERBASE_H_

#include <unordered_map>
#include <string>

#include "core_guid_manager.h"
#include "core_math_vectransform.h"
#include "resource_manager_resourcemanager.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {
class RenderBase {
 public:
  virtual void Draw() = 0;
  void SetShader(corelayer::guid::guid id);
  void SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader);
  corelayer::guid::guid GetShaderId();
  std::shared_ptr<platformlayer::RHI::Shader> GetShader();
  void SetMesh(corelayer::guid::guid id);
  void SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh);
  corelayer::guid::guid GetMeshId();
  std::shared_ptr<platformlayer::RHI::Mesh> GetMesh();
  corelayer::guid::guid GetTexture();
  corelayer::guid::guid GetNormal();
 protected:
  corelayer::guid::guid shaderid_ {0};
  std::shared_ptr<platformlayer::RHI::Shader> shader_ {nullptr};
  corelayer::guid::guid meshid_ {0};
  std::shared_ptr<platformlayer::RHI::Mesh> mesh_ {nullptr};
  corelayer::math::VecTransform transform_;
  std::unordered_map<std::string, float> floatlist_;
  std::unordered_map<std::string, bool> boollist_;
  std::unordered_map<std::string, int> intlist_;
  std::unordered_map<std::string, glm::mat4> mat4list_;
  std::unordered_map<std::string, glm::vec3> vec3list_;
};

}
}
}

#endif