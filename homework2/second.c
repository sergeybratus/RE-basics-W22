#include <stdio.h>

int square(int i){
  return i*i;
}

int main(int argc, char **argv){
  for(int i=0; i<10; i++){
    printf("The square of %d is %d.\n",
           i, square(i));
  }
}
