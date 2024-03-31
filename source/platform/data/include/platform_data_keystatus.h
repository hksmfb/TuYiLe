#ifndef PLATFORM_DATA_KEYSTATUS_H_
#define PLATFORM_DATA_KEYSTATUS_H_

namespace TuYiLe{
namespace platformlayer {
namespace datatype {

struct keystatus {
  unsigned short key {0};
  unsigned short scancode {0};
  unsigned char action {0};
  unsigned char mods {0};
};

}
}
}

#endif