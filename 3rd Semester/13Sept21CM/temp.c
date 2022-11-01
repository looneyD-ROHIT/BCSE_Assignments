/*Write a program which allows you to do addition and subtraction of two integers which can be
upto 40 decimal digits long (call it as huge integers). Create your own representation of huge
integers and it should use as minimum space as possible.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char num1[40];
    char num2[40];
} num;

void add_large(char *a, char *b);
void sub_large(char *a, char *b);

void main()
{
    num n;
    printf("Enter first number = ");
    scanf(" %s", n.num1);
    printf("Enter second number = ");
    scanf(" %s", n.num2);
    printf("\n\nADDITION of\n\n");
    add_large(n.num1, n.num2);
    printf("\n\n");
    printf("\n\nSUBTRACTION of\n\n");
    sub_large(n.num1, n.num2);
    printf("\n\n");
}

void add_large(char *a, char *b)
{
    char temp[41];
    int i, j, sum = 0, l1 = strlen(a), l2 = strlen(b);
    int n1[40] = {0}, n2[40] = {0}, s[41] = {0};
    for (i = 0; i < l1; i++)
        *(n1 + 39 - i) = (int)*(a + l1 - 1 - i) - 48;

    for (i = 0; i < l2; i++)
        *(n2 + 39 - i) = (int)*(b + l2 - 1 - i) - 48;

    for (i = 0; i < l1; i++)
        printf("%d  ", *(n1 + 39 - l1 + 1 + i));
    printf("\n");

    printf("AND\n");

    for (i = 0; i < l2; i++)
        printf("%d  ", *(n2 + 39 - l2 + 1 + i));
    printf("\n\n");

    if (l1 >= l2)
    {
        for (i = 0; i < l1; i++)
        {
            sum = 0;
            sum = *(n1 + 39 - i) + *(n2 + 39 - i);
            *(s + 40 - i) = *(s + 40 - i) + sum % 10;
            sum = sum / 10;
            *(s + 40 - i - 1) += sum % 10;
        }
    }
    else
    {
        for (i = 0; i < l2; i++)
        {
            sum = 0;
            sum = *(n1 + 39 - i) + *(n2 + 39 - i);
            *(s + 40 - i) += sum % 10;
            sum = sum / 10;
            *(s + 40 - i - 1) += sum % 10;
        }
    }
    if (l1 >= l2)
        for (i = 40 - l1; i < 41; i++)
            printf("%d  ", *(s + i));

    else
        for (i = 40 - l2; i < 41; i++)
            printf("%d  ", *(s + i));
}

void sub_large(char *a, char *b)
{
    char temp[41];
    int i, j, sum = 0, l1 = strlen(a), l2 = strlen(b);
    int n1[41] = {0}, n2[41] = {0}, s[42] = {0};
    for (i = 0; i < l1; i++)
        *(n1 + 40 - i) = (int)*(a + l1 - 1 - i) - 48;

    for (i = 0; i < l2; i++)
        *(n2 + 40 - i) = ((int)*(b + l2 - 1 - i) - 48);

    for (i = 0; i < l1; i++)
        printf("%d  ", *(n1 + 40 - l1 + 1 + i));
    printf("\n");

    printf("AND\n");

    for (i = 0; i < l2; i++)
        printf("%d  ", *(n2 + 40 - l2 + 1 + i));
    printf("\n\n");

    if (l1 >= l2)
    {
        for (i = 0; i < l1; i++)
            *(n2 + 40 - i) = 9 - *(n2 + 40 - i);

        /*Evaluating 10's complement*/
        sum = 0;
        sum = *(n2 + 40) + 1;
        *(n2 + 40) = sum % 10;
        for (i = 0; i < l1; i++)
        {
            sum = sum / 10;
            sum = sum + *(n2 + 40 - i - 1);
            *(n2 - 40 - i - 1) = sum % 10;
        }

        // for(i=40-l1 ; i<41; i++)
        // printf("%d  ",*(n2+i));
        // printf("\n\n");
    }

    else
    {
        for (i = 0; i < l2; i++)
            *(n2 + 40 - i) = 9 - *(n2 + 40 - i);
        /*Evaluating 10's complement*/
        sum = 0;
        sum = *(n2 + 40) + 1;
        *(n2 + 40) = sum % 10;
        for (i = 0; i < l2; i++)
        {
            sum = sum / 10;
            sum = sum + *(n2 + 40 - i - 1);
            *(n2 - 40 - i - 1) = sum % 10;
        }

        // for(i=40-l2 ; i<41; i++)
        // printf("%d  ",*(n2+i));
        // printf("\n\n");
    }

    if (l1 >= l2)
    {
        for (i = 0; i < l1 + 1; i++)
        {
            sum = 0;
            sum = *(n1 + 40 - i) + *(n2 + 40 - i);
            *(s + 40 - i) = *(s + 40 - i) + sum % 10;
            sum = sum / 10;
            *(s + 40 - i - 1) += sum % 10;
        }
    }
    else
    {
        for (i = 0; i < l2 + 1; i++)
        {
            sum = 0;
            sum = *(n1 + 40 - i) + *(n2 + 40 - i);
            *(s + 40 - i) += sum % 10;
            sum = sum / 10;
            *(s + 40 - i - 1) += sum % 10;
        }
    }
    // if(l1>=l2)
    // for(i=40-l1 ; i<41; i++)
    // printf("%d  ",*(s+i));

    // else
    // for(i=40-l2 ; i<41; i++)
    // printf("%d  ",*(s+i));

    if (l2 >= l1)
        l1 = l2;

    if (*(s + 40 - l1) != 0)
    {
        for (i = 40 - l1 + 1; i < 41; i++)
            printf("%d  ", *(s + i));
    }
    else
    {
        for (i = 40 - l1 + 1; i < 41; i++)
            *(s + i) = 9 - *(s + i);
        sum = 0;
        sum = *(s + 40) + 1;
        *(s + 40) = sum % 10;
        for (i = 0; i < l1; i++)
        {
            sum = sum / 10;
            sum = sum + *(s + 40 - i - 1);
            *(s + 40 - i - 1) = sum % 10;
        }
        printf("\n - ");
        for (i = 40 - l1 + 1; i < 41; i++)
            printf("%d  ", *(s + i));
    }
}