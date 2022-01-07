#include <stdio.h>

/* a very naive recursive factorial */
unsigned int fact(unsigned int n)
{
     if( 0 == n )
          return 1;
     if( 1 == n )
          return 1;
     return n * fact(n-1);
}

int main()
{
     printf("%d\n", fact(7));
     return 0;
}
