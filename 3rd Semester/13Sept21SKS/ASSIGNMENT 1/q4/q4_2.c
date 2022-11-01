/*Implement the programs in Q.2 breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation,
iii) accepting the values and 
iv) printing the values.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getDim(int *p) // getting input of the dimensions
{
    printf("Enter the no. of elements = ");
    scanf("%d", p);
    return *p;
}

int *getPtr(int *arr, int n) // allocation of memory
{
    arr = (int *)malloc(n * sizeof(int));
    return arr;
}

void inVal(int *arr, int n) //taking input of values
{
    int i;
    printf("Enter the values:\n");
    for (i = 0; i < n; i++)
        scanf("%d", (arr + i));
}

void outVal(int *arr, int n) // displaying values
{
    int i;
    printf("Values:\n");
    for (i = 0; i < n; i++)
        printf("arr[%d] = %d  |  ", i, *(arr + i));
    printf("\n");
}

int main(int argc, char **argv)
{
    int n, i;
    n = getDim(&n);
    int *arr;
    arr = getPtr(arr, n);
    inVal(arr, n);
    outVal(arr, n);
    free(arr);
    return 0;
}