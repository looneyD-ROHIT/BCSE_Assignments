/*
Write C data representation and functions for the operations on the Set in a
Header file, with array as the base data structure. Write a menu-driven main
program in a separate file for testing the different operations and include
the above header file.  
*/
#include "headers.h"

int main(int argc, char **argv)
{
    system("cls");
    int ch, index = 0, in1, in2;
    int pos;
    SET *new_SETS = (SET *)malloc(1 * sizeof(SET));
    do
    {
        printf("OPTIONS:\n1. Create SET\n2. Union/Addition of two sets\n3. Intersection of two sets\n4. Subtraction of two sets\n5. Show all SETs\n");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exitting\n");
            for (int i = 0; i < index; i++)
            {
                free((new_SETS + i)->arr);
            }
            free(new_SETS);
            printf(__dline__);
            exit(0);
        case 1:
            printf("SET creation:\n");
            new_SETS = (SET *)realloc(new_SETS, (index + 1) * sizeof(SET));
            initSET(new_SETS + index);
            addElements(new_SETS + index);
            index++;
            printf("SET creation successful\n");
            printf(__dline__);
            break;
        case 2:
            printf("SET UNION:\n");
            new_SETS = (SET *)realloc(new_SETS, (index + 1) * sizeof(SET));
            if (unionSET(new_SETS, index))
                index++;
            printf(__dline__);
            break;
        case 3:
            printf("SET INTERSECTION:\n");
            new_SETS = (SET *)realloc(new_SETS, (index + 1) * sizeof(SET));
            if (intersectionSET(new_SETS, index))
                index++;
            printf(__dline__);
            break;
        case 4:
            printf("SET SUBTRACTION:\n");
            new_SETS = (SET *)realloc(new_SETS, (index + 1) * sizeof(SET));
            if (subtractionSET(new_SETS, index))
                index++;
            printf(__dline__);
            break;
        case 5:
            printf("These are all the SETS currently in memory:\n");
            printf(__dline__);
            for (int i = 0; i < index; i++)
            {
                printf("[%d] = ", i);
                displaySET(new_SETS + i);
                printf(__dline__);
            }
            // printf(__dline__);
            break;
        default:
            printf("You have entered a wrong choice!!!\n");
            printf(__dline__);
        }
    } while (1);

    return 0;
}