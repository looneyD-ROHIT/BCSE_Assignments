/*
Write programs for linear search and binary search for searching integers,
floating point numbers and words in arrays of respective types.   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int searchInt(int *a, int n, int e, int ch) // integer nos. searching
{
    if (ch == 1) // linear search
    {
        for (int i = 0; i < n; i++)
        {
            if (*(a + i) == e)
                return i;
        }
        return -1;
    }
    else // binary search
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (a[mid] == e)
                return mid;
            else if (a[mid] > e)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
}

int searchFloat(float *a, int n, float e, int ch) // floating nos. searching
{
    if (ch == 1) // linear search
    {
        for (int i = 0; i < n; i++)
        {
            if (*(a + i) == e)
                return i;
        }
        return -1;
    }
    else // binary search
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (a[mid] == e)
                return mid;
            else if (a[mid] > e)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
}

int searchChar(char **a, int n, char *q, int ch) // char searching
{
    if (ch == 1) // linear search
    {
        for (int i = 0; i < n; i++)
        {
            if (strcmp(*(a + i), q) == 0)
                return i;
        }
        return -1;
    }
    else // binary search
    {
        int start = 0, end = n - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (strcmp(a[mid], q) == 0)
                return mid;
            else if (strcmp(a[mid], q) > 0)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
}

int main(int argc, char **argv)
{
    int n, i, t, ch, flag;
    char c;
    do
    {
        printf("1. For integers\n2. For floating nos.\n3. For strings\n");
        scanf(" %d", &t);
        switch (t)
        {
        case 1:
            printf("\n=>INTEGERS ---\n");
            int e_i;
            printf(">Enter the total no. of terms = ");
            scanf(" %d", &n);
            int *a = (int *)malloc(n * sizeof(int));
            printf("\t>Enter terms:-\n");
            for (i = 0; i < n; i++)
            {
                scanf(" %d", (a + i));
            }
            printf(">Enter search query = ");
            scanf(" %d", &e_i);
            printf(">Enter 1 for linear and 2 for binary = ");
            scanf(" %d", &ch);
            flag = searchInt(a, n, e_i, ch);
            free(a);
            break;
        case 2:
            printf("\n=>FLOATING NOS. ---\n");
            float e_f;
            printf(">Enter the total no. of terms = ");
            scanf(" %d", &n);
            float *b = (float *)malloc(n * sizeof(float));
            printf("\t>Enter terms:-\n");
            for (i = 0; i < n; i++)
            {
                scanf(" %f", (b + i));
            }
            printf(">Enter search query = ");
            scanf(" %f", &e_f);
            printf(">Enter 1 for linear and 2 for binary = ");
            scanf(" %d", &ch);
            flag = searchFloat(b, n, e_f, ch);
            free(b);
            break;
        case 3:
            printf("\n=>STRINGS ---\n");
            char q[32];
            printf(">Enter the total no. of terms = ");
            scanf(" %d", &n);
            char **arr = (char **)malloc(n * sizeof(char *));
            printf("\t>Enter terms:-\n");
            for (i = 0; i < n; i++)
            {
                *(arr + i) = (char *)malloc(1024);
                scanf(" %[^\n]s", *(arr + i));
                *(arr + i) = (char *)realloc(*(arr + i), strlen(*(arr + i)) + 1);
            }
            printf(">Enter search query = ");
            scanf(" %[^\n]s", q);
            printf(">Enter 1 for linear and 2 for binary = ");
            scanf(" %d", &ch);
            flag = searchChar(arr, n, q, ch);
            for (i = 0; i < n; i++)
            {
                free(*(arr + i));
            }
            free(arr);
            break;
        default:
            printf("Wrong Choice!!!\n");
            goto next;
        }
        if (flag != -1)
        {
            printf("\n=>Element found at ");
            printf("pos = %d\n\n", flag);
        }
        else
            printf("\n=>Element not found\n\n");
    next:
        printf("To continue press y/Y: ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return 0;
}