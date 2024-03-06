#include "core_guid_manager.h"

namespace corelayer {

guid GUIDManager::GetGUID() {
  return guid_;
}

guid GUIDManager::RequestGUID() {
  guid ret = guid_;
  guid_++;
  return ret;
}

GUIDManager* guidmanager = nullptr;

}