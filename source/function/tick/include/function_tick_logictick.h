#ifndef FUNCTION_TICK_LOGICTICK_H_
#define FUNCTION_TICK_LOGICTICK_H_

#include "function_tick_tickbase.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

class LogicTick : public TickBase {
 public:
  LogicTick();
  ~LogicTick();
  void Update();
  render::RenderList GetRenderList();
 private:
  
};

}
}
}

#endif