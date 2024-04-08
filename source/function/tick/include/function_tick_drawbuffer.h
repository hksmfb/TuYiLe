#ifndef FUNCTION_TICK_DRAWBUFFER_H_
#define FUNCTION_TICK_DRAWBUFFER_H_

#include "platform_time_timer.h"
#include "function_render_renderlist.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

class DrawBuffer {
 public:
  DrawBuffer();
  ~DrawBuffer();
  void UpdateDrawbuffer();
  void SetRenderList(render::RenderList renderlist);
  render::RenderList* GetCurrentRenderList();
  render::RenderList* GetPastRenderList();
  render::RenderList* GetLogicRenderList();
 private:
  unsigned int past_status_index_ {0};
  unsigned int current_status_index_ {1};
  unsigned int logic_status_index_ {2};
  std::array<double, 3> time {};
  std::array<render::RenderList, 3> drawbuffer_ {};
};

}
}
}

#endif