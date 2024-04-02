#ifndef RESOURCE_SHADER_DEFAULT_H_
#define RESOURCE_SHADER_DEFAULT_H_

#include "platform_data_shadercode.h"

namespace TuYiLe {
namespace resourcelayer {
namespace shader {

struct Default : public platformlayer::datatype::shadercode {
 public:
  Default();
  ~Default();
};

}
}
}

#endif