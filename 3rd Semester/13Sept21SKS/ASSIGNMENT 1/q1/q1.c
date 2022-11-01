/*Write a program that will have an integer variable and a pointer (say, p) pointing to it. Also have 
a pointer to pointer pointing to p. Take the value for the integer variable and print it using p, 
and pp.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int n;

    int *p;
    p = &n; //p pointing to n

    int **pp;
    pp = &p; //pp points to p

    printf("Enter the value of n = "); //taking input of n

    scanf("%d", &n); //using n
    // scanf("%d", p); //using p
    // scanf("%d", *pp); //using pp

    printf("Value of n = %d\n", n);
    printf("Value of n by p = %d\n", *p);
    printf("Value of n by pp = %d\n", **pp);
}