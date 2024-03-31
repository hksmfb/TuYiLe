#ifndef FUNCTION_RENDER_MESRENDER_H_
#define FUNCTION_RENDER_MESRENDER_H_

#include <memory>
#include <unordered_map>
#include <string>

#include "function_render_renderbase.h"
#include "platform_data_datatype.h"
#include "platform_rhi_rhi.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {
class MeshRender : public RenderBase{
 public:
  MeshRender();
  ~MeshRender();
  void SetTexture(platformlayer::datatype::Texture* texture);
  void SetTransform(const corelayer::math::VecTransform& trans);
  void Draw();
  void DrawInstance();
  void SetBool(const std::string &name, bool value);
  void SetInt(const std::string &name, int value);
  void SetFloat(const std::string &name, float value);
  void SetMat4(const std::string &name, const glm::mat4& mat);
  void SetVec3(const std::string &name, const glm::vec3& vec);
 private:
  platformlayer::datatype::Texture* texture_;
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