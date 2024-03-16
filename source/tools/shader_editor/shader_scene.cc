#include "shader_scene.h"

ShaderScene::ShaderScene() {
  platformlayer::datatype::shadercode code;
  code.vertex_shader_code = platformlayer::file::TxtReader(
    "shaders/shadercode/default/default.vs"
  );
  code.fragment_shader_code = platformlayer::file::TxtReader(
    "shaders/shadercode/default/default.fs"
  );
}

ShaderScene::~ShaderScene() {

}

