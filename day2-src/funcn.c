#include <stdio.h>

void myfunc();

int main()
{
     int i = 10;
     
     while( i >= 0 ){
          myfunc( "world" );
          i--;
     }

     return 0;
}

void myfunc(char *str)
{
     printf( "hello %s\n", str );
}
