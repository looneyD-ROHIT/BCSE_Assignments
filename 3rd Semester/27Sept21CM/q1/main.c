/*
Write C data structure representation and functions for the operations on
the Polynomials in a Header file. Write a menu-driven main program in a separate
file for testing the different operations and include the above header file.
*/
#include "C:\Users\rohit\Desktop\Assignments\27Sept21CM\q1\headers.h"

int main(int argc, char **argv)
{
    system("cls");
    int ch, input, input2;
    P **list = (P **)malloc(1 * sizeof(P *));
    int list_index = 0;
    do
    {
        printf("OPTIONS:\n1. Create a Polynomial\n2. Show value at a given x\n3. Add two polynomials\n4. Multiply two polynomials\n5. Display the polynomial\n");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exitting\n");
            for (int i = 0; i < list_index; i++)
            {
                free(*(list + i));
            }
            free(list);
            printf(__dline__);
            exit(0);
        case 1:
            list = (P **)realloc(list, (list_index + 1) * sizeof(P *));
            createPolynomial(list + list_index);
            list_index++;
            printf(__dline__);
            break;
        case 2:
            printf("Enter polynomial index value = ");
            scanf(" %d", &input);
            double v = showValue(*(list + input));
            printf("The value of the polynomial at specified x is = %.2Lf\n", v);
            printf(__dline__);
            break;
        case 3:
            printf("Addition of polynomials:\n");
            list = (P **)realloc(list, (list_index + 1) * sizeof(P *));
            addPolynomial(list, list_index);
            list_index++;
            printf(__dline__);
            break;
        case 4:
            printf("Multiplication of polynomials:\n");
            list = (P **)realloc(list, (list_index + 1) * sizeof(P *));
            multiplyPolynomial(list, list_index);
            list_index++;
            printf(__dline__);
            break;
        case 5:
            printf("Enter the index value = ");
            scanf(" %d", &input);
            printf("The entered polynomial is as follows: ");
            removeRedundants(*(list + input));
            // sortExponents(*(list + input));
            showPolynomial(*(list + input));
            printf(__dline__);
            break;
        default:
            printf("You have entered a wrong choice!!!\n");
            printf(__dline__);
        }
    } while (1);
    return 0;
}