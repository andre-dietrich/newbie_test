#include<iostream>
#include <stdio.h>
#include "main.h"
#include "output.h"
#include "compute.h"

int main() {
  int n;

  std::cout << "Bitte gib eine Zahl ein: ";

  std::cin >> n;

  long* fibs = computeFib(&n);
  ++n;
  while(n--){
    if(checkPrime(fibs[n]))
      outputPrime(fibs[n]);
    else
      outputNPrime(fibs[n]);
  }
  return 0;
}
