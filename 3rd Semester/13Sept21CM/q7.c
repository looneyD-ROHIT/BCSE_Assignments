/*
Take  a  four-digit  prime  number  P.  Generate  a  series  of  large  integers
L  and  for  each  member  Li compute  the  remainder  Ri  after  dividing  Li
by  P.  Tabulate  Li  and  Ri.  Repeat  for  seven  other  four  digit prime
numbers keeping Li fixed.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define N 10
#define T 8
// #define M (1e9 + 7)

int main(int argc, char **argv)
{
    unsigned int prime[T], div[N];
    srand(time(0));
    for (int i = 0; i < N; i++) // generating random list of 10 integers
    {
        div[i] = rand(); // % (int)M;
    }
    system("cls");
    clock_t t;
    t = clock();
    for (int i = 0; i < T; i++) // taking modulo of the respective nos.
    {
        printf("Enter your prime no. = ");
        scanf(" %lu", (prime + i));
        printf("-----------------------------------\n%d.  ", i + 1);
        for (int j = 0; j < N; j++)
        {
            printf("%5lu |", div[j] % prime[i]);
        }
        printf("\n\n");
    }
    t = (clock() - t) / CLOCKS_PER_SEC;
    printf("Time required to perform the operations = %Lf\n\n", t);

    return 0;
}