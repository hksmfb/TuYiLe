#include "function_scene_main.h"

namespace functionlayer {
namespace scene {

MainScene::MainScene() {
std::string vert = R"(
#version 330 core
layout (location = 0) in vec3 aPos; // 位置变量的属性位置值为0

out vec4 vertexColor; // 为片段着色器指定一个颜色输出

void main()
{
    gl_Position = vec4(aPos, 1.0); // 注意我们如何把一个vec3作为vec4的构造器的参数
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // 把输出变量设置为暗红色
}
)";
std::string frag = R"(
#version 330 core
out vec4 FragColor;

in vec4 vertexColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）

void main()
{
    FragColor = vertexColor;
}
)";
shader_ = platformlayer::RHI::CreateShader(vert, frag);
std::vector<float> vec({
  0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
  -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
  0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f ,0.0f, 0.0f
});
std::vector<unsigned int> ind({
  0, 1, 3,
  1, 2, 3
});
platformlayer::datatype::Mesh mesh;
mesh.SetVertex(vec);
mesh.SetIndex(ind);
mesh_ = platformlayer::RHI::CreateMesh(mesh);
}

MainScene::~MainScene() {

}

void MainScene::Draw() {
printf("scene draw in\n");
shader_->Use();
mesh_->Draw();
printf("scene draw in\n");
}

}
}