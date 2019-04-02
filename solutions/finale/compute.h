#ifndef __COMPUTE_H__
#define __COMPUTE_H__
#include "output.h"

long* computeFib(int const *n);

template<typename T>
class adder{
public:
  static T add(T a, T b){
    return a+b;
  }
};

bool checkPrime(int n);
#endif
