/*Write a program to store student information in a file and t do the following
operations. Information includes roll, name, and score in five subjects. Use may
like to add record (ensure roll number is unique), display all records showing roll,
name and total score. User may search for the record against a roll. User may edit
the details a record. User may delete record. Deletion may be logical (by some means
indicate it is an invalid record and to be avoided in processing) and physical
(file will not have the record).*/

#include "main.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("U have not entered the filename!!!\n");
        exit(0);
    }
    system("cls");
    int ch, val, flag;
    char *fname = argv[1];
    FILE *fp = fopen(fname, "wb");
    fclose(fp);
    do
    {
        printf("\nOPTIONS:\n1. Add record\n2. Search record\n3. Modify record\n4. Delete record\n5. Display record\n");
        printf("Enter choice = ");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("\n=> Addition of records\n");
            addRecord(fname);
            break;
        case 2:
            printf("\n=> Search\n\n");
            printf("Enter roll no. = ");
            scanf(" %d", &val);
            fp = fopen(fname, "rb+");
            if (fp == NULL)
            {
                printf("File couldn't be opened :'(\n");
                break;
            }
            flag = searchRecord(fp, val);
            if (flag != -1)
            {
                printf("\n=>Record found, at pos = %d\n", flag);
            }
            else
            {
                printf("\n=>Record not found\n");
            }
            fclose(fp);
            break;
        case 3:
            printf("\n=> Modify\n\n");
            printf("Enter roll no. = ");
            scanf(" %d", &val);
            fp = fopen(fname, "rb+");
            if (fp == NULL)
            {
                printf("File couldn't be opened :'(\n");
                break;
            }
            flag = searchRecord(fp, val);
            if (flag != -1)
            {
                editRecord(fp, val);
            }
            else
            {
                printf("\n=>Record not found\n");
            }
            fclose(fp);
            break;
        case 4:
            printf("\n=> Deletion of records\n\n");
            printf("Enter roll no. to delete = ");
            scanf(" %d", &val);
            deleteRecord(fname, val);
            break;
        case 5:
            printf("\n=> Displaying of records\n\n");
            displayRecord(fname);
            break;
        default:
            printf("\n=>Wrong OPTION!!! Try again :)\n");
            break;
        }
    } while (1);
    return 0;
}