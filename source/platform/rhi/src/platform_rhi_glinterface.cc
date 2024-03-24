#include "platform_rhi_glinterface.h"

namespace platformlayer {
namespace graphicinterface {

std::string GLInterface::GetInterfaceName() {
  return interfacename_;
}

void GLInterface::AppendShader(datatype::shadercode shadercode, std::shared_ptr<RHI::Shader>* dest) {
  shaderinfo newshaderinfo;
  newshaderinfo.code = shadercode;
  newshaderinfo.dest = dest;
  temp_shader_source_lock_.lock();
  temp_shader_source_list_.push_back(newshaderinfo);
  temp_shader_source_lock_.unlock();
}

void GLInterface::CreateShaderBatch() {
  temp_shader_source_lock_.lock();
  std::list<shaderinfo> shadercodelist(std::move(temp_shader_source_list_));
  temp_shader_source_list_.clear();
  temp_shader_source_lock_.unlock();
  for (auto& shadercode : shadercodelist) {
    *shadercode.dest = CreateShader(shadercode.code);
  }
}

void GLInterface::AppendMesh(datatype::Mesh mesh, std::shared_ptr<RHI::Mesh>* dest) {
  meshinfo newmeshinfo;
  newmeshinfo.mesh = mesh;
  newmeshinfo.dest = dest;
  temp_mesh_list_lock_.lock();
  temp_mesh_list_.push_back(newmeshinfo);
  temp_mesh_list_lock_.unlock();
}

void GLInterface::CreateMeshBatch() {
  temp_mesh_list_lock_.lock();
  std::list<meshinfo> meshlist(std::move(temp_mesh_list_));
  temp_mesh_list_.clear();
  temp_mesh_list_lock_.unlock();
  for (auto& mesh : meshlist) {
    *mesh.dest = CreateMesh(mesh.mesh);
  }
}

}
}