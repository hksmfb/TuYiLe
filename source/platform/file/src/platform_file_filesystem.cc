#include "platform_file_filesystem.h"

namespace TuYiLe{
namespace platformlayer {
namespace file{

std::string TxtReader(platformlayer::datatype::Path path) {
  std::ifstream infile;
  infile.open(path.data(), std::ios::in);
  std::stringstream str;
  str << infile.rdbuf();
  std::string ret;
  ret = str.str();
  infile.close();
  return ret;
}

std::vector<std::vector<std::string>> CsvReader(platformlayer::datatype::Path path) {
  std::vector<std::vector<std::string>> ret;
  std::ifstream infile;
  infile.open(path.data(), std::ios::in);
  std::string line;
  std::vector<std::string> templine;
  while (!infile.eof()) {
    line.clear();
    std::getline(infile, line);
    std::size_t previous = 0;
    std::size_t current = line.find(',');
    templine.clear();
    while (current != std::string::npos) {
      if (current > previous) {
        templine.push_back(line.substr(previous, current - previous));
      }
      previous = current + 1;
      current = line.find(',', previous);
    }
    templine.push_back(line.substr(previous, std::string::npos));
    ret.push_back(std::move(templine));
  }
  return ret;
}

std::vector<char> BinaryReader(platformlayer::datatype::Path path) {
  std::ifstream infile;
  infile.open(path.data(), std::ios::in | std::ios::ate | std::ios::binary);
  size_t fileSize = (size_t) infile.tellg();
  std::vector<char> ret(fileSize);
  infile.seekg(0);
  infile.read(ret.data(), fileSize);
  infile.close();
  return ret;
}

datatype::Texture* ImgReader(platformlayer::datatype::Path path) {
  unsigned char* data = nullptr;
  int width = 0;
  int height = 0;
  int nrChannels = 3;
  stbi_set_flip_vertically_on_load(true);
  data = stbi_load(path.data().c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);
  datatype::Texture* ret = new datatype::Texture(data, width, height, nrChannels);
  return ret;
}

datatype::Mesh MeshReader(platformlayer::datatype::Path path) {
  std::vector<unsigned int> index;
  std::vector<float> vertex;
  std::ifstream infile;
  infile.open(path.data(), std::ios::in);
  unsigned int size;
  infile >> size;
  index.reserve(size);
  unsigned int ui;
  for (auto i = 0; i < size; ++i) {
    infile >> ui;
    index.push_back(ui);
  }
  float f;
  while (infile >> f) {
    vertex.push_back(f);
  }
  datatype::Mesh ret;
  ret.SetIndex(index);
  ret.SetVertex(vertex);
  return ret;
}

}
}
}