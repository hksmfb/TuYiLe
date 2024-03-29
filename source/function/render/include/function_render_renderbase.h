#ifndef FUNCTION_RENDER_RENDERBASE_H_
#define FUNCTION_RENDER_RENDERBASE_H_

#include <unordered_map>
#include <string>

#include "core_guid_manager.h"
#include "core_math_vectransform.h"
#include "resource_manager_resourcemanager.h"

namespace functionlayer {
namespace render {
class RenderBase {
 public:
  virtual void Draw() = 0;
  void SetShader(corelayer::guid id);
  void SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader);
  corelayer::guid GetShaderId();
  std::shared_ptr<platformlayer::RHI::Shader> GetShader();
  void SetMesh(corelayer::guid id);
  void SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh);
  corelayer::guid GetMeshId();
  std::shared_ptr<platformlayer::RHI::Mesh> GetMesh();
  corelayer::guid GetTexture();
  corelayer::guid GetNormal();
 protected:
  corelayer::guid shaderid_ {0};
  std::shared_ptr<platformlayer::RHI::Shader> shader_ {nullptr};
  corelayer::guid meshid_ {0};
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

#endif