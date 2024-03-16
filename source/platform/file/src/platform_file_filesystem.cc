#include "platform_file_filesystem.h"

namespace platformlayer {
namespace file{
std::string TxtReader(std::string path) {
  std::ifstream infile;
  infile.open(path, std::ios::in);
  std::stringstream str;
  str << infile.rdbuf();
  std::string ret;
  ret = str.str();
  infile.close();
  return ret;
}

std::vector<char> BinaryReader(const std::string& path) {
  std::ifstream infile;
  infile.open(path, std::ios::in | std::ios::ate | std::ios::binary);
  size_t fileSize = (size_t) infile.tellg();
  std::vector<char> ret(fileSize);
  infile.seekg(0);
  infile.read(ret.data(), fileSize);
  infile.close();
  return ret;
}

datatype::Texture* ImgReader(std::string path) {
  unsigned char* data = nullptr;
  int width = 0;
  int height = 0;
  int nrChannels = 3;
  stbi_set_flip_vertically_on_load(true);
  data = stbi_load(path.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);
  datatype::Texture* ret = new datatype::Texture(data, width, height, nrChannels);
  return ret;
}

}
}