
/* Use this very simple program to observe how pointer 
   operations are compiled. */

long glob = 255;

int main()
{
     long *p;  

     p = &glob;
     
     *p = 42;

     return *p;
}


