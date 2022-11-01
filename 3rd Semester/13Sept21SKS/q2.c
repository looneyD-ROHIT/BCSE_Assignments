/*Implement a one dimensional array of integers where array size of the array will be provided during 
runtime. Accept the value for the elements and print those using pointers.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int n, i, *arr;
    printf("Enter the size of the array = ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int)); //dynamic memory allcation for array

    printf("Enter the elements of the array = ");
    for (i = 0; i < n; i++) //taking input from the user
        scanf("%d", (arr + i));

    for (i = 0; i < n; i++) //printing the elements of the array
        printf("arr[%d] = %d\n", i, *(arr + i));

    free(arr);
    return 0;
}