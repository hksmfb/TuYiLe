#include "function_scene_main.h"

namespace functionlayer {
namespace scene {

MainScene::MainScene() {
platformlayer::datatype::shadercode shadercode;
shadercode.vertex_shader_code = R"(
#version 330 core
layout (location = 0) in vec3 aPos; // 位置变量的属性位置值为0

out vec4 vertexColor; // 为片段着色器指定一个颜色输出

void main()
{
    gl_Position = vec4(aPos, 1.0); // 注意我们如何把一个vec3作为vec4的构造器的参数
    vertexColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); // 把输出变量设置为暗红色
}
)";
shadercode.fragment_shader_code = R"(
#version 330 core
out vec4 FragColor;

in vec4 vertexColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）

void main()
{
  FragColor = vertexColor;
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