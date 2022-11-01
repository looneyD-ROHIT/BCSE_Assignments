/*Implement Q.5 using structure.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct myStr // actual structure
{
    int age;
    char *name;
} person;

person *memA(int n) // memory allocation and taking input of data
{
    person *s = (person *)malloc(n * sizeof(person));
    int len;
    for (int i = 0; i < n; i++)
    {
        printf("\n=> Enter age and name of person %d: ", i + 1);
        (s + i)->name = (char *)malloc(1024);
        scanf(" %d %[^\n]s", &(s + i)->age, (s + i)->name);
        len = strlen((s + i)->name);
        (s + i)->name = (char *)realloc((s + i)->name, len + 1);
    }
    return s;
}

void sortD(person **s, int n) // sorting a structure and taking care of memory management
{
    int i, j;
    person temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (((*(s) + j)->age) > ((*(s) + j + 1)->age))
            {
                temp.age = (*s + j)->age;
                temp.name = (char *)malloc(strlen((*s + j)->name) + 1);
                strcpy(temp.name, (*s + j)->name);
                free((*s + j)->name);

                (*s + j)->age = (*s + j + 1)->age;
                (*s + j)->name = (char *)malloc(strlen((*s + j + 1)->name) + 1);
                strcpy((*s + j)->name, (*s + j + 1)->name);
                free((*s + j + 1)->name);

                (*s + j + 1)->age = temp.age;
                (*s + j + 1)->name = (char *)malloc(strlen(temp.name) + 1);
                strcpy((*s + j + 1)->name, temp.name);
                free(temp.name);
            }
        }
    }
}

void displayD(person *s, int n) // displaying data
{
    for (int i = 0; i < n; i++)
    {
        printf("Age = %d\t\tName: %s\n", (s + i)->age, (s + i)->name);
    }
}

void memD(person *s, int n) // memory deallocation
{
    for (int i = 0; i < n; i++)
    {
        free((s + i)->name);
    }
    free(s);
}

int main(int argc, char **argv)
{
    int n;
    printf("Enter the number of persons = ");
    scanf(" %d", &n);

    person *s = memA(n); // allocation and input

    sortD(&s, n); // sorting

    displayD(s, n); // displaying

    memD(s, n); // memory deallocation
    return 0;
}