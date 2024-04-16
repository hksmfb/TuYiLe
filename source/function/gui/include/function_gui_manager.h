#ifndef FUNCTION_GUI_MANAGER_H_
#define FUNCTION_GUI_MANAGER_H_

#include <vector>

#include "function_render_renderlist.h"
#include "function_camera_camerabase.h"
#include "function_gui_guibase.h"
#include "function_gui_block.h"
#include "core_math_vectransform.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class GuiManager {
 public:
  GuiManager();
  ~GuiManager();
  void Update();
  void AppendGui(GuiBase* gui);
  void SetCurrentGui(GuiBase* gui);
  /**
   * @brief Append a block set into blocklist,
   * blocklist contains blocks and their subblocks,
   * use preorder to store blocks.
   * set block shape depth to its corresponding index,
   * update guicamera position to (0,0,blocklist.size()).
  */
  void AppendBlockSet(Block* blockset);
  render::RenderList GetCurrentRenderList();
 private:
  void UpdateWindowSize();
  int window_width_ {1};
  int window_height_ {1};
  int viewport_width_ {1};
  int viewport_height_ {1};
  float widthratio_ {1};
  float heightratio_ {1};
  glm::vec4 mousepos_ {glm::vec4(0,0,0,1)};
  GuiBase* current_gui_ {nullptr};
  render::RenderList current_renderlist_;
  std::vector<GuiBase*> guilist_ {};
  std::vector<Block*> blocklist_ {};
  functionlayer::camera::CameraBase* guicamera_ {nullptr};
};

}
}
}

#endif