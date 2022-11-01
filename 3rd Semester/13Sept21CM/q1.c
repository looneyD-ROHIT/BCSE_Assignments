/*
Write a program to compute the factorial of an integer n iteratively and
recursively. Check when there is overflow in the result and change the data
types for accommodating higher values of inputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

long long int factorial(long long int n)
{
    if (n == 1 || n == 0)
        return 1;

    return n * factorial(n - 1);
}

long long int main(long long int argc, char **argv)
{
    long long int n, i, fact;
    clock_t beg, end;
    long double treq;
    printf("Enter n = ");
    scanf("%lld", &n);

    //by iteration
    fact = 1;
    beg = clock();
    for (i = 1; i <= n; i++)
        fact = fact * i;
    end = clock();
    treq = (long double)(end - beg) / CLOCKS_PER_SEC;
    printf("factorial = %lld\n", fact);
    printf("The time taken by iteration = %Lf seconds\n", treq);

    printf("\n\n");

    // by recursion
    beg = clock();
    fact = factorial(n);
    end = clock();
    treq = (long double)(end - beg) / CLOCKS_PER_SEC;
    printf("factorial = %lld\n", fact);
    printf("The time taken by recursion = %Lf seconds\n", treq);
    return 0;
}

// for int type overflow occurs at n = 17
// for unsigned int type overflow occurs at n = 34
// for long long int overflow occurs at n = 40
// for unsigned long long int overflow occurs at n = 66