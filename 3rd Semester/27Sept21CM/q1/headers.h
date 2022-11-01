#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "---------------------------------------------------\n"

typedef struct polynomial
{
    float coefficient;
    int exponent;
    struct polynomial *next;
} P;

void createPolynomial(P **head)
{
    *head = (P *)malloc(sizeof(P));
    P *temp = *head;
    int exp = 0;
    float coeff = 0;
    printf("Enter the values as coefficients and exponents for the polynomial:\n");
    printf(__dline__);
    printf("C = ");
    scanf("%f", &coeff);
    printf("E = ");
    scanf("%d", &exp);
    temp->coefficient = coeff;
    temp->exponent = exp;
    while (exp != 0)
    {
        temp->next = (P *)malloc(sizeof(P));
        temp = temp->next;
        temp->next = NULL;
        printf("C = ");
        scanf("%f", &coeff);
        printf("E = ");
        scanf("%d", &exp);
        temp->coefficient = coeff;
        temp->exponent = exp;
    }
}

void removeRedundants(P *head)
{
    P *temp1 = head, *temp2 = head->next;
    while (temp1->next != NULL)
    {
        if (temp2->coefficient == 0)
        {
            temp1->next = temp2->next;
            free(temp2);
            temp2 = temp1->next;
            continue;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

void sortExponents(P *head)
{
    int len;
    P *temp1, *temp2;
    for (len = 0, temp1 = head; temp1 != NULL; len++)
        ;
    for (int i = 1; i < len; i++)
    {
        temp1 = head;
        temp2 = head->next;
        for (int j = 0; j < len - i && temp2 != NULL; j++)
        {
            if (temp2->exponent > temp1->exponent)
            {
                int t = temp2->exponent;
                float tt = temp2->coefficient;
                temp2->exponent = temp1->exponent;
                temp2->coefficient = temp1->coefficient;
                temp1->exponent = t;
                temp1->coefficient = tt;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
}

double showValue(P *head)
{
    float x;
    printf("Enter the value of x = ");
    scanf("%f", &x);
    double val = 0.0;
    while (head->exponent != 0)
    {
        val += head->coefficient * pow(x, head->exponent);
        head = head->next;
    }
    val = val + head->coefficient;
    return val;
}

void addPolynomial(P **list, int list_index)
{
    int input, input2;
    printf("Enter the indices of the polynomial u want to add: ");
    scanf(" %d%d", &input, &input2);
    P *head1 = (*(list + input));
    P *head2 = (*(list + input2));
    P *head3 = (P *)malloc(sizeof(P));
    *(list + list_index) = head3;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->exponent == head2->exponent)
        {
            head3->coefficient = head1->coefficient + head2->coefficient;
            head3->exponent = head1->exponent;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exponent > head2->exponent)
        {
            head3->coefficient = head1->coefficient;
            head3->exponent = head1->exponent;
            head1 = head1->next;
        }
        else
        {
            head3->coefficient = head2->coefficient;
            head3->exponent = head2->exponent;
            head2 = head2->next;
        }
        head3->next = (P *)malloc(sizeof(P));
        head3 = head3->next;
        head3->coefficient = 0;
        head3->exponent = 0;
        head3->next = NULL;
    }
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            head3->coefficient = head1->coefficient;
            head3->exponent = head1->exponent;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            head3->coefficient = head2->coefficient;
            head3->exponent = head2->exponent;
            head2 = head2->next;
        }
        head3->next = (P *)malloc(sizeof(P));
        head3 = head3->next;
        head3->coefficient = 0;
        head3->exponent = 0;
        head3->next = NULL;
    }
}

void multiplyPolynomial(P **list, int list_index)
{
    int input, input2;
    printf("Enter the indices of the polynomial u want to add: ");
    scanf(" %d%d", &input, &input2);
    P *head1 = (*(list + input));
    P *head3 = (P *)malloc(sizeof(P));
    *(list + list_index) = head3;

    // multiplication process
    while (head1 != NULL)
    {
        P *head2 = (*(list + input2));
        while (head2 != NULL)
        {
            head3->coefficient = head1->coefficient * head2->coefficient;
            head3->exponent = head1->exponent + head2->exponent;
            head2 = head2->next;
            head3->next = (P *)malloc(sizeof(P));
            head3 = head3->next;
            head3->coefficient = 0;
            head3->exponent = 0;
            head3->next = NULL;
        }
        head1 = head1->next;
    }

    // addition of similar generated terms
    head3 = (*(list + list_index));
    while (head3 != NULL)
    {
        P *temp1 = head3, *temp2 = head3->next;
        while (temp2 != NULL)
        {
            if (temp2->exponent == head3->exponent)
            {
                head3->coefficient = head3->coefficient + temp2->coefficient;
                temp1->next = temp2->next;
                free(temp2);
                temp2 = temp1->next;
                continue;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        head3 = head3->next;
    }
}

void showPolynomial(P *head)
{
    while (head != NULL)
    {
        if (head->coefficient >= 0)
            printf(" +%.2f(x)^%d", head->coefficient, head->exponent);
        else if (head->coefficient < 0)
            printf(" -%.2f(x)^%d", abs(head->coefficient), head->exponent);
        head = head->next;
    }
    printf("\n");
}
