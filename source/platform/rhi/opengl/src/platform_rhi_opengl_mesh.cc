#include "platform_rhi_opengl_mesh.h"

namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLMesh::OpenGLMesh() {
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  glGenBuffers(1, &EBO_);
  glVertexAttribPointer(0, 8, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
}

OpenGLMesh::OpenGLMesh(datatype::Mesh mesh) {
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  glGenBuffers(1, &EBO_);
  glVertexAttribPointer(0, 8, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
  SetVertex(mesh.GetVertex());
  SetIndex(mesh.GetIndex());
}

OpenGLMesh::~OpenGLMesh() {

}

void OpenGLMesh::SetVertex(std::vector<float>& vertex) {
  glGenBuffers(1, &VBO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertex.size(), vertex.data(), GL_STATIC_DRAW);
}
  
void OpenGLMesh::SetIndex(std::vector<unsigned int>& index) {
  vertex_nums_ = index.size();
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*index.size(), index.data(), GL_STATIC_DRAW);
}

void OpenGLMesh::Draw() {
  glBindVertexArray(VAO_);
  glVertexAttribPointer(0, 8, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glDrawElements(GL_TRIANGLES, vertex_nums_, GL_UNSIGNED_INT, 0);
}

}
}
}