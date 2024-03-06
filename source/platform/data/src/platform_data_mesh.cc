#include "platform_data_mesh.h"

namespace platformlayer {
namespace datatype {

Mesh::Mesh() {

}

Mesh::~Mesh() {

}

Mesh& Mesh::operator=(const Mesh& m) {
  vertices_.clear();
  indecates_.clear();
  vertices_.reserve(m.vertices_.size());
  indecates_.reserve(m.indecates_.size());
  vertices_ = m.vertices_;
  indecates_ = m.indecates_;
  return *this;
}

void Mesh::reserve(size_t num_vertices) {
  vertices_.reserve(num_vertices);
  indecates_.reserve(num_vertices);
}

void Mesh::SetVertices(std::vector<vertex>& vertices) {
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

void Mesh::SetVertices(std::vector<float>& vertices) {
  size_t size = vertices.size();
  vertices_.clear();
  vertices_.reserve(size);
  vertices_ = vertices;
}

void Mesh::SetIndecates(std::vector<unsigned int>& indecates) {
  size_t size = indecates.size();
  indecates_.clear();
  indecates_.reserve(size);
  indecates_ = indecates;
}

}
}