#include <stdio.h>

void myfunc();

int main()
{
     int i = 10;
     
     while( i >= 0 ){
          myfunc();
          i--;
     }

     return 0;
}

void myfunc()
{
     puts( "hello" );
}
