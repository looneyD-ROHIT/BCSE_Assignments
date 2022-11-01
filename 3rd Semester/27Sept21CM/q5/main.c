/*
Write C data representation and functions for the operations on the String in
a Header file, with array as the base data structure, without using any inbuilt
function in C. Write a menu-driven main program in a separate file for testing
the different  operations and include the above header file. 
*/
#include "C:\Users\rohit\Desktop\Assignments\27Sept21CM\q5\headers.h"

int main(int argc, char **argv)
{
    system("cls");
    int ch, index = 0, in1, in2;
    int pos;
    STRING *new_STRINGS = (STRING *)malloc(1 * sizeof(STRING));
    do
    {
        printf("OPTIONS:\n1. Create STRING\n2. Copy s1 to s2\n3. Concatenate s1 by s2\n4. Compare two STRINGs\n5. Length of STRING\n6. Show all STRINGs\n");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exitting\n");

            free(new_STRINGS);
            printf(__dline__);
            exit(0);
        case 1:
            printf("STRING Creation:\n");
            new_STRINGS = (STRING *)realloc(new_STRINGS, (index + 1) * sizeof(STRING));
            initSTRING(new_STRINGS + index);
            index++;
            printf("STRING creation successful\n");
            printf(__dline__);
            break;
        case 2:
            printf("STRING Copy:\n");
            printf("Enter two indices = ");
            scanf(" %d%d", &in1, &in2);
            if (in1 == in2)
            {
                printf("Cannot copy a string to its same position!!!\n");
                printf(__dline__);
                break;
            }
            if (in1 >= index || in2 > index)
            {
                printf("Choose valid indices!!!\n");
                printf(__dline__);
                break;
            }
            if (in2 == index)
            {
                new_STRINGS = (STRING *)realloc(new_STRINGS, (index + 1) * sizeof(STRING));
                index++;
            }
            copySTRING((new_STRINGS + in1), (new_STRINGS + in2));
            printf(__dline__);
            break;
        case 3:
            printf("STRING Concatenate:\n");
            printf("Enter two indices = ");
            scanf(" %d%d", &in1, &in2);
            if (in1 == in2)
            {
                printf("Cannot concatenate a string to its same position!!!\n");
                printf(__dline__);
                break;
            }
            if (in1 > index || in2 >= index)
            {
                printf("Choose valid indices!!!\n");
                printf(__dline__);
                break;
            }
            if (in1 == index)
            {
                new_STRINGS = (STRING *)realloc(new_STRINGS, (index + 1) * sizeof(STRING));
                (new_STRINGS + index)->len = 0;
                index++;
            }
            concatenateSTRING((new_STRINGS + in1), (new_STRINGS + in2));
            printf(__dline__);
            break;
        case 4:
            printf("STRING Compare:\n");
            printf("Enter two indices = ");
            scanf(" %d%d", &in1, &in2);
            if (in1 >= index || in2 >= index)
            {
                printf("Choose valid indices!!!\n");
                printf(__dline__);
                break;
            }
            int flag = compareSTRING((new_STRINGS + in1), (new_STRINGS + in2));
            if (flag < 0)
                printf("The compare function returns = %d\nSo s%d is greater than s%d\n", flag, in2, in1);
            else
                printf("The compare function returns = %d\nSo s%d is greater than s%d\n", flag, in1, in2);
            printf(__dline__);
            break;
        case 5:
            printf("STRING Length:\n");
            printf("Enter the index = ");
            scanf(" %d", &in1);
            if (in1 > index)
            {
                printf("Choose valid indices!!!\n");
                printf(__dline__);
                break;
            }
            printf("The length of the string at pos %d is = [%d]\n", in1, (new_STRINGS + in1)->len);
            printf(__dline__);
            break;
        case 6:
            printf("These are all the STRINGS currently in memory:\n");
            printf(__dline__);
            for (int i = 0; i < index; i++)
            {
                printf("[%d] = ", i);
                displaySTRING(new_STRINGS + i);
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