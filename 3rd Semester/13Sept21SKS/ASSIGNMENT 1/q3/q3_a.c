/*Implement a two dimensional array of integers using [POINTER TO AN ARRAY].
Accept the value for the elements and print those.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{

    // //Implementation using pointer to an array

    int n, r, i, j;
    printf("Enter the number of elements for each array = ");
    scanf("%d", &n);

    int(*p)[n]; //pointer to an array containing n terms

    printf("Enter the number of rows = ");
    scanf("%d", &r);

    p = (int(*)[n])malloc((r * n) * sizeof(int));

    printf("Enter the elements row-wise :\n");

    for (i = 0; i < r; i++) //taking input
    {
        for (j = 0; j < n; j++)
            scanf("%d", (*(p + i) + j));
    }

    for (i = 0; i < r; i++) //displaying output
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("arr[%d][%d] = %d\t|\t", i, j, *(*(p + i) + j));
        printf("\n");
    }

    free(p); //memory freed

    return 0;
}