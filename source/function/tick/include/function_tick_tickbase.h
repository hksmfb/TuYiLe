#ifndef FUNCTION_TICK_TICKBASE_H_
#define FUNCTION_TICK_TICKBASE_H_

#include <unordered_map>
#include <vector>
#include <list>

#include "platform_time_timer.h"
#include "function_scene_manager.h"

namespace functionlayer {
namespace tick {

class TickBase {
 public:
  virtual void Update() = 0;
  void Run();
  void Stop();
  void SetTick(int tick_ps);
 protected:
  int tick_ {1};
  float dt_ {1.0f};
 private:
  double time_ {0};
  bool shouldstop_ {false};
};

}
}

#endif