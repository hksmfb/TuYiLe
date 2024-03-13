#ifndef CORE_GUID_MANAGER_H_
#define CORE_GUID_MANAGER_H_

#include "core_thread_manager.h"

namespace corelayer {

typedef unsigned long long guid;

class GUIDManager {
  public:
    guid GetGUID();
    guid RequestGUID();
  private:
    std::mutex mtx_;
    guid guid_ {0};
};

extern GUIDManager* guidmanager;

}

#endif