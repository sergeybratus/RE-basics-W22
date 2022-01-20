#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
  if ( argc != 2 ) {
    exit(0);
  }

  switch (argv[1][0]) {
    case 'A':
      printf("You entered 'A'\n");
      break;
    case 'B':
      printf("You entered 'B'\n");
      break;
    case 'C':
      printf("You entered 'C'\n");
      break;
    case 'D':
      printf("You entered 'D'\n");
      break;
    case 'E':
      printf("You entered 'E'\n");
      break;
    case 'F':
      printf("You entered 'F'\n");
      break;
    case 'G':
      printf("You entered 'G'\n");
      break;
    case 'H':
      printf("You entered 'H'\n");
      break;
    case 'I':
      printf("You entered 'I'\n");
      break;
    case 'J':
      printf("You entered 'J'\n");
      break;
    case 'K':
      printf("You entered 'K'\n");
      break;
    case 'L':
      printf("You entered 'L'\n");
      break;
    case 'M':
      printf("You entered 'M'\n");
      break;
    case 'N':
      printf("You entered 'N'\n");
      break;
    case 'O':
      printf("You entered 'O'\n");
      break;
    case 'P':
      printf("You entered 'P'\n");
      break;
    case 'Q':
      printf("You entered 'Q'\n");
      break;
    case 'R':
      printf("You entered 'R'\n");
      break;
    case 'S':
      printf("You entered 'S'\n");
      break;
    case 'T':
      printf("You entered 'T'\n");
      break;
    case 'U':
      printf("You entered 'U'\n");
      break;
    case 'V':
      printf("You entered 'V'\n");
      break;
    default:
      printf("Had to be different\n");
      break;
  }

  return 0;
}
