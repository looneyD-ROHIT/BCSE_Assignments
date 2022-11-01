#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
    int *a, n, i, max_index = 0;
    printf("Enter no of elements = ");
    scanf(" %d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf(" %d", (a + i));

    for (i = 0; i < n; i++)
    {
        if (*(a + max_index) < *(a + i))
            max_index = i;
    }
    printf("\n=>The index of the max element is = %d\n", max_index);
    free(a);
    return 0;
}