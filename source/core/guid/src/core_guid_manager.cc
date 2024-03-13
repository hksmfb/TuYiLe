#include "core_guid_manager.h"

namespace corelayer {

guid GUIDManager::GetGUID() {
  mtx_.lock();
  guid ret = guid_;
  mtx_.unlock();
  return ret;
}

guid GUIDManager::RequestGUID() {
  mtx_.lock();
  guid ret = guid_;
  guid_++;
  mtx_.unlock();
  return ret;
}

GUIDManager* guidmanager = nullptr;

}