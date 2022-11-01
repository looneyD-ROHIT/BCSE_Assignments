#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct nodetag
{
    int info;
    struct nodetag *next;
} nodetype;

nodetype *head, *cur, *prev, *target;

nodetype *createnode(int item)
{
    nodetype *head = NULL;
    if ((head = (nodetype *)malloc(sizeof(nodetype))) == NULL)
        perror(“malloc eror”);
    else
    {
        head->info = item;
        head->next = NULL;
    }
    return head;
}

nodetype *init_l() { return NULL; }

bool empty_l(nodetype *head) { return (head == NULL); }

bool atend_l(nodetype *cur)
{
    return (cur->next == NULL);
}

void insert_front(nodetype *target, nodetype **phead)
{
    target->next = *phead;
    *phead = target;
}

void insert_after(nodetype *target, nodetype *prev)
{
    nodetype *cur;
    cur = prev->next;
    target->next = cur;
    prev->next = target;
}

void delete_front(nodetype **phead)
{
    nodetype *cur;
    cur = *phead;
    *phead = (*phead)->next;
    free(cur);
}

void delete_after(nodetype *prev)
{
    nodetype *cur;
    if (!(atend_l(prev)))
    {
        cur = prev->next;
        prev->next = cur->next;
        free(cur);
    }
}

void showList(nodetype *head)
{
    if (empty_l(head))
    {
        printf("List is empty\n");
        return;
    }
    printf("The list is as follows:-\n");
    while (head != NULL)
    {
        printf("%d-->", head->info);
        head = head->next;
    }
    printf("NULL\n");
}