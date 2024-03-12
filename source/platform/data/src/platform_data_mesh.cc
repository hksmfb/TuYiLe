#include "platform_data_mesh.h"

namespace platformlayer {
namespace datatype {

Mesh::Mesh() {

}

Mesh::~Mesh() {

}

Mesh& Mesh::operator=(const Mesh& m) {
  vertices_.clear();
  indices_.clear();
  vertices_.reserve(m.vertices_.size());
  indices_.reserve(m.indices_.size());
  vertices_ = m.vertices_;
  indices_ = m.indices_;
  return *this;
}

void Mesh::reserve(size_t num_vertices) {
  vertices_.reserve(num_vertices);
  indices_.reserve(num_vertices);
}

void Mesh::SetVertex(std::vector<vertex>& vertices) {
  size_t size = vertices.size()*8;
  vertices_.clear();
  vertices_.reserve(size);
  for(auto& i : vertices) {
    vertices_.insert(
      vertices_.end(),
      {
        i.position[0], i.position[1], i.position[2],
        i.normal[0], i.normal[1], i.normal[2],
        i.coordinate[0], i.coordinate[1]
      }
    );
  }
}

void Mesh::SetVertex(std::vector<float>& vertices) {
  size_t size = vertices.size();
  vertices_.clear();
  vertices_.reserve(size);
  vertices_ = vertices;
}

void Mesh::SetIndex(std::vector<unsigned int>& indices) {
  size_t size = indices.size();
  indices_.clear();
  indices_.reserve(size);
  indices_ = indices;
}

std::vector<float>& Mesh::GetVertex() {
  return vertices_;
}

std::vector<unsigned int>& Mesh::GetIndex() {
  return indices_;
}

}
}