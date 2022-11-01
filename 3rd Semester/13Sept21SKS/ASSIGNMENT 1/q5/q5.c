/*Store name and age of number of persons (number provided at run time). Collect the data and display 
data in the ascending order of age. Implement without using structure. Write functions for memory 
allocation of the list, sorting and display of data.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void memA(int **age, char ***name, int n) //memory allocation
{

    *age = (int *)malloc(n * sizeof(int));

    *name = (char **)malloc(n * sizeof(char *));
    int len;

    //taking input of data
    for (int i = 0; i < n; i++)
    {

        printf("Enter age[%d] = ", i + 1);
        scanf(" %d", (*age + i));

        *(*name + i) = (char *)malloc(1024);
        printf("Enter name[%d]: ", i + 1);
        scanf(" %[^\n]s", *(*name + i));
        len = strlen(*(*name + i));
        *(*name + i) = (char *)realloc(*(*name + i), len);
        printf("\n");
    }
}

void sortD(int **age, char ***name, int n) //bubble sorting process
{
    int i, j, temp;
    char *t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (*(*age + j) > *(*age + j + 1))
            {
                temp = *(*age + j);
                *(*age + j) = *(*age + j + 1);
                *(*age + j + 1) = temp;

                t = *(*name + j);
                *(*name + j) = *(*name + j + 1);
                *(*name + j + 1) = t;
            }
        }
    }
}

void displayD(int *age, char **name, int n) //displaying terms
{
    for (int i = 0; i < n; i++)
    {
        printf("Person %d, Name: %s\tand Age = %d\n", (i + 1), *(name + i), *(age + i));
    }
}

void memD(int *age, char **name, int n) //memory deallocation
{
    for (int i = 0; i < n; i++)
    {
        free(*(name + i));
    }
    free(age);
    free(name);
}

int main(int argc, char **argv)
{
    int n;
    printf("Enter the number of persons = "); //taking input
    scanf("%d", &n);

    int *age;
    char **name;
    memA(&age, &name, n); //memory allocation function call

    sortD(&age, &name, n); //sorting function call

    displayD(age, name, n); //displaying function call

    memD(age, name, n); //memory deallocation function call
    return 0;
}