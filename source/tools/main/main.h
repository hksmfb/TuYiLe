#ifndef MAIN_H_
#define MAIN_H_

#include "platform_window_manager.h"
#include "platform_input_manager.h"
#include "platform_rhi_initializer.h"
#include "core_guid_manager.h"
#include "core_thread_manager.h"
#include "resource_manager_resourcemanager.h"
#include "function_tick_tickmanager.h"

void GlobalVarInit() {
  platformlayer::windowmanager = new platformlayer::WindowManager(800, 800, "TuYiLe");
  platformlayer::graphicinterface::RhiInitializer("Vulkan");
  platformlayer::inputmanager = new platformlayer::InputManager();
  corelayer::guidmanager = new corelayer::GUIDManager();
  corelayer::threadmanager = new corelayer::ThreadManager();
  resourcelayer::resourcemanager = new resourcelayer::ResourceManager();
  functionlayer::tick::tickmanager = new functionlayer::tick::TickManager();
}

#endif