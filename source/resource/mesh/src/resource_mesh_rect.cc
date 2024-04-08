#include "resource_mesh_rect.h"

namespace TuYiLe {
namespace resourcelayer {
namespace mesh {

Rect::Rect() {
  std::vector<float> vertex({
    -0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0
  });
  std::vector<unsigned int> index({
    0, 1, 2, 0, 2, 3
  });
  SetVertex(vertex);
  SetIndex(index);
}

Rect::~Rect() {

}

}
}
}