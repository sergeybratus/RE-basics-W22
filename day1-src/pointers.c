#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv){
  void *heapthing=malloc(512);
  printf("Main is at 0x%08llx.\n", (uint64_t) main);
  printf("The call stack is near 0x%08llx.\n",
         (uint64_t) &argc);
  printf("The heap is near 0x%08llx.\n",
         (uint64_t) heapthing);
  
}
