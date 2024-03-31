#ifndef PLATFORM_DATA_TEXTURE_H_
#define PLATFORM_DATA_TEXTURE_H_

#include <vector>

namespace TuYiLe{
namespace platformlayer {
namespace datatype {

class Texture {
 public:
  Texture();
  Texture(
    unsigned char* data,
    int width,
    int height,
    int nrchannels
  );
  ~Texture();
  std::vector<unsigned char>& GetData();
  int GetWidth();
  int GetHeight();
  int GetNumChannels();
 private:
  std::vector<unsigned char> data_;
  int width_ {0};
  int height_ {0};
  int nrChannels_ {3};
};

}
}
}

#endif