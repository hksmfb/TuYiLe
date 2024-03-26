#ifndef PLATFORM_FILE_FILESYSTEM_H_
#define PLATFORM_FILE_FILESYSTEM_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "stb_image.h"

#include "platform_data_datatype.h"

namespace platformlayer {
namespace file{
struct image {
  unsigned char* data {nullptr};
  int width {0};
  int height {0};
  int nrChannels {3};
  ~image() {
    if (data != nullptr) {
      free(data);
    }
  }
};

std::string TxtReader(std::string path);
std::vector<std::vector<std::string>> CsvReader(std::string path);
std::vector<char> BinaryReader(const std::string& path);
datatype::Texture* ImgReader(std::string path);
datatype::Mesh* MeshReader(std::string path);

}
}


#endif