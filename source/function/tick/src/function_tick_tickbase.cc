#include "function_tick_tickbase.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

void TickBase::Run() {
  while (!shouldstop_) {
    if (platformlayer::time::GetTime()-time_ <dt_) {
      auto time_point = std::chrono::steady_clock::now()+std::chrono::milliseconds(int(dt_*1000));
      std::this_thread::sleep_until(time_point);
      continue;
    }
    time_ = platformlayer::time::GetTime();
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

void TickBase::SetDrawBuffer(DrawBuffer* drawbuffer) {
  drawbuffer_ = drawbuffer;
}

}
}
}