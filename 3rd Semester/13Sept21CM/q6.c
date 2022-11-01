/*
Store the names of your classmates according to roll numbers in a text file
one name per line. Write a program  to  find  out  from  the  file,  the
smallest  and  largest  names  and  their  lengths  in  number  of characters.
Write a function to sort the names alphabetically and store in a second file. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void find_largest(char *fname) // function to find length of largest and smallest names
{
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("Couldn't open file !!!\n");
        exit(0);
    }
    int c = 0, i, *arr = (int *)malloc(4);
    char **str = (char **)malloc(sizeof(char *));
    *(str + c) = (char *)malloc(100);
    while (!feof(f))
    {
        fgets(*(str + c), 100, f);
        // printf()
        *(*(str + c) + strlen(*(str + c)) - 1) = '\0';
        *(arr + c) = strlen(*(str + c));
        *(str + c) = (char *)realloc(*(str + c), *(arr + c) + 1);

        c++;
        str = (char **)realloc(str, (c + 1) * sizeof(char *));
        *(str + c) = (char *)malloc(100);
        arr = (int *)realloc(arr, (c + 1) * sizeof(int));
    }

    int max = 0, min = 0;
    for (i = 1; i < c; i++)
    {
        if (*(arr + max) < *(arr + i))
            max = i;
        if (*(arr + min) > *(arr + i))
            min = i;
    }
    printf("\n=>Largest name: %s, length = %d\n\n", *(str + max), *(arr + max));
    printf("\n=>Smallest name: %s, length = %d\n\n", *(str + min), *(arr + min));

    for (i = 0; i < c; i++)
    {
        free((void *)*(str + i));
    }
    free(arr);
    free(str);
}

void sort(char **s, int c) // bubble sorting technique to sort names
{
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - i - 1; j++)
        {
            if (strcmpi(*(s + j), *(s + j + 1)) > 0)
            {
                char *temp = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = temp;
            }
        }
    }
}

int lexicOrder(char *fname) // function to arrange names sequentially
{
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("Couldn't open file !!!\n");
        exit(0);
    }
    int c = 0, i = 0;
    char **str = (char **)malloc(sizeof(char *));
    *(str + c) = (char *)malloc(100);

    while (!feof(f)) // storing names in a 2D char array
    {
        fgets(*(str + c), 100, f);
        // *(*(str + c) + strlen(*(str + c)) - 1) = '\0';
        *(str + c) = (char *)realloc(*(str + c), strlen(*(str + c)) + 1);

        c++;
        str = (char **)realloc(str, (c + 1) * sizeof(char *));
        *(str + c) = (char *)malloc(100);
    }
    strcpy(*(str + c), "\0");

    sort(str, c);

    FILE *ordered_file = fopen("newnames.txt", "w");
    while (strcmp(*(str + i), "\0") != 0) // writing names to new file
    {
        fputs(*(str + i), ordered_file);
        fputs("\n", ordered_file);
        i++;
    }
    fclose(ordered_file);
    for (i = 0; i < c; i++)
    {
        free(*(str + i));
    }
    free(str);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) //argv[1] = "names.txt"
    {
        printf("U haven't entered file name, try again\n");
        exit(0);
    }
    clock_t t;
    t = clock();

    find_largest(argv[1]); // finding largest and smallest names

    lexicOrder(argv[1]); // arranging lexicographically and storing in newnames.txt

    t = (clock() - t) / CLOCKS_PER_SEC;
    printf("Time required to perform the operations = %Lf\n\n", t);

    return 0;
}
