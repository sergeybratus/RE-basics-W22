#include <stdio.h>

int main(int argc, char **argv)
{
  int i = 0;

  while ( i < 10 ) {
    printf("Loop: %d\n", i);
    i += 1;
  }

  return 0;
}
