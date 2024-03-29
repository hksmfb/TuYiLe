#ifndef SHADER_EDITOR_
#define SHADER_EDITOR_

#include "platform_window_manager.h"
#include "platform_input_manager.h"
#include "platform_rhi_initializer.h"
#include "core_guid_manager.h"
#include "core_thread_manager.h"
#include "resource_manager_resourcemanager.h"
#include "function_tick_tickmanager.h"
#include "function_scene_manager.h"
#include "shader_scene.h"

void GlobalVarInit() {
  platformlayer::windowmanager = new platformlayer::WindowManager(800, 800, "TuYiLe");
  platformlayer::graphicinterface::RhiInitializer("OpenGL");
  platformlayer::inputmanager = new platformlayer::InputManager();
  corelayer::guidmanager = new corelayer::GUIDManager();
  corelayer::thread::threadmanager = new corelayer::thread::ThreadManager();
  resourcelayer::resourcemanager = new resourcelayer::ResourceManager();
  functionlayer::tick::tickmanager = new functionlayer::tick::TickManager();
  functionlayer::render::pipeline::renderpipeline = new functionlayer::render::pipeline::RenderPipeline();
  functionlayer::scene::scenemanager = new functionlayer::scene::SceneManager(new ShaderScene());
}

#endif