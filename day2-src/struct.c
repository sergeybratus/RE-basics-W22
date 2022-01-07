#include <stdio.h>

/* Use this simple program to see how struct member accesses 
   are compiled. */

struct item {
     int  num;
     char *name;
};

struct item it[3] = { {1, "foo"}, {2, "bar"}, {3, "baz"} };

int main()
{
     int k;

     struct item *p;

     for(k = 1; k < 4; k++)
          printf("item %d: %s\n", it[k-1].num, it[k-1].name);

     /* comment this out first */
     //p = &it[0]; /* recall that [] has higher precedence than & (address-of); 
     //               cf. http://en.cppreference.com/w/c/language/operator_precedence */
     //for(k = 1; k < 4; k++){
     //     printf("item %d again: %s\n", p->num, p->name);
     //     p++;
     //}
     

     return 42;
}

     
