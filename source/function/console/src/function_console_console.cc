#include "function_console_console.h"

namespace functionlayer {
namespace console {

Console::Console() {
  //todo
  #ifdef DEVMOD
  printf("Create Console\n");
  #endif
}

Console::~Console() {
  //todo
}

void Console::Init() {
  //todo
  #ifdef DEVMOD
  printf("Init Console\n");
  #endif
}

void Console::Run(std::string command) {
  //todo
  #ifdef DEVMOD
  std::cout << "Console::Run(" << command << ")\n";
  #endif
}

void Console::RegistCommand(std::string command, std::function<void()> func) {
  //todo
  #ifdef DEVMOD
  std::cout << "Console::RegistCommand(" << command << ")\n";
  #endif
}

}
}