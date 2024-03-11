#ifndef PLATFORM_RHI_OPENGL_MESH_H_
#define PLATFORM_RHI_OPENGL_MESH_H_

#include "glad/glad.h"

#include "platform_rhi_mesh.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

class OpenGLMesh : public RHI::Mesh {
 public:
  OpenGLMesh();
  ~OpenGLMesh();
  void SetVertex(std::vector<float>& vertex);
  void SetIndex(std::vector<unsigned int>& index);
  void Draw();
 private:
  unsigned int vertex_nums_ {0};
  unsigned int VAO_ {0};
  unsigned int VBO_ {0};
  unsigned int EBO_ {0};
};

}
}
}

#endif