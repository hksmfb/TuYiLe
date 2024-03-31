#include "platform_data_path.h"
#include <iostream>

namespace TuYiLe{
namespace platformlayer {
namespace datatype {

Path::Path() {

}

Path::Path(std::string path) {
  if (path.find('/') != std::string::npos) {
    file_path_ = split(path, '/');
  } else if (path.find('\\') != std::string::npos) {
    file_path_ = split(path, '\\');
  } else {

  }
}

Path::Path(const char* path) {
  auto str = std::string(path);
  if (str.find('/') != std::string::npos) {
    file_path_ = split(path, '/');
  } else if (str.find('\\') != std::string::npos) {
    file_path_ = split(path, '\\');
  } else {

  }
}

Path::~Path() {

}

Path Path::operator=(const char* path) {
  return Path(path);
}

std::vector<std::string> Path::split(std::string str,char delim) {
  std::vector<std::string> ret;
  std::size_t previous = 0;
  std::size_t current = str.find(delim);
  int id = 0;
  while (current != std::string::npos) {
    if (current > previous) {
      ret.push_back(str.substr(previous, current - previous));
    }
    previous = current + 1;
    current = str.find(delim, previous);
  }
  ret.push_back(str.substr(previous, std::string::npos));
  return ret;
}

std::string Path::data() {
  std::string ret;
  for (auto& s : file_path_) {
    ret.append(s);
    ret.append("/");
  }
  ret.pop_back();
  return ret;
}

std::vector<std::string> Path::GetPath() {
  return file_path_;
}

}
}
}