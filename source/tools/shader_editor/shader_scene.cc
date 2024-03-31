#include "shader_scene.h"

ShaderScene::ShaderScene() {
  TuYiLe::platformlayer::datatype::shadercode code;
  code.vertex_shader_code = TuYiLe::platformlayer::file::TxtReader(
    "shaders/shadercode/default/default.vs"
  );
  code.fragment_shader_code = TuYiLe::platformlayer::file::TxtReader(
    "shaders/shadercode/default/default.fs"
  );
  defaultshader_ = TuYiLe::platformlayer::RHI::CreateShader(code.vertex_shader_code, code.fragment_shader_code);
  TuYiLe::platformlayer::datatype::Mesh mesh;
  mesh.SetVertex(std::vector<float>({
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
  }));
  mesh.SetIndex(std::vector<unsigned int>({
    0, 1, 3,
    1, 2, 3
  }));
  meshrender_.SetShader(defaultshader_);
  
}

ShaderScene::~ShaderScene() {

}

