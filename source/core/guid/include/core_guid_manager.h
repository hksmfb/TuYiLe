#ifndef CORE_GUID_MANAGER_H_
#define CORE_GUID_MANAGER_H_

#include <vector>
#include <unordered_map>

#include "core_thread_manager.h"
#include "platform_file_filesystem.h"

namespace corelayer {

typedef unsigned long long guid;

class GUIDManager {
 public:
  GUIDManager();
  ~GUIDManager();
  guid GetGUID();
  guid RequestGUID();
 private:
  std::unordered_map<corelayer::guid, std::string>* resource_handler_ {nullptr};
  std::mutex mtx_;
  guid guid_ {0};
};

extern GUIDManager* guidmanager;

}

#endif