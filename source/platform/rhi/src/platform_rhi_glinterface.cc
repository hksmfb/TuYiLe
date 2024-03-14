#include "platform_rhi_glinterface.h"

namespace platformlayer {
namespace graphicinterface {

std::string GLInterface::GetInterfaceName() {
  return interfacename_;
}

void GLInterface::AppendShader(datatype::shadercode shadercode) {
  temp_shader_source_lock_.lock();
  temp_shader_source_list_.push_back(shadercode);
  temp_shader_source_lock_.unlock();
}

std::list<datatype::shadercode> GLInterface::GetTempShaderSourceList() {
  temp_shader_source_lock_.lock();
  std::list<datatype::shadercode> ret(temp_shader_source_list_);
  temp_shader_source_list_.clear();
  temp_shader_source_lock_.unlock();
  return ret;
}

void GLInterface::AppendMesh(datatype::Mesh mesh) {
  temp_mesh_list_lock_.lock();
  temp_mesh_list_.push_back(mesh);
  temp_mesh_list_lock_.unlock();
}

std::list<datatype::Mesh> GLInterface::GetTempMeshList() {
  temp_mesh_list_lock_.lock();
  std::list<datatype::Mesh> ret(temp_mesh_list_);
  temp_mesh_list_.clear();
  temp_mesh_list_lock_.unlock();
  return ret;
}

}
}