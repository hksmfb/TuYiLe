#include "function_tick_tickbase.h"

namespace functionlayer {
namespace tick {

void TickBase::Run() {
  while (!shouldstop_) {
    if (platformlayer::GetTime()-time_ <dt_) {
      continue;
    }
    time_ = platformlayer::GetTime();
    Update();
  }
}

void TickBase::Stop() {
  shouldstop_ = true;
}

void TickBase::SetTick(int ticks_ps) {
  tick_ = ticks_ps;
  dt_ = tick_ == 0 ? 0 : 1.0f/tick_;
}

}
}