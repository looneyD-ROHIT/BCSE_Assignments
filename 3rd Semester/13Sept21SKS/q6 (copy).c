#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct myStr //actual structure
{
    int age;
    char *name;
} student;

student *memA(int n) // memory allocation and taking input of data
{
    student *s = (student *)malloc(n * sizeof(student));
    int len;
    for (int i = 0; i < n; i++)
    {
        printf("Enter age and name of student %d: ", i + 1);
        (s + i)->name = (char *)malloc(1024);
        scanf(" %d%s", &(s + i)->age, (s + i)->name);
        len = strlen((s + i)->name);
        (s + i)->name = (char *)realloc((s + i)->name, len);
    }
    return s;
}

void sortD(student **s, int n) //sorting a structure and taking care of memory management
{
    int i, j;
    student temp;
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

void displayD(student *s, int n) // displaying data
{
    for (int i = 0; i < n; i++)
    {
        printf("Age = %d\tName: %s\n", (s + i)->age, (s + i)->name);
    }
}

void memD(student *s, int n) // memory deallocation
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
    printf("Enter the number of students = ");
    scanf(" %d", &n);

    student *s = memA(n); // allocation and input

    sortD(&s, n); // sorting

    displayD(s, n); // displaying

    memD(s, n); // memory deallocation
    return 0;
}