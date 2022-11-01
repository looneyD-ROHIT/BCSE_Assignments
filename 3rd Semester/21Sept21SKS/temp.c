#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int func(int (**p)[5])
{
    printf("val in func = %p\n", *p);
    printf("val in func = %p\n", **p);
}

int main(int argc, char **argv)
{
    int(*p)[5];
    printf("val in main = %p\n", p);
    printf("val in main = %p\n", *p);
    func(&p);
    return 0;
}