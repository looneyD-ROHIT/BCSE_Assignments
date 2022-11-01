#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
    int a[100];
    srand(time(NULL));
    int i = 100;
    while (i--)
    {
        a[i] = rand();
    }
    for (i = 0; i < 100; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}