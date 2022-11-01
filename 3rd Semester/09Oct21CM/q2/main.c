#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define ull unsigned long long int

typedef struct nodeStruct
{
    ull data;
    struct nodeStruct *next;
} NODE;

ull convert(char *str)
{
    ull sum = 0;
    for (int i = 0; str[i + 1] != '\0'; i++)
    {
        sum = sum * 10 + ((int)str[i] - 48);
    }
    return sum;
}
void build_list(NODE **head, ull e)
{
    if (*head == NULL)
    {
        (*head) = (NODE *)malloc(sizeof(NODE));
        (*head)->data = e;
        (*head)->next = NULL;
        return;
    }
    NODE *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (NODE *)malloc(sizeof(NODE));
    temp->next->data = e;
    temp->next->next = NULL;
}
void build_list_reverse(NODE **head)
{
    NODE *temp = NULL;
    while ((*head)->next != NULL)
    {
        NODE *t = (*head);
        (*head) = (*head)->next;
        t->next = temp;
        temp = t;
    }
    (*head)->next = temp;
}
void showList(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    while (head != NULL)
    {
        printf("%llu-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Couldn't open file!!!\n");
        exit(0);
    }
    char str[100];
    NODE *head1 = NULL;
    while (fgets(str, 100, fp) != NULL)
    {
        ull temp = convert(str);
        build_list(&head1, temp);
    }
    printf("------------------------------------------------------------------\n");
    printf("List 1:\n");
    showList(head1);
    printf("------------------------------------------------------------------\n");

    fseek(fp, 0L, SEEK_SET);
    NODE *head2 = NULL;
    while (fgets(str, 100, fp) != NULL)
    {
        ull temp = convert(str);
        build_list(&head2, temp);
    }
    printf("List 2:\n");
    showList(head2);
    printf("------------------------------------------------------------------\n");
    build_list_reverse(&head2);
    printf("List 2 reverse:\n");
    showList(head2);
    printf("------------------------------------------------------------------\n");

    return 0;
}