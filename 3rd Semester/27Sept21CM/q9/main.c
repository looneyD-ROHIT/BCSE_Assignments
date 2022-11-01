/*
Given two sorted arrays, write a function to merge the array in the sorting order.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "--------------------------------------------------------------------\n"
#define dim1 5
#define dim2 6

int sortOrder(int *arr, int dim)
{
    int i;
    bool a, d;
    a = (arr[1] >= arr[0]);
    d = (arr[1] <= arr[0]);

    for (i = 2; i < dim; i++)
    {
        if (arr[i] >= arr[i - 1] && a)
        {
            a = true;
            d = false;
        }
        else if (arr[i] <= arr[i - 1] && d)
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
    if (a == true && d == false)
    {
        return 1;
    }
    else if (a == false && d == true)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int *mergeSorted(int *a, int d1, int *b, int d2)
{
    system("cls");
    int i = 0, j = 0, k = 0;
    int *finalArray = (int *)calloc((d1 + d2), sizeof(int));
    int f1 = sortOrder(a, d1), f2 = sortOrder(b, d2);
    if ((f1 == 1 && f2 == -1) || (f1 == -1 && f2 == 1))
    {
        printf("Order of arrays do not match!!!\n");
        return finalArray;
    }
    if (f1 == 1 || (f1 == 0 && f2 != -1))
        while (i < d1 && j < d2)
        {
            if (a[i] <= b[j])
            {
                *(finalArray + k++) = a[i++];
            }
            else
            {
                *(finalArray + k++) = b[j++];
            }
        }
    else
        while (i < d1 && j < d2)
        {
            if (a[i] >= b[j])
            {
                *(finalArray + k++) = a[i++];
            }
            else
            {
                *(finalArray + k++) = b[j++];
            }
        }
    while (i < d1)
        *(finalArray + k++) = a[i++];
    while (j < d2)
        *(finalArray + k++) = b[j++];
    return finalArray;
}
int main(int argc, char **argv)
{
    int a[dim1] = {1, 4, 9, 13, 20}, b[dim2] = {0, 3, 7, 12, 19, 20};
    int *finalArray = mergeSorted(a, dim1, b, dim2);
    printf("Final array:\n");
    for (int i = 0; i < (dim1 + dim2); i++)
    {
        printf("%d | ", *(finalArray + i));
    }
    printf("\n");
    printf(__dline__);
    free(finalArray);
    return 0;
}