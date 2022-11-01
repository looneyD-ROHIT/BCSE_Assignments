#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct student_records // original structure
{
    int roll;
    char name[32];
    float marks[5];
} strecord;

void makeRecord(strecord *);
int addRecord(char *);
int searchRecord(FILE *, int);
int displayRecord(char *);

void makeRecord(strecord *s) // making record
{
    printf("Enter roll no. of student = ");
    scanf(" %d", &s->roll);
    printf("Enter name no. of student = ");
    scanf(" %[^\n]s", s->name);
    printf("Enter marks of 5 subjects: ");
    for (int i = 0; i < 5; i++)
        scanf(" %f", s->marks + i);
}

int addRecord(char *fname) // adding records
{
    int flag, pos;
    strecord s;
    FILE *fp = fopen(fname, "rb+");
    if (fp == NULL)
    {
        printf("File couldn't be opened :'(\n");
        exit(0);
    }
    printf("\n=>Enter student details: \n");

    flag = searchRecord(fp, s.roll);
    if (flag == -1)
    {
        makeRecord(&s);
        strecord temp;
        temp.roll = -1;
        fseek(fp, 0L, 2);
        int total = ftell(fp) / sizeof(strecord);
        if (total < s.roll)
        {
            for (int i = 0; i < s.roll - total - 1; i++)
            {
                fwrite(&temp, sizeof(strecord), 1, fp);
            }
            fwrite(&s, sizeof(strecord), 1, fp);
        }
        else
        {
            fseek(fp, (s.roll - 1) * sizeof(strecord), 0);
            fwrite(&s, sizeof(strecord), 1, fp);
        }
        fclose(fp);
        return 1;
    }
    else
    {

        printf("Record against roll already exists!!!\n");
        fseek(fp, flag * sizeof(strecord), SEEK_SET);
        fread(&s, sizeof(strecord), 1, fp);
        if (s.roll == flag + 1)
        {
            editRecord(fp, flag + 1);
        }
        fclose(fp);
        return 0;
    }
}

int searchRecord(FILE *fp, int r) // searching records
{
    int c = 0;
    strecord data;
    FILE *x = fp;
    while (fread(&data, sizeof(strecord), 1, x))
    {
        if (r == data.roll)
        {
            if (strcmp(data.name, "$&#@") == 0)
            {
                printf("Memory location is logically deleted!!!\n");
            }
            return c;
        }
        c++;
    }
    return -1;
}

int displayRecord(char *fname) // displaying records
{
    strecord temp;
    int c = 0;
    FILE *fp = fopen(fname, "rb+");
    if (fp == NULL)
    {
        printf("File couldn't be opened :'(\n");
        exit(0);
    }
    while (fread(&temp, sizeof(strecord), 1, fp))
    {
        c++;
        printf("=>Roll no. of student = %d\n", temp.roll);
        printf("=>Name of student: %s\n", temp.name);
        printf("=>Marks:\n");
        for (int i = 0; i < 5; i++)
        {
            printf("\tsub %d = %f\n", i, (temp.marks)[i]);
        }
        printf("\n");
    }
    fclose(fp);
}

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
        printf("\nOPTIONS:\n1. Add record\n2. Search record\n3. Display record\n");
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