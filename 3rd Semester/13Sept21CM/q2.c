/*
Write a program to generate the nth Fibonacci number iteratively and recursively.
Check when there is overflow  in  the  result  and  change  the  data  types
for  accommodating  higher  values  of  inputs.  Plot  the Fibonacci number
vs n graph. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

unsigned long long int fiboN(unsigned long long int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fiboN(n - 1) + fiboN(n - 2);
}

unsigned long long int main(unsigned long long int argc, char **argv)
{
    unsigned long long int n, i, sum = 0;
    long double treq;
    printf("\n=>  Enter the position (1st term is n=0) = ");
    scanf(" %llu", &n);
    clock_t beg, end;
    FILE *f = fopen("graph.csv", "w");
    fprintf(f, "Fibo,N\n");
    fprintf(f, "%llu,%llu\n", 0, 0);
    fprintf(f, "%llu,%llu\n", 1, 1);

    // by iteration
    unsigned long long int a = 0, b = 1;
    beg = clock();
    if (n == 0)
        sum = a;
    else if (n == 1)
        sum = b;
    else
    {
        sum = a + b;
        for (i = 0; i < n - 2; i++)
        {
            a = b;
            b = sum;
            sum = a + b;
            fprintf(f, "%llu,%llu\n", i + 2, sum);
        }
        end = clock();
        treq = (long double)(end - beg) / CLOCKS_PER_SEC;
        printf("\n*>\tThe value at %lluth position = %llu\n", n, sum);
        printf("\n*>\tThe time taken by iteration = %Lf seconds\n", treq);
    }

    // by recursion
    beg = clock();
    // sum = fiboN(n);
    end = clock();
    treq = (long double)(end - beg) / CLOCKS_PER_SEC;
    printf("\n*>\tThe value at %lluth position = %llu\n", n, sum);
    printf("\n*>\tThe time taken by recursion = %Lf seconds\n", treq);
    fclose(f);
    return 0;
}

// for int type overflow occurs at n=49
// for int type overflow occurs at n=60
// for long long int type overflow occurs at n=104
// for unsigned long long int type overflow occurs at n=141