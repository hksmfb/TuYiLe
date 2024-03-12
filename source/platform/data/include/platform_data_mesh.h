#ifndef PLATFORM_DATA_MESH_H_
#define PLATFORM_DATA_MESH_H_

#include <vector>

#include "platform_data_vertex.h"

namespace platformlayer {
namespace datatype {

class Mesh {
  public:
    Mesh();
    ~Mesh();
    Mesh& operator=(const Mesh& m);
    void reserve(size_t num_vertices);
    void SetVertex(std::vector<vertex>& vertices);
    void SetVertex(std::vector<float>& vertices);
    void SetIndex(std::vector<unsigned int>& indices);
    std::vector<float>& GetVertex();
    std::vector<unsigned int>& GetIndex();
  private:
    std::vector<float> vertices_;
    std::vector<unsigned int> indices_;
};

}
}

#endif