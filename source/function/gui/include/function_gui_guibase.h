#ifndef FUNCTION_GUI_GUIBASE_H_
#define FUNCTION_GUI_GUIBASE_H_

#include <vector>

#include "function_gui_shape.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

class GuiBase {
 public:
 protected:
  std::vector<ShapeBase*> shapelist_;
 private:
  
};

}
}
}

#endif