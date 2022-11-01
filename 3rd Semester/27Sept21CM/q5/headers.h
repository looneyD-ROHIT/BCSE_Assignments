#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "----------------------------------------------------------------------------------------------\n"

#define min(a, b) (((a) < (b)) ? (a) : (b))
static int count = 0;

typedef struct myString
{
    char *str;
    int len;
} STRING;

char *data(struct myString *s)
{
    return s->str;
}

void initSTRING(STRING *s)
{
    int temp = 10, count = temp - 1, i;
    s->str = (char *)calloc(temp, sizeof(char));
    printf("Enter the sting as input: ");
    fflush(stdin);
    char ch = getchar();
    i = 0;
    while (i < temp)
    {
        if (ch != '\n')
            (s->str)[i] = (char)ch;
        else
            break;
        i++;
        if (i == temp)
        {
            temp *= 2;
            s->str = (char *)realloc(s->str, temp * sizeof(char));
        }
        ch = getchar();
    }
    (s->str)[i] = '\0';
    // i++;
    s->len = i;
    s->str = (char *)realloc(s->str, (s->len + 1) * sizeof(char));
}

void copySTRING(STRING *s1, STRING *s2)
{
    int i;
    s2->str = (char *)calloc(s1->len + 1, sizeof(char));
    for (i = 0; (s1->str)[i] != '\0'; i++)
    {
        (s2->str)[i] = (s1->str)[i];
    }
    (s2->str)[i] = '\0';
    s2->len = i;
}

void concatenateSTRING(STRING *s1, STRING *s2)
{
    if (s1->len == 0)
    {
        printf("Target string is empty\n");
        printf(__dline__);
        s1->str = (char *)calloc(1, sizeof(char));
    }

    int i, j, n = s1->len + s2->len + 1;
    s1->str = (char *)realloc(s1->str, (n * sizeof(char)));
    for (i = s1->len, j = 0; (s2->str)[j] != '\0'; i++, j++)
    {
        (s1->str)[i] = (s2->str)[j];
    }
    (s1->str)[i] = '\0';
    s1->len = i;
}

int compareSTRING(STRING *s1, STRING *s2)
{
    int i, flag = 0, n = min(s1->len, s2->len);
    for (i = 0; flag == 0 && i < n; i++)
    {
        flag += (int)((s1->str)[i]) - (int)((s2->str)[i]);
    }
    return flag;
}

void displaySTRING(STRING *s)
{
    printf("The underlying string is:\n\t=> ");
    printf("%s\n", s->str);
    printf(__dline__);
}
