#include "platform_data_texture.h"

namespace TuYiLe{
namespace platformlayer {
namespace datatype{

Texture::Texture() {

}

Texture::Texture(
  unsigned char* data,
  int width,
  int height,
  int nrchannels
) {
  size_t size = width * height * nrchannels;
  data_.reserve(size);
  for (int i = 0; i < size; ++i) {
    data_.push_back(data[i]);
  }
  width_ = width;
  height_ = height;
  nrChannels_ = nrchannels;
}

Texture::~Texture() {

}

std::vector<unsigned char>& Texture::GetData() {
  return data_;
}

int Texture::GetWidth() {
  return width_;
}

int Texture::GetHeight() {
  return height_;
}

int Texture::GetNumChannels() {
  return nrChannels_;
}

}
}
}