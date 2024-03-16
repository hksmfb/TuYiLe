#include "function_scene_main.h"

namespace functionlayer {
namespace scene {

MainScene::MainScene() {
platformlayer::datatype::shadercode shadercode;
shadercode.vertex_shader_code = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 coord;
out vec3 color;

void main()
{
  gl_Position = vec4(aPos, 1.0f);
  color = normal;
}  
)";
shadercode.fragment_shader_code = R"(
#version 330 core
in vec3 color;
out vec4 FragColor;
void main()
{
  FragColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);
}  
)";

render::resourceloader::CreateShader(shadercode);

std::vector<float> vec({
  0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
  0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
  -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
  -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  
});
std::vector<unsigned int> ind({
  0, 1, 3,
  1, 2, 3
});
platformlayer::datatype::Mesh mesh;
mesh.SetVertex(vec);
mesh.SetIndex(ind);
render::resourceloader::CreateMesh(mesh);

}

MainScene::~MainScene() {

}

void MainScene::Draw() {
  shader_->Use();
  mesh_->Draw();
}

}
}