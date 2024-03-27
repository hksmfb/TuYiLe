#include "platform_data_path.h"

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

Path::~Path() {

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