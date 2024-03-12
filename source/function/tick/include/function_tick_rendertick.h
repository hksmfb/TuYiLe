#ifndef FUNCTION_TICK_RENDERTICK_H_
#define FUNCTION_TICK_RENDERTICK_H_

#include <array>

#include "function_tick_tickbase.h"
#include "function_render_renderlist.h"
#include "platform_window_manager.h"
#include "platform_rhi_rhi.h"

namespace functionlayer {
namespace tick {

class RenderTick : public TickBase {
 public:
  RenderTick();
  ~RenderTick();
  void Update();
  void UpdateDrawbuffer();
 private:
  unsigned int current_status_index_ {1};
  unsigned int past_status_index_ {0};
  unsigned int logic_status_index_ {2};
  std::array<render::RenderList, 3> drawbuffer_;
};

}
}

#endif