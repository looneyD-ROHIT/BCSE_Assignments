#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "----------------------------------------------------------------------------------------------\n"
#define MAX 100
#define min(a, b) (((a) < (b)) ? (a) : (b))
// static int count = 0;

typedef struct mySet
{
    int *arr;
    int n_elements;
} SET;

void initSET(SET *ptr)
{
    ptr->arr = NULL;
    ptr->n_elements = 0;
}

bool isPresent(int val, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (val == arr[i])
            return true;
    }
    return false;
}

void addElements(SET *ptr)
{

    int temp = 100, i = 0, j = 0;
    char *str = (char *)calloc(temp, sizeof(char));
    int val;
    // printf("Enter the no. of elements u want to enter = ");
    // scanf(" %d", &temp);
    printf(__dline__);
    ptr->arr = (int *)calloc(temp, sizeof(int));
    while (j < temp)
    {
        printf("Enter the elements of the set = ");
        scanf(" %s", str);
        if (str[0] == 'x')
            break;
        val = atoi(str);
        if (!isPresent(val, ptr->arr, i))
        {
            (ptr->arr)[i] = val;
            printf("element added\n");
            i++;
        }
        else
            printf("element not added\n");
        j++;
        if (j == temp)
        {
            printf("U have now entered %d elements, to exit at any moment type x, else continue\n", temp);
            // scanf(" %c", &choice);
            printf(__dline__);
            temp *= 2;
            ptr->arr = (int *)realloc(ptr->arr, temp * sizeof(int));
            char *str = (char *)realloc(str, temp * sizeof(char));
        }
    }
    ptr->arr = (int *)realloc(ptr->arr, i * sizeof(int));
    ptr->n_elements = i;
    free(str);
}

bool unionSET(SET *ptr, int index)
{
    int in1, in2, i, j;
    printf("Enter the indices of the SETS to be added = ");
    scanf(" %d%d", &in1, &in2);
    if (in1 >= index || in2 >= index)
    {
        printf("Indicated position doesn't exist\n");
        printf("UNION computation unsuccessful\n");
        return false;
    }
    initSET(ptr + index);
    ((ptr + index)->arr) = (int *)calloc((ptr + in1)->n_elements + (ptr + in2)->n_elements, sizeof(int));
    for (i = 0; i < (ptr + in1)->n_elements; i++)
    {
        ((ptr + index)->arr)[i] = ((ptr + in1)->arr)[i];
    }
    for (j = i, i = 0; i < (ptr + in2)->n_elements; i++)
    {
        if (!isPresent(((ptr + in2)->arr)[i], (ptr + index)->arr, j))
        {
            ((ptr + index)->arr)[j] = ((ptr + in2)->arr)[i];
            j++;
        }
    }
    (ptr + index)->n_elements = j;
    (ptr + index)->arr = (int *)realloc((ptr + index)->arr, (ptr + index)->n_elements * sizeof(int));
    printf("UNION computed successfully\n");
    return true;
}

bool intersectionSET(SET *ptr, int index)
{
    int in1, in2, i, j;
    printf("Enter the indices of the SETS to be added = ");
    scanf(" %d%d", &in1, &in2);
    if (in1 >= index || in2 >= index)
    {
        printf("Indicated position doesn't exist\n");
        printf("INTERSECTION computation unsuccessful\n");
        return false;
    }
    initSET(ptr + index);
    ((ptr + index)->arr) = (int *)calloc((ptr + in1)->n_elements + (ptr + in2)->n_elements, sizeof(int));
    for (i = 0, j = 0; i < (ptr + in1)->n_elements; i++)
    {
        if (isPresent(((ptr + in1)->arr)[i], (ptr + in2)->arr, (ptr + in2)->n_elements))
        {
            ((ptr + index)->arr)[j] = ((ptr + in1)->arr)[i];
            j++;
        }
    }
    (ptr + index)->n_elements = j;
    (ptr + index)->arr = (int *)realloc((ptr + index)->arr, (ptr + index)->n_elements * sizeof(int));
    printf("INTERSECTION computed successfully\n");
    return true;
}

bool subtractionSET(SET *ptr, int index)
{
    int in1, in2, i, j;
    printf("Enter the indices of the SETS to be added = ");
    scanf(" %d%d", &in1, &in2);
    if (in1 >= index || in2 >= index)
    {
        printf("Indicated position doesn't exist\n");
        printf("SUBTRACTION computation unsuccessful\n");
        return false;
    }
    initSET(ptr + index);
    ((ptr + index)->arr) = (int *)calloc((ptr + in1)->n_elements + (ptr + in2)->n_elements, sizeof(int));
    for (i = 0, j = 0; i < (ptr + in1)->n_elements; i++)
    {
        if (!isPresent(((ptr + in1)->arr)[i], (ptr + in2)->arr, (ptr + in2)->n_elements))
        {
            ((ptr + index)->arr)[j] = ((ptr + in1)->arr)[i];
            j++;
        }
    }
    (ptr + index)->n_elements = j;
    (ptr + index)->arr = (int *)realloc((ptr + index)->arr, (ptr + index)->n_elements * sizeof(int));
    printf("SUBTRACTION computed successfully\n");
    return true;
}
void displaySET(SET *ptr)
{
    if (ptr == NULL)
    {
        printf("SET is empty!!!\n");
        printf(__dline__);
        return;
    }
    if (ptr->n_elements == 0)
    {
        printf("The SET is as follows:\n\t{ NIL }\n");
        return;
    }
    int i = ptr->n_elements, r = ptr->n_elements, temp;
    int *SET_index = (int *)calloc(i, sizeof(int));
    printf("The SET is as follows:\n\t{ ");
    srand(time(NULL));
    while (i)
    {
        temp = rand() % r;
        if (SET_index[temp] == 0)
        {
            SET_index[temp] = 1;
            printf("%d, ", ptr->arr[temp]);
            i--;
        }
    }
    printf("\b\b }\n");
}
