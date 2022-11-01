/*
Find whether an array is sorted or not, and the sorting order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "--------------------------------------------------------------------\n"
#define dim 10
#define mod 10

int main(int argc, char **argv)
{
    system("cls");
    int array[dim]; // = {1, 2, 3, 4, 4, 4, 5, 5, 6, 6, 6, 6, 7, 8, 9, 10};
    int i;
    bool a, d;
    // random array
    srand(time(NULL));
    for (i = 0; i < dim; i++)
    {
        array[i] = rand() % mod;
    }
    if (dim <= 2)
    {
        printf("Array is sorted\n");
        exit(0);
    }
    a = (array[1] >= array[0]);
    d = (array[1] <= array[0]);

    for (i = 2; i < dim; i++)
    {
        if (array[i] >= array[i - 1] && a)
        {
            a = true;
            d = false;
        }
        else if (array[i] <= array[i - 1] && d)
        {
            d = true;
            a = false;
        }
        else
        {
            a = false;
            d = false;
        }
    }
    if (a || d)
    {
        printf("Sorted!!!\n");
    }
    else
    {
        printf("Not sorted!!!\n");
    }
    printf(__dline__);
    return 0;
}