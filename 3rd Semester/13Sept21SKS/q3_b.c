/*Implement a two dimensional array of integers using [ARRAY OF POINTERS].
Accept the value for the elements and print those.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{

    // Implementation using array of pointers

    int n, r = 1, i, j;

    printf("Enter the number of columns and rows = ");
    scanf("%d%d", &n, &r);

    int *(p[r]); // array containing r pointers

    for (i = 0; i < r; i++)
    {
        *(p + i) = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements row-wise :\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", (*(p + i) + j));
    }

    for (i = 0; i < r; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("arr[%d][%d] = %d\t|\t", i, j, *(*(p + i) + j));
        printf("\n");
    }

    for (i = 0; i < r; i++) // memory freeing
    {
        free(*(p + i));
    }

    return 0;
}