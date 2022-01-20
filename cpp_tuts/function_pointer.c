#include <stdio.h>
#include <stdlib.h>

void even() { printf("Even\n"); }
void odd()  { printf("Odd\n"); }

int main(int argc, char **argv)
{
  if ( argc != 2 ) {
    exit(0);
  }

  void (*parity)() = NULL;

  int x = atoi(argv[1]);

  if ( x % 2 ) {
    parity = &odd;
  } else {
    parity = &even;
  }

  parity();

  return 0;
}
