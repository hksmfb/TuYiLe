#include "function_tick_logictick.h"

namespace TuYiLe {
namespace functionlayer {
namespace tick {

LogicTick::LogicTick() {

}

LogicTick::~LogicTick() {
  
}

void LogicTick::Update() {
  scene::scenemanager->GetScene()->BasicUpdate();
  scene::scenemanager->GetScene()->Update();
}

}
}
}