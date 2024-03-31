#ifndef MAIN_H_
#define MAIN_H_

#include "platform_window_manager.h"
#include "platform_input_manager.h"
#include "platform_rhi_initializer.h"
#include "core_guid_manager.h"
#include "core_thread_manager.h"
#include "resource_manager_resourcemanager.h"
#include "function_tick_tickmanager.h"
#include "function_scene_manager.h"
#include "function_scene_main.h"

namespace TuYiLe {
void GlobalVarInit() {
  platformlayer::window::windowmanager = new platformlayer::window::WindowManager(800, 800, "TuYiLe");
  platformlayer::graphicinterface::RhiInitializer("OpenGL");
  platformlayer::input::inputmanager = new platformlayer::input::InputManager();
  corelayer::guid::guidmanager = new corelayer::guid::GUIDManager();
  corelayer::thread::threadmanager = new corelayer::thread::ThreadManager();
  resourcelayer::manager::resourcemanager = new resourcelayer::manager::ResourceManager();
  functionlayer::render::pipeline::renderpipeline = new functionlayer::render::pipeline::RenderPipeline();
  functionlayer::scene::scenemanager = new functionlayer::scene::SceneManager();
  functionlayer::tick::tickmanager = new functionlayer::tick::TickManager();
}
}

#endif