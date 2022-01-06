#include<stdio.h>

int main(void)
{
    int var1 = 0, var2 = 0;
    const int *ptr = &var1;
    ptr = &var1;
    *ptr = var2;
    printf("%d\n", *ptr);

    return 0;
}
