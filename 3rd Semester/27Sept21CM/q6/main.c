/*
Given  a large  single  dimensional  array  of integers, write  functions for
sliding  window filter with maximum, minimum, median, and average to generate
an output array. The window size should be an odd integer like 3, 5 or 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "----------------------------------------------------------------------------------------------\n"
#define MAX 12

int randArray(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}
int setArray(int *arr, int n, int e)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = e;
    }
}
int maxArray(int *arr, int n)
{
    int i, max = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > arr[max])
            max = i;
    }
    return arr[max];
}
int minArray(int *arr, int n)
{
    int i, min = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }
    return arr[min];
}
int medianArray(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr[n / 2];
}
float averageArray(int *arr, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return ((float)sum / (float)n);
}

int main(int argc, char **argv)
{
    freopen("input.txt", "r", stdin);
    system("cls");
    int arr[MAX], i, j, k, n, win;
    // randArray(arr, MAX); // --> randomly taking input of the array
    // printf("Enter the elements of the array = "); // --> user input of the array
    for (i = 0; i < MAX; i++)
    {
        scanf(" %d", arr + i);
    }
    // printf("Enter the window size = ");
    scanf(" %d", &n);                     // n is always odd as given
    printf("The array is as follows:\n"); // --> displaying the array
    for (i = 0; i < MAX; i++)
    {
        printf("%d | ", *(arr + i));
    }
    printf("\n");
    int *sec_arr = (int *)calloc(n, sizeof(int));
    int iter = (MAX - n + 1) + 2 * (n - 1) / 2;
    // main work begins here
    int end = n / 2 - 1, start = 0;
    printf("\tMAX\tMIN\tMEDIAN\tAVERAGE\n");
    for (i = 0; i < iter; i++)
    {
        if (i <= n / 2)
            end++;
        else if ((i >= (n / 2 + 1)) && (i <= (iter - n / 2 - 1)))
        {
            start++;
            end++;
        }
        else
        {
            start++;
        }
        setArray(sec_arr, n, 0);
        for (j = start, k = 0; j <= end; j++, k++)
        {
            sec_arr[k] = arr[j];
        }
        printf("\t %d\t %d\t  %d\t   %.2f\n", maxArray(sec_arr, n), minArray(sec_arr, n), medianArray(sec_arr, n), averageArray(sec_arr, n));
    }
    return 0;
}