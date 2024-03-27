#include "core_guid_manager.h"

namespace corelayer {

GUIDManager::GUIDManager() {
  resource_handler_ = new std::unordered_map<corelayer::guid, std::string>();
  std::vector<std::vector<std::string>> reserved = platformlayer::file::CsvReader("guid/reserved_value.csv");
  resource_handler_->reserve(reserved.size());
  for (auto& line : reserved) {
    corelayer::guid id = std::stoull(line[0]);
    (*resource_handler_)[id] = line[1];
  }
}

GUIDManager::~GUIDManager() {
  delete resource_handler_;
}

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