#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#define DEBUG false
#include "compute.h"
#define outputNPrime(Y)  (DEBUG ? outputNPrime_debug(Y) : outputNPrime_empty(Y))
#include<iostream>
void outputPrime(long n);
void outputNPrime_debug(long n);
void outputNPrime_empty(long n);
#endif
