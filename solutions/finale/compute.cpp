#include "compute.h"
#include "classes.h"

long* computeFib(int const *n){
  storage<long> store;
  store[0]=0;
  if(!*n){
    return store.get_c();
  }
  store[1]=1;
  if(*n==1){
    return store.get_c();
  }

  for(unsigned i=2; i<=*n;i++)
    store[i]=adder<long>::add(store[i-1],store[i-2]);
  return store.get_c();
}
bool checkPrime_old(int n){
  if((!(n%2))||(!(n%3))||(!(n%5)))
    return 0;
  for(long i=7;i*i<=n;i=i+2)
    if(!(n%i))
      return 0;
  return 1;
}
bool checkPrime(int n){if ((!(n % (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06))) || (!(n % (0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09))) || (!(n % (0x000000000000000A + 0x0000000000000205 + 0x0000000000000805 - 0x0000000000000A0F))))return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);;for (long i=(0x000000000000000E + 0x0000000000000207 + 0x0000000000000807 - 0x0000000000000A15);(i * i <= n) & !!(i * i <= n);i = i + (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06))if (!(n % i))return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);;return (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);};
