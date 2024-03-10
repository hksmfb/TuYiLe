#ifndef PLATFORM_RHI_RHI_H_
#define PLATFORM_RHI_RHI_H_

#include <array>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "platform_rhi_glinterface.h"

namespace platformlayer {
namespace RHI {

extern graphicinterface::GLInterface* interface;

void WindowInit();
void ClearColor(int R, int G, int B, float Alpha);

void DepthTest(bool b);
void WireframeMode(bool b);
void ClearScreen();
int GetViewportHeight();
int GetViewportWidth();

}
}

#endif