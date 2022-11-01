#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct myList
{
    int val;
    struct myList *next;
} list;

void showList(list *head)
{
    while (head != NULL)
    {
        printf("%d-->", head->val);
        head = head->next;
    }
    printf("NULL");
}

void reverseList(list **head)
{
    list *temp = NULL;
    while ((*head) != NULL)
    {
        list *t = (*head);
        (*head) = (*head)->next;
        t->next = temp;
        temp = t;
    }
    (*head) = temp;
}

int main(int argc, char **argv)
{
    list *a1 = (list *)malloc(sizeof(list));
    a1->val = 1;

    list *a2 = (list *)malloc(sizeof(list));
    a2->val = 2;
    a1->next = a2;
    list *a3 = (list *)malloc(sizeof(list));
    a3->val = 3;
    a2->next = a3;

    list *a4 = (list *)malloc(sizeof(list));
    a4->val = 4;
    a3->next = a4;

    list *a5 = (list *)malloc(sizeof(list));
    a5->val = 5;
    a4->next = a5;

    a5->next = NULL;

    showList(a1);
    reverseList(&a1);
    showList(a1);
    return 0;
}