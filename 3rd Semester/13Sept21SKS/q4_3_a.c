/*Implement the programs in 3 part a breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation,
iii) accepting the values and 
iv) printing the values.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getDim(int *n, int *r) // getting input of the columns and rows
{
    printf("Enter the no. of columns = ");
    scanf("%d", n);
    printf("Enter the no. of rows = ");
    scanf("%d", r);
}

int *memA(int n, int r) // allocation of memory
{
    int *p = (int *)malloc(r * n * sizeof(int));
    return p;
}

void inVal(int *temp, int n, int r) //taking input of values
{
    int i, j;
    int(*arr)[n] = (int(*)[n])temp;
    printf("Enter the values row-wise:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", (*(arr + i) + j));
    }
}

void outVal(int *temp, int n, int r) //displaying values
{
    int i, j;
    int(*arr)[n] = (int(*)[n])temp;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            printf("arr[%d][%d] = %d\t|\t", i, j, *(*(arr + i) + j));
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int n, r;

    getDim(&n, &r); //assigning cols and rows

    int *p = memA(n, r); //assigning pointer

    inVal(p, n, r); //input function

    outVal(p, n, r); //output function

    free(p); //memory freed
    return 0;
}
