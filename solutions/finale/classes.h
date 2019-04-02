#ifndef __CLASSES_H__
#define __CLASSES_H__
#include <vector>
#include <iostream>
#include <cstdint>
#include <cstring>

template<typename T>
class storage{
public:
  T& operator[](std::size_t idx){
    if(storage_vector.size()<=idx){
      T dummy;
      for(int n=0; n<=idx;n++)
        storage_vector.push_back(dummy);
    }
    return storage_vector[idx];
  }
  T* get_c(){
    T* ret = new T[storage_vector.size()];
    memcpy(ret, storage_vector.data(), sizeof(T)*storage_vector.size());
    return ret;
  }
protected:
  std::vector<T> storage_vector;
};
#endif
