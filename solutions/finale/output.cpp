#include "output.h"
void outputPrime(long n){
  std::cout<<"Found prime number "<<n<<" in fibonacci sequence"<<std::endl;
}
void outputNPrime_debug(long n){
  std::cout<<"Checked number "<<n<<" in fibonacci sequence"<<std::endl;
}
void outputNPrime_empty(long n){
  return;
}
