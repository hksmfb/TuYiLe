#include "platform_rhi_rhi.h"

namespace platformlayer {
namespace RHI {

graphicinterface::GLInterface* interface = nullptr;

void ClearColor(int R, int G, int B, float Alpha) {
  interface->ClearColor(R, G, B, Alpha);
}

}
}