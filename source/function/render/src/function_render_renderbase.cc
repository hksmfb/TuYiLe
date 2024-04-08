#include "function_render_renderbase.h"

namespace TuYiLe {
namespace functionlayer {
namespace render {

void RenderBase::SetShader(corelayer::guid::guid id) {
  shaderid_ = id;
  shader_ = resourcelayer::manager::resourcemanager->GetShader(id);
}

void RenderBase::SetShader(std::shared_ptr<platformlayer::RHI::Shader> shader) {
  shaderid_ = 0;
  shader_ = shader;
}

corelayer::guid::guid RenderBase::GetShaderId() {
  return shaderid_;
}

std::shared_ptr<platformlayer::RHI::Shader> RenderBase::GetShader() {
  return shader_;
}

void RenderBase::SetMesh(corelayer::guid::guid id) {
  meshid_ = id;
  mesh_ = resourcelayer::manager::resourcemanager->GetMesh(id);
}

void RenderBase::SetMesh(std::shared_ptr<platformlayer::RHI::Mesh> mesh) {
  meshid_ = 0;
  mesh_ = mesh;
}

corelayer::guid::guid RenderBase::GetMeshId() {
  return meshid_;
}

std::shared_ptr<platformlayer::RHI::Mesh> RenderBase::GetMesh() {
  return mesh_;
}

corelayer::guid::guid RenderBase::GetTexture() {
  return 0;
}

corelayer::guid::guid RenderBase::GetNormal() {
  return 0;
}

void RenderBase::SetTransform(corelayer::math::VecTransform trans) {
  transform_ = trans;
}

corelayer::math::VecTransform RenderBase::GetTransform() {
  return transform_;
}

renderdata RenderBase::GetRenderData() {
  renderdata ret {};
  ret.meshid = meshid_;
  ret.shaderid = shaderid_;
  ret.floatname.reserve(floatlist_.size());
  ret.floatlist.reserve(floatlist_.size());
  for (auto& val : floatlist_) {
    ret.floatname.push_back(val.first);
    ret.floatlist.push_back(val.second);
  }
  ret.intname.reserve(intlist_.size());
  ret.intlist.reserve(intlist_.size());
  for (auto& val : intlist_) {
    ret.intname.push_back(val.first);
    ret.intlist.push_back(val.second);
  }
  ret.mat4name.reserve(mat4list_.size()+1);
  ret.mat4list.reserve(mat4list_.size()+1);
  ret.mat4name.push_back("UniformTransform");
  ret.mat4list.push_back(transform_.GetTransform());
  for (auto& val : mat4list_) {
    ret.mat4name.push_back(val.first);
    ret.mat4list.push_back(val.second);
  }
  ret.vec4name.reserve(vec4list_.size());
  ret.vec4list.reserve(vec4list_.size());
  for (auto& val : vec4list_) {
    ret.vec4name.push_back(val.first);
    ret.vec4list.push_back(val.second);
  }
  ret.vec3name.reserve(vec3list_.size());
  ret.vec3list.reserve(vec3list_.size());
  for (auto& val : vec3list_) {
    ret.vec3name.push_back(val.first);
    ret.vec3list.push_back(val.second);
  }
  ret.vec2name.reserve(vec2list_.size());
  ret.vec2list.reserve(vec2list_.size());
  for (auto& val : vec2list_) {
    ret.vec2name.push_back(val.first);
    ret.vec2list.push_back(val.second);
  }
  return ret;
}

template<typename T> void RenderBase::SetVal(std::string name, T val) {
  
}

void RenderBase::SetInt(std::string name, int val) {
  intlist_[name] = val;
}

void RenderBase::SetFloat(std::string name, float val) {
  floatlist_[name] = val;
}

void RenderBase::SetMat4(std::string name, glm::mat4 val) {
  mat4list_[name] = val;
}

void RenderBase::SetVec4(std::string name, glm::vec4 val) {
  vec4list_[name] = val;
}

void RenderBase::SetVec3(std::string name, glm::vec3 val) {
  vec3list_[name] = val;
}

void RenderBase::SetVec2(std::string name, glm::vec2 val) {
  vec2list_[name] = val;
}

}
}
}