#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int rev(int n) // function to  reverse a no.
{
    int temp = 0;
    while (n)
    {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp;
}

char *ctoitos(char c) // function to convert char to int and then to char
{
    int t = rev((int)c);
    char *s = (char *)malloc(32);
    int i = 0;
    do
    {
        *(s + i) = (char)(t % 10 + 48);
        t /= 10;
        i++;
    } while (t != 0);
    *(s + i) = (char)0;
    s = (char *)realloc(s, (int)(strlen(s) + 1));
    return s;
}

void strcon(char *a, char *b)
{
    int i = 0, j;
    while (*(a + i) != '\0')
        i++;
    for (j = 0; *(b + j) != '\0'; j++, i++)
    {
        *(a + i) = *(b + j);
    }
    *(a + i) = '\0';
}

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

void juxt(char **name)
{
    remSpaces(name);
    char *temp = (char *)malloc((int)(2 * strlen(*name) + 1));
    *temp = '\0';
    for (int i = 0; *((*name) + i) != '\0'; i++)
    {
        strcon(temp, ctoitos(*((*name) + i)));
    }
    (*name) = (char *)realloc((*name), (int)(strlen(temp) + 1));
    strcpy((*name), temp);
    free(temp);
}

int *sumJux(char *name)
{
    int t_len = strlen(name);
    int l2 = t_len / 2;
    int l1 = t_len - l2;
    int i, j;

    int *a = (int *)malloc((l1 + 2) * sizeof(int)), b[l2];
    a[0] = 0;
    a[l1 + 1] = -1;
    for (i = 0; i < l1; i++)
        a[i + 1] = (int)(*(name + i)) - 48;
    for (i = l1; i < t_len; i++)
        b[i - l1] = (int)(*(name + i)) - 48;

    int sum = 0;
    for (i = l2 - 1, j = l1; i >= 0; i--, j--)
    {
        sum += a[j] + b[i];
        a[j] = sum % 10;
        sum /= 10;
    }
    if (l1 > l2)
    {
        sum = sum + a[j - 1];
        a[j - 1] = (a[j - 1] + sum) % 10;
        a[j - 2] += sum / 10;
    }
    else
    {
        a[j - 1] += sum;
    }
    return a;
}

int main(int argc, char **argv)
{
    char *name;
    putDetails(&name);
    printf("=> Name: %s\n", name);

    juxt(&name);
    printf("=> Juxtaposed = %s\n", name);

    int *arr = sumJux(name);

    unsigned long long int term = 0, p;

    for (int i = 0; arr[i] != -1; i++)
        term = term * 10 + arr[i];

    printf("\n\t=>Term = %lld\n", term);

    printf("\n=> Enter your prime no. = ");
    scanf(" %lld", &p);

    printf("\n\t=> Modulo result = %lld\n", (term % p));

    free(name);
    free(arr);

    return 0;
}