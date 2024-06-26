#ifndef CORE_GUID_MANAGER_H_
#define CORE_GUID_MANAGER_H_

#include <vector>
#include <unordered_map>

#include "core_thread_manager.h"
#include "platform_file_filesystem.h"
#include "platform_data_path.h"

namespace TuYiLe{
namespace corelayer {
namespace guid {

typedef unsigned long long guid;

class GUIDManager {
 public:
  GUIDManager();
  ~GUIDManager();
  guid GetGUID();
  guid RequestGUID();
 private:
  std::unordered_map<guid, std::string>* resource_handler_ {nullptr};
  std::mutex mtx_;
  guid guid_ {0};
};

extern GUIDManager* guidmanager;

}
}
}

#endif