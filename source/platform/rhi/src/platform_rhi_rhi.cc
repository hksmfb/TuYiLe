#include "platform_rhi_rhi.h"

namespace platformlayer {
namespace RHI {

graphicinterface::GLInterface* interface = nullptr;

void SetViewport(int posx, int posy, int width, int height) {
  interface->SetViewport(posx, posy, width, height);
}

void ClearColor(int R, int G, int B, float Alpha) {
  interface->ClearColor(R, G, B, Alpha);
}

}
}