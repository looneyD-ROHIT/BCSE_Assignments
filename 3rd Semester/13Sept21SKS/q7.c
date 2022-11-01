/*Maintain a list to store roll, name and score of students. As and when required student record 
may be added or deleted. Also, the list has to be displayed. Design suitable functions for different 
operations. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct myStr
{
    int roll;
    char name[32];
    float score;
    struct myStr *next;
} student;

student *mkNode() //function to make a node
{
    student *s = (student *)malloc(1 * sizeof(student));
    printf("Enter roll = ");
    scanf(" %d", &((s)->roll));
    printf("Enter name = ");
    scanf(" %[^\n]s", (s)->name);
    printf("Enter score = ");
    scanf(" %f", &((s)->score));
    return s;
}

void addEnt(student **head) // add entries sequentially
{
    student *s;
    student *temp = (*head);
    if ((*head) == NULL)
    {
        printf("\n>List was empty\n");
        s = mkNode();
        (*head) = s;
        s->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        s = mkNode();
        temp->next = s;
        s->next = NULL;
    }
}

void addNext(student **head, int pos) // add entries to any position
{
    if (pos < -1)
    {
        printf("\n>Positional index not valid for use!!!\n\t----Returned to main\n");
        return;
    }

    student *s;
    student *temp = (*head);

    if ((*head) == NULL)
    {
        printf("\n>List was empty\n");
        if (pos != 0)
        {
            printf("\n>Indicated position could not be located!!!\n");
            return;
        }
        s = mkNode();
        (*head) = s;
        s->next = NULL;
    }

    else if (pos == 0)
    {
        s = mkNode();
        s->next = (*head);
        (*head) = s;
    }
    else if (pos == -1)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        s = mkNode();
        temp->next = s;
        s->next = NULL;
    }
    else
    {
        student *x = (*head);
        while ((pos != 0) && (temp->next != NULL))
        {
            x = temp;
            temp = temp->next;
            pos--;
        }
        if (pos)
        {
            printf("\n>Indicated position yet to be reached!!!\n");
            return;
        }
        s = mkNode();
        x->next = s;
        s->next = temp;
    }
}

void delEntry(student **head, int pos) // delete from any position
{
    if (pos < -1)
    {
        printf("\n>Positional index not valid for use!!!\n\t----Returned to main\n");
        return;
    }
    student *temp;
    temp = (*head);
    if ((*head) == NULL)
    {
        printf("\n>No items in list to delete!!!\n");
        return;
    }
    else if (pos == 0)
    {
        if ((*head)->next == NULL)
        {
            free((*head));
            (*head) = NULL;
        }
        else
        {
            (*head) = (*head)->next;
            free(temp);
        }
    }
    else if (pos == -1)
    {
        while ((temp->next)->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    else
    {
        student *x = (*head);
        while ((pos != 0) && (temp->next != NULL))
        {
            x = temp;
            temp = temp->next;
            pos--;
        }
        if (pos)
        {
            printf("\n>Indicated position doesn't exist!!!\n");
            return;
        }
        else
        {
            x->next = temp->next;
            free(temp);
        }
    }
    printf("\t----Deleted Entry\n");
}

void displayL(student *head) // display list
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("Roll = %d\t", head->roll);
        printf("Name = %s\t", head->name);
        printf("Score = %3.2f\n", head->score);
        head = head->next;
    }
}

void displayRev(student *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        displayRev(head->next);
        printf("Roll = %d\n", head->roll);
        printf("Name = %s\n", head->name);
        printf("Score = %f\n", head->score);
        printf("--------------------------------------------\n");
    }
}

int main(int argc, char **argv)
{
    int n, pos;
    char c = 'N';
    printf("1. Add entry\n2. Add in between\n3. Delete entry\n4. Display List\n");
    student *head = NULL;
    do
    {
        printf("Enter choice no: ");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
            printf("\n=>Adding entries\n");
            addEnt(&head);
            break;
        case 2:
            printf("\n=>Adding entries in between\n");
            printf("Enter position = ");
            scanf(" %d", &pos);
            addNext(&head, pos);
            break;
        case 3:
            printf("\n=>Deletion of entries\n");
            printf("\nEnter position = ");
            scanf(" %d", &pos);
            delEntry(&head, pos);
            break;
        case 4:
            printf("\n=>List is as follows:\n");
            // displayL(head);
            displayRev(head);
            break;

        default:
            printf("\n=>The entry doesn't exist!!!\n");
            break;
        }
        printf("\n=>To continue press y/Y: ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return 0;
}