#ifndef FUNCTION_GUI_MANAGER_H_
#define FUNCTION_GUI_MANAGER_H_

#include <vector>

#include "function_camera_camerabase.h"
#include "function_gui_guibase.h"
#include "function_gui_block.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class GuiManager {
 public:
  GuiManager();
  ~GuiManager();
  void Update();
  /**
   * @brief Append a block set into blocklist,
   * blocklist contains blocks and their subblocks,
   * use preorder to store blocks.
   * set block shape depth to its corresponding index,
   * update guicamera position to (0,0,blocklist.size()).
  */
  void AppendBlockSet(Block* blockset);
 private:
  GuiBase* current_gui_ {nullptr};
  std::vector<GuiBase*> guilist_ {};
  std::vector<Block*> blocklist_ {};
  functionlayer::camera::CameraBase* guicamera_ {nullptr};
};

}
}
}

#endif