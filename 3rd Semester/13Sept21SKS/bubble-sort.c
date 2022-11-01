#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void bub_sort(int *p, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}

void display(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d | ", i, *(p + i));
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int arr[] = {4, 3, 6, 1, 0, 5};
    bub_sort(arr, 6);
    display(arr, 6);
    return 0;
}