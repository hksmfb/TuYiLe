#ifndef FUNCTION_TICK_TICKMANAGER_H_
#define FUNCTION_TICK_TICKMANAGER_H_

#include "function_tick_rendertick.h"
#include "function_tick_logictick.h"
#include "function_render_renderlist.h"
#include "core_thread_manager.h"
#include "function_tick_drawbuffer.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

class TickManager {
 public:
  TickManager();
  ~TickManager();
  void Run();
  void SetMaxFps(int max_fps);
  void SetMaxTick(int max_tick);
  void SetRenderList(render::RenderList renderlist);
 private:
  RenderTick rendertick_;
  LogicTick logictick_;
  DrawBuffer drawbuffer_;
};

extern TickManager* tickmanager;

}
}
}

#endif