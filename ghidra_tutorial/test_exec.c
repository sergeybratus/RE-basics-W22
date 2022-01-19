#include <stdio.h>
#include <stdlib.h>

unsigned char assembly[] = {
  0x48, 0x89, 0xf8, 0xc3
};
unsigned int assembly_len = 4;

int main( int argc, char **argv)
{
  int retval = 0;

  int (*sc)(int) = (int(*)(int))assembly;

  retval = sc( atoi(argv[1])  );

  printf("Return value: %d\n", retval);

  return 0;
}
