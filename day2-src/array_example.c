#include <stdio.h>
#include <stdlib.h>

int int_array[0x10] = {0x12, 0x34, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
		       0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x43, 0x21};

int main(int argc, char**argv)
{
  if ( argc != 2 ) {
    exit(0);
  }

  int index = atoi(argv[1]);

  if ( index > 0xf ) {
    exit(0);
  }

  printf("Index %d: %x\n", index, int_array[index]);

  return 0;
}
