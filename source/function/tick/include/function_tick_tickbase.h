#ifndef FUNCTION_TICK_TICKBASE_H_
#define FUNCTION_TICK_TICKBASE_H_

#include <unordered_map>
#include <vector>
#include <list>
#include <chrono>

#include "platform_time_timer.h"
#include "function_scene_manager.h"
#include "function_tick_drawbuffer.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

class TickBase {
 public:
  virtual void Update() = 0;
  void Run();
  void Stop();
  void SetTick(int tick_ps);
  void SetDrawBuffer(DrawBuffer* drawbuffer);
 protected:
  int tick_ {1};
  float dt_ {1.0f};
  DrawBuffer* drawbuffer_;
 private:
  double time_ {0};
  bool shouldstop_ {false};
};

}
}
}

#endif