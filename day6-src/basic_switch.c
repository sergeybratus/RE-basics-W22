#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if ( argc != 2 ) {
    exit(0);
  }

  switch(argv[1][0]) {
    case 'A':
      printf("You pass\n");
      break;
   case 'B':
      printf("Yep, still pass\n");
      break;
   case 'C':
      printf("I guess, but really?\n");
      break;
   default:
      printf("Nope\n");
      break;
  }

  return 0;
}
