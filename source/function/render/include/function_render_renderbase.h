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

struct renderdata {
  corelayer::guid::guid meshid {0};
  corelayer::guid::guid shaderid {0};
  std::vector<std::string> floatname;
  std::vector<float> floatlist;
  std::vector<std::string> intname;
  std::vector<int> intlist;
  std::vector<std::string> mat4name;
  std::vector<glm::mat4> mat4list;
  std::vector<std::string> vec4name;
  std::vector<glm::vec4> vec4list;
  std::vector<std::string> vec3name;
  std::vector<glm::vec3> vec3list;
  std::vector<std::string> vec2name;
  std::vector<glm::vec2> vec2list;
};

class RenderBase {
 public:
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
  void SetTransform(corelayer::math::VecTransform trans);
  corelayer::math::VecTransform& GetTransform();
  renderdata GetRenderData();
  template<typename T> void SetVal(std::string name, T val);
  void SetInt(std::string name, int val);
  void SetFloat(std::string name, float val);
  void SetMat4(std::string name, glm::mat4 val);
  void SetVec4(std::string name, glm::vec4 val);
  void SetVec3(std::string name, glm::vec3 val);
  void SetVec2(std::string name, glm::vec2 val);
 protected:
  corelayer::guid::guid shaderid_ {3000};
  std::shared_ptr<platformlayer::RHI::Shader> shader_ {nullptr};
  corelayer::guid::guid meshid_ {0};
  std::shared_ptr<platformlayer::RHI::Mesh> mesh_ {nullptr};
  corelayer::math::VecTransform transform_ {};
  std::unordered_map<std::string, float> floatlist_;
  std::unordered_map<std::string, bool> boollist_;
  std::unordered_map<std::string, int> intlist_;
  std::unordered_map<std::string, glm::mat4> mat4list_;
  std::unordered_map<std::string, glm::vec4> vec4list_;
  std::unordered_map<std::string, glm::vec3> vec3list_;
  std::unordered_map<std::string, glm::vec2> vec2list_;
};

}
}
}

#endif