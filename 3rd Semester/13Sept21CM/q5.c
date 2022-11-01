/*
Write  a  program  to  generate  1,00,000  random  strings  of  capital  letters
of  length  10  each,  without repetitions and store them in a file in character
mode one string per line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define N 1e5

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please enter a valid file name!!!\n");
        exit(0);
    }
    char *string = (char *)malloc(11);
    const int d = 26;
    int i, j, r;

    FILE *f = fopen(argv[1], "w");
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 10; j++)
        {
            r = (rand() % d) + 65;
            *(string + j) = (char)r;
        }
        *(string + j) = '\0';

        fprintf(f, "%s\n", string);
    }
    fclose(f);
    free(string);
    return 0;
}