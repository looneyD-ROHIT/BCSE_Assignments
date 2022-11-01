/*Implement the programs in 3 part b breaking it into functions for 
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

void memA(int **p, int r, int n) // allocation of memory
{
    for (int i = 0; i < r; i++)
    {
        *(p + i) = (int *)malloc(n * sizeof(int));
    }
}

void inVal(int **temp, int n, int r) //taking input of values
{
    int i, j;
    printf("Enter the values row-wise:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", (*(temp + i) + j));
    }
}

void outVal(int **temp, int n, int r) //displaying values
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            printf("arr[%d][%d] = %d\t|\t", i, j, *(*(temp + i) + j));
        printf("\n");
    }
}

void memD(int **x, int r) // deallocation of memory
{
    for (int i = 0; i < r; i++)
    {
        free(*(x + i));
    }
}

int main(int argc, char **argv)
{
    int n, r;

    getDim(&n, &r); //assigning cols and rows

    int *p[r];
    memA(p, r, n); //assigning pointer function call

    inVal(p, n, r); //input function call

    outVal(p, n, r); //output function call

    memD(p, r); //deallocation of memory

    return 0;
}
