#ifndef PLATFORM_DATA_PATH_H_
#define PLATFORM_DATA_PATH_H_

#include <string>
#include <vector>

namespace TuYiLe{
namespace platformlayer {
namespace datatype {

class Path {
 public:
  Path();
  Path(std::string path);
  Path(const char* path);
  ~Path();
  Path operator=(const char* path);
  std::string data();
  std::vector<std::string> GetPath();
 private:
  std::vector<std::string> split(std::string str,char delim);
  std::vector<std::string> file_path_;
};

}
}
}

#endif