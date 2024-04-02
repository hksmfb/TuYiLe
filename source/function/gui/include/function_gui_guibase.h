#ifndef FUNCTION_GUI_GUIBASE_H_
#define FUNCTION_GUI_GUIBASE_H_

#include <vector>

#include "function_gui_block.h"
#include "function_camera_camerabase.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class GuiBase {
 public:
  void SetAspectRatio(float ratio);
  /**
   * @brief Append a block set into blocklist.
   * blocklist contains blocks and their subblocks,
   * use preorder to store blocks.
   * Set block shape depth to its corresponding index,
   * update guicamera position to (0,0,blocklist.size()).
  */
  void AppendBlockSet(Block* blockset);
  /**
   * @brief Update every block in blocklist.
   * Check if should run Hover or Click.
   * Check if Drag or Drop.
  */
  void Update();
 protected:
  std::vector<Block*> blocklist_;
 private:
  float aspect_ratio_ {1};
  std::vector<glm::vec2> track_point_ {{
    glm::vec2(-1,1), glm::vec2(0,1), glm::vec2(1,1),
    glm::vec2(-1,0), glm::vec2(0,0), glm::vec2(0,1),
    glm::vec2(-1,-1), glm::vec2(0,-1), glm::vec2(-1,1)
  }};
  functionlayer::camera::CameraBase* guicamera_ {nullptr};
};

}
}
}

#endif