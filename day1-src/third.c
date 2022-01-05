#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline))
void guess(int g){
  if(g==42)
    printf("That's right!\n");
  else
    printf("Nope, that's the wrong number.\n");
}


int main(int argc, char **argv){
  if(argc==2){
    guess(atoi(argv[1]));
  }else{
    printf("Give me a number?\n");
  }
}
