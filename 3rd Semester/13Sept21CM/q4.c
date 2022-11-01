/*
Write a program to generate 1,00,000 random integers between 1 and 1,00,000
without repetitions and store  them  in  a  file  in  character  mode  one
number  per  line.  Study  and  use  the  functions  in  C  related  to random 
numbers.     
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please enter a valid file name!!!\n");
        exit(0);
    }
    int d = (int)1e5, i, r, temp;
    int arr[(int)1e5 + 1];
    for (i = 1; i < d + 1; i++)
        arr[i] = i;
    FILE *f = fopen(argv[1], "w");
    srand(time(NULL));
    for (i = 1; i < d + 1; i++)
    {
        r = (rand() % d) + 1;
        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }

    for (i = 1; i < d + 1; i++)
        fprintf(f, "%d\n", arr[i]);

    fclose(f);
    return 0;
}