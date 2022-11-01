/*
Write C data structure representation and functions for the operations on the
List in a Header file with array as the base data structure. Write a menu-driven
main program in a separate file for testing the different operations and include
the above header file. Two data structures with and without using sentinels in
arrays are to be implemented.
*/
#include "C:\Users\rohit\Desktop\Assignments\27Sept21CM\q3\headers.h"

int main(int argc, char **argv)
{
    system("cls");
    int ch, pos;
    float val;
    LA *new_list;
    // P **list = (P **)malloc(1 * sizeof(P *));
    // int list_index = 0;
    do
    {
        printf("OPTIONS:\n1. Create list\n2. Insert element to list\n3. Delete element from list\n4. Display list\n5. Search for a val\n");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exitting\n");
            free(new_list);
            printf(__dline__);
            exit(0);
        case 1:
            new_list = (LA *)calloc(MAX, sizeof(LA));
            new_list[0].index = -1;
            printf("List initiated successfully\n");
            printf(__dline__);
            break;
        case 2:
            printf("Enter pos at which val to be inserted = ");
            scanf(" %d", &pos);
            addEntry(new_list, pos);
            printf("Inserted successfully\n");
            printf(__dline__);
            break;
        case 3:
            printf("Enter pos at which val to be deleted = ");
            scanf(" %d", &pos);
            delEntry(new_list, pos);
            printf("Deleted successfully\n");
            printf(__dline__);
            break;
        case 4:
            showList(new_list);
            printf(__dline__);
            break;
        case 5:
            printf("Enter the value to be searched = ");
            scanf(" %f", &val);
            searchList(new_list, val);
            printf(__dline__);
            break;
        default:
            printf("You have entered a wrong choice!!!\n");
            printf(__dline__);
        }
    } while (1);

    return 0;
}

// tested using input 1->2->3->4->5 => 1->4->2->3->5