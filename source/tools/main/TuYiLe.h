#ifndef TUYILE_H_
#define TUYILE_H_

#include "platform_data_header.h"
#include "platform_file_header.h"
#include "platform_input_header.h"
#include "platform_rhi_header.h"
#include "platform_window_header.h"

#include "core_math_header.h"
#include "core_guid_header.h"
#include "core_thread_header.h"

#include "resource_manager_header.h"
#include "resource_asset_header.h"
#include "resource_component_header.h"

#include "function_render_header.h"
#include "function_tick_header.h"
#include "function_scene_header.h"
#include "function_job_header.h"
#include "function_gameobject_header.h"
#include "function_camera_header.h"
#include "function_console_header.h"

namespace TuYiLe {

struct setting {
  std::string title {"TuYiLe"};
  int width {800};
  int height {800};
  std::string GL {"OpenGL"};
  int maxfps {60};
  int tick {30};
};

void Init(setting init_setting) {
  platformlayer::window::windowmanager = new platformlayer::window::WindowManager(init_setting.width, init_setting.height, init_setting.title);
  platformlayer::input::inputmanager = new platformlayer::input::InputManager();
  corelayer::guid::guidmanager = new corelayer::guid::GUIDManager();
  corelayer::math::randomgenerator = new corelayer::math::Random();
  corelayer::thread::threadmanager = new corelayer::thread::ThreadManager();
  resourcelayer::manager::resourcemanager = new resourcelayer::manager::ResourceManager();
  functionlayer::render::pipeline::renderpipeline = new functionlayer::render::pipeline::RenderPipeline();
  functionlayer::scene::scenemanager = new functionlayer::scene::SceneManager();
  functionlayer::tick::tickmanager = new functionlayer::tick::TickManager();

  // platformlayer::window::windowmanager->SetSize(init_setting.width, init_setting.height);
  platformlayer::window::windowmanager->Init();
  platformlayer::window::windowmanager->GlInterfaceInit(init_setting.GL);
  platformlayer::RHI::Init(init_setting.GL);
  corelayer::thread::threadmanager->Init();
  resourcelayer::manager::resourcemanager->InitBuildinResource();
  functionlayer::scene::scenemanager->Init();
  functionlayer::tick::tickmanager->SetMaxFps(init_setting.maxfps);
  functionlayer::tick::tickmanager->SetMaxTick(init_setting.tick);
}

void SetInitialScene(functionlayer::scene::SceneBase* scene) {
  
}

void Run(float engine_dt) {
  functionlayer::tick::tickmanager->Run();
  float time = 0;
  while (TuYiLe::platformlayer::window::windowmanager->isRunning()) {
    float curr_time = platformlayer::time::GetTime();
    if (curr_time-time < engine_dt) {
      auto time_point = std::chrono::steady_clock::now()+std::chrono::milliseconds((int)(1000*(engine_dt-(curr_time-time))));
      std::this_thread::sleep_until(time_point);
      continue;
    }
    time = platformlayer::time::GetTime();
    TuYiLe::corelayer::thread::threadmanager->UpdateThreadPool();
  }
}

}

#endif