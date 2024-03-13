#ifndef PLATFORM_RHI_MESH_H_
#define PLATFORM_RHI_MESH_H_

#include <vector>

namespace platformlayer {
namespace RHI {

class Mesh {
 public:
  void SetVertices();
  void SetIndex();
  virtual void Draw() = 0;
 private:
};

}
}

#endif