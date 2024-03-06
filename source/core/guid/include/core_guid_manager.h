#ifndef CORE_GUID_MANAGER_H_
#define CORE_GUID_MANAGER_H_

namespace corelayer {

typedef unsigned long long guid;

class GUIDManager {
  public:
    guid GetGUID();
    guid RequestGUID();
  private:
    guid guid_ {0};
};

extern GUIDManager* guidmanager;

}

#endif