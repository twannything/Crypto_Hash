#include <stdio.h>


unsigned int R_256(unsigned int x, unsigned int n);
unsigned int S_256(unsigned int x, unsigned int n);
unsigned int Ch_256(unsigned int x, unsigned int y, unsigned int z);
unsigned int Maj_256(unsigned int x, unsigned int y, unsigned int z);
unsigned int Sum0_256(unsigned int x);
unsigned int Sum1_256(unsigned int x);
unsigned int Sigma0_256(unsigned int x);
unsigned int Sigma1_256(unsigned int x);
unsigned int Hash256();

unsigned long long R_512(unsigned long long x, unsigned long long n);
unsigned long long S_512(unsigned long long x, unsigned long long n);
unsigned long long Ch_512(unsigned long long x, unsigned long long y, unsigned long long z);
unsigned long long Maj_512(unsigned long long x, unsigned long long y, unsigned long long z);
unsigned long long Sum0_512(unsigned long long x);
unsigned long long Sum1_512(unsigned long long x);
unsigned long long Sigma0_512(unsigned long long x);
unsigned long long Sigma1_512(unsigned long long x);
unsigned int Hash512();