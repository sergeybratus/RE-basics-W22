#include <stdio.h>

/* a very naive recursive Fibonacci number implementation */
unsigned int fib(unsigned int n)
{
     if( 0 == n )
          return 1;
     if( 1 == n )
          return 1;
     return fib(n-1) + fib(n-2);
}

int main()
{
     int i;
     for( i = 0; i < 10; i++ ){ 
          printf("%d\n", fib(i));  /* note implicit conversion from int to unsigned int */
     }

     return 0;
}
