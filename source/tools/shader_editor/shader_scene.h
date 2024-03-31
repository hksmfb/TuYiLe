#ifndef SHADER_SCENE_H_
#define SHADER_SCENE_H_

#include "function_scene_scenebase.h"

class ShaderScene : public TuYiLe::functionlayer::scene::SceneBase {
 public:
  ShaderScene();
  ~ShaderScene();
  void CreateShader();
 private:
  TuYiLe::functionlayer::render::MeshRender meshrender_;
  std::shared_ptr<TuYiLe::platformlayer::RHI::Shader> defaultshader_;
  std::shared_ptr<TuYiLe::platformlayer::RHI::Shader> tempshader_;
  std::shared_ptr<TuYiLe::platformlayer::RHI::Mesh> currentmesh_;
};

#endif