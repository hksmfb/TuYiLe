#ifndef PLATFORM_DATA_PATH_H_
#define PLATFORM_DATA_PATH_H_

#include <string>
#include <vector>

namespace platformlayer {
namespace datatype {

class Path {
 public:
  Path();
  Path(std::string path);
  ~Path();
  std::string data();
  std::vector<std::string> GetPath();
 private:
  std::vector<std::string> file_path_;
};

}
}

#endif