/*
Convert your Name and Surname into large integers by juxtaposing integer ASCII
codes for alphabet. Print the corresponding converted integer. Cut the large
integers into two halves and add the two halves. Compute the remainder after
dividing the by the prime numbers P in problem 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct name
{
    char *name;
    int *arr;
} myStr;

void putDetails(char **name)
{
    (*name) = (char *)malloc(10240);
    printf("Enter name: ");
    scanf(" %[^\n]s", *name);
}
void remSpaces(char **name)
{
    int i;
    for (i = 0; *(*name + i) != '\0'; i++)
    {
        if (*(*name + i) == ' ')
        {
            int j = i;
            while (*(*name + j) != '\0')
            {
                *(*name + j) = *(*name + j + 1);
                j++;
            }
            i--;
        }
    }
}

void juxt(myStr *x)
{
    remSpaces(&(x->name));
    int len = strlen(x->name);
    x->arr = (int *)calloc(2 * len, sizeof(int));
    for (int i = 0, j = 0; *(x->name + i) != '\0' && j < 2 * len; i++, j += 2)
    {
        int c = (int)*(x->name + i);
        *(x->arr + j + 1) = (c) % 10;
        *(x->arr + j) = (c) / 10;
    }
}

int *sumJux(myStr *x)
{
    int t_len = 2 * strlen(x->name);
    int l1 = t_len / 2;
    int i, j;
    int *n_arr = (int *)calloc(l1 + 1, sizeof(int));
    int *m_arr = (int *)calloc(l1 + 1, sizeof(int));
    memset(n_arr, 0, l1 + 1);
    memset(m_arr, 0, l1 + 1);

    for (i = 0; i < l1; i++)
    {
        *(n_arr + i + 1) = *(x->arr + i);
        *(m_arr + i + 1) = *(x->arr + i + l1);
    }

    int sum = 0;
    for (i = l1; i > 0; i--)
    {
        sum += (*(m_arr + i) + *(n_arr + i));
        *(m_arr + i) = sum % 10;
        sum /= 10;
    }
    *(m_arr + i) = sum;
    free(n_arr);
    return m_arr;
}

void modN(int *arr, int l)
{
    unsigned long long int sum = 0;
    int i, prime[8];
    srand(time(0));
    for (i = 0; i < l; i++)
    {
        sum = sum * 10 + *(arr + i);
    }
    // printf("\nSUM = %llu\n", sum);
    clock_t t;
    t = clock();
    for (int i = 0; i < 8; i++) // taking modulo of the respective nos.
    {
        printf("Enter your prime no. = ");
        scanf(" %lu", (prime + i));
        printf("mod val = %4llu\n", sum % prime[i]);
    }
    printf("\n");
    t = (clock() - t) / CLOCKS_PER_SEC;
    printf("Time required to perform the operations = %Lf\n\n", t);
}

int main(int argc, char **argv)
{
    int i, l, *num;
    myStr x;
    putDetails(&x.name);

    printf("=> Name: %s\n", x.name);

    juxt(&x);

    num = sumJux(&x);
    l = strlen(x.name);
    printf("\nSUM = ");
    for (i = 0; i < l + 1; i++)
    {
        printf("%d", *(num + i));
    }
    printf("\n\n");

    modN(num, l + 1);

    return 0;
}