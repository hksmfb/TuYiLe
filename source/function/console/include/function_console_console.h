#ifndef FUNCTION_CONSOLE_CONSOLE_H_
#define FUNCTION_CONSOLE_CONSOLE_H_

#include <string>
#include <unordered_map>
#include <functional>

namespace TuYiLe {
namespace functionlayer {
namespace console {

class Console {
 public:
  Console();
  ~Console();
  void Init();
  void Run(std::string command);
  void RegistCommand(std::string command, std::function<void()> func);
 private:
  std::unordered_map<std::string, std::function<void()>> commandlist_;
};

}
}
}

#endif