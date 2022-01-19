#include <stdio.h>

int main(){
  int  x = -1;
  char c = -2;

  long long y = 10;
  long long z;

  x = x + c;
  
  z = y*x;
  printf( "%su %llx \n", z, z);
  return z;
} 
