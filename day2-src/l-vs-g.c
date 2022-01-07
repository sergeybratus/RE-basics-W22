#include <stdio.h>

int x = 1;
int y = 200;

void g();

int main()
{
     int x  = 100;
     printf( "x=%d y=%d\n", x, y);

     g();
     return 0;
}

void g()
{
     printf( "x=%d\n", x);
     printf( "x=%d\n", x);
}
