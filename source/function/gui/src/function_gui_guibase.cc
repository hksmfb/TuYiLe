#include "function_gui_guibase.h"

namespace TuYiLe {
namespace functionlayer {
namespace gui {

void GuiBase::SetAspectRatio(float ratio) {
  aspect_ratio_ = ratio;
  for (auto& p : track_point_) {
    p.x *= ratio;
  }
}

void GuiBase::AppendBlockSet(Block* blockset) {
  blocklist_.push_back(blockset);
}

void GuiBase::Update(glm::vec4& mousepos) {
  for (auto& block : blocklist_) {
    block->CheckHover(mousepos);
  }
}

std::vector<render::RenderBase*> GuiBase::GetAllRender() {
  std::vector<render::RenderBase*> ret {};
  for (auto& block : blocklist_) {
    auto render = block->GetShape()->GetRender();
    render->SetMat4("UniformProjection", glm::mat4(1.0f));
    ret.push_back(render);
  }
  return ret;
}

}
}
}