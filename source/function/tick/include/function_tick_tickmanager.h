#ifndef FUNCTION_TICK_TICKMANAGER_H_
#define FUNCTION_TICK_TICKMANAGER_H_

#include "function_tick_rendertick.h"
#include "function_tick_logictick.h"
#include "core_thread_manager.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

class TickManager {
 public:
  TickManager();
  ~TickManager();
  void Run();
  void LogicUpdate();
  void SetMaxFps(int max_fps);
  void SetMaxTick(int max_tick);

 private:
  RenderTick rendertick_;
  LogicTick logictick_;
};

extern TickManager* tickmanager;

}
}
}

#endif