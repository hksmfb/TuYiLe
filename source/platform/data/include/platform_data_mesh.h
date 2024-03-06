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
    void SetVertices(std::vector<vertex>& vertices);
    void SetVertices(std::vector<float>& vertices);
    void SetIndecates(std::vector<unsigned int>& indecates);
  private:
    std::vector<float> vertices_;
    std::vector<unsigned int> indecates_;
    unsigned int VAO_ {0};
    unsigned int VBO_ {0};
    unsigned int EBO_ {0};
};

}
}

#endif