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
     int i;
     for( i = 0; i < 10; i++ ){ 
          printf("%d\n", fact(i));
     }

     return 0;
}
