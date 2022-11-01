/*
Write C data structure representation and functions for the operations on the
Sparse Matrix in a Header file. Write a menu-driven main program in a separate
file for testing the different operations and include the above header file. 
*/
#include "C:\Users\rohit\Desktop\Assignments\27Sept21CM\q2\headers.h"

int main(int argc, char **argv)
{
    system("cls");
    int ch, input;
    SM *mxs = (SM *)malloc(sizeof(SM));
    int m_indices = 0;
    do
    {
        printf("OPTIONS:\n1. Create a SM\n2. Add two SM\n3. Multiply two SM\n4. Display the SM\n");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exitting\n");
            free(mxs);
            printf(__dline__);
            exit(0);
        case 1:
            mxs = (SM *)realloc(mxs, (m_indices + 1) * sizeof(SM));
            createSM(mxs + m_indices);
            m_indices++;
            printf(__dline__);
            break;
        case 2:
            printf("Addition of SM:\n");
            mxs = (SM *)realloc(mxs, (m_indices + 1) * sizeof(SM));
            addSM(mxs, m_indices);
            m_indices++;
            printf(__dline__);
            break;
        case 3:
            printf("Multiplication of SM:\n");
            mxs = (SM *)realloc(mxs, (m_indices + 1) * sizeof(SM));
            mulSM(mxs, m_indices);
            m_indices++;
            printf(__dline__);
            break;
        case 4:
            printf("Enter the index value = ");
            scanf(" %d", &input);
            printf("The entered SMis as follows: ");
            showSM(mxs + input);
            printf(__dline__);
            break;
        default:
            printf("You have entered a wrong choice!!!\n");
            printf(__dline__);
        }
    } while (1);
    return 0;
}