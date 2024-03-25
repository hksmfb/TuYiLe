#ifndef SHADER_SCENE_H_
#define SHADER_SCENE_H_

#include "function_scene_scenebase.h"

class ShaderScene : public functionlayer::scene::SceneBase {
 public:
  ShaderScene();
  ~ShaderScene();
  void CreateShader();
 private:
  functionlayer::render::MeshRender meshrender_;
  std::shared_ptr<platformlayer::RHI::Shader> defaultshader_;
  std::shared_ptr<platformlayer::RHI::Shader> tempshader_;
  std::shared_ptr<platformlayer::RHI::Mesh> currentmesh_;
};

#endif