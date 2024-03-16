#ifndef SHADER_SCENE_H_
#define SHADER_SCENE_H_

#include "function_scene_scenebase.h"
#include "function_render_resourceloader.h"
#include "platform_rhi_rhi.h"

class ShaderScene : public functionlayer::scene::SceneBase {
 public:
  ShaderScene();
  ~ShaderScene();
  void CreateShader();
 private:
  std::shared_ptr<platformlayer::RHI::Shader> tempshader_;
  std::shared_ptr<platformlayer::RHI::Mesh> currentmesh_;
};

#endif