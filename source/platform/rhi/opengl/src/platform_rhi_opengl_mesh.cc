#include "platform_rhi_opengl_mesh.h"
#include <iostream>
namespace platformlayer {
namespace graphicinterface {
namespace opengl {

OpenGLMesh::OpenGLMesh() {
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  glGenBuffers(1, &EBO_);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

OpenGLMesh::OpenGLMesh(datatype::Mesh mesh) {
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  glGenBuffers(1, &EBO_);
  glBindVertexArray(VAO_);
  SetVertex(mesh.GetVertex());
  SetIndex(mesh.GetIndex());
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0); 
}

OpenGLMesh::~OpenGLMesh() {

}

void OpenGLMesh::SetVertex(std::vector<float>& vertex) {
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
  glDrawElements(GL_TRIANGLES, vertex_nums_, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}

}
}
}