#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "---------------------------------------------------\n"

typedef struct SparseMatrix
{
    int r;
    int c;
    float **arr;
} SM;

void createSM(SM *mx)
{
    int i, j;
    printf("Enter the no. of rows = ");
    scanf(" %d", &(mx->r));
    printf("Enter the no. of cols = ");
    scanf(" %d", &(mx->c));
    printf(__dline__);
    mx->arr = (float **)malloc((mx->r) * sizeof(float *));
    for (int i = 0; i < mx->r; i++)
    {
        *(mx->arr + i) = (float *)calloc((mx->c), sizeof(float));
    }
    bool flag = true;
    while (flag)
    {
        printf("coordinates = ");
        scanf(" %d%d", &i, &j);
        if (i < mx->r && j < mx->c)
        {
            printf("val at coordinate = ");
            scanf(" %f", &((mx->arr)[i][j]));
        }
        else
            flag = false;
    }
}

void addSM(SM *mx, int m_index)
{
    int index1, index2;
    printf("Enter the indices of the matrices to be added = ");
    scanf(" %d%d", &index1, &index2);
    if ((mx + index1)->r == (mx + index2)->r && (mx + index1)->c == (mx + index2)->c)
    {
        (mx + m_index)->r = (mx + index1)->r;
        (mx + m_index)->c = (mx + index1)->c;
        (mx + m_index)->arr = (float **)malloc(((mx + m_index)->r) * sizeof(float *));
        for (int i = 0; i < (mx + m_index)->r; i++)
        {
            *((mx + m_index)->arr + i) = (float *)calloc(((mx + m_index)->c), sizeof(float));
        }
        for (int i = 0; i < (mx + m_index)->r; i++)
        {
            for (int j = 0; j < (mx + m_index)->c; j++)
                ((mx + m_index)->arr)[i][j] = ((mx + index1)->arr)[i][j] + ((mx + index2)->arr)[i][j];
        }
        printf("Added successfully\n");
    }
    else
    {
        printf("No match in dimensions :'( \n");
    }
}

void mulSM(SM *mx, int m_index)
{
    int index1, index2;
    printf("Enter the indices of the matrices to be multiplied = ");
    scanf(" %d%d", &index1, &index2);
    if ((mx + index1)->c == (mx + index2)->r)
    {
        int n = (mx + index1)->c;
        (mx + m_index)->r = (mx + index1)->r;
        (mx + m_index)->c = (mx + index2)->c;
        (mx + m_index)->arr = (float **)malloc(((mx + m_index)->r) * sizeof(float *));
        for (int i = 0; i < (mx + m_index)->r; i++)
        {
            *((mx + m_index)->arr + i) = (float *)calloc(((mx + m_index)->c), sizeof(float));
        }
        for (int i = 0; i < (mx + m_index)->r; i++)
        {
            for (int j = 0; j < (mx + m_index)->c; j++)
                for (int k = 0; k < n; k++)
                    ((mx + m_index)->arr)[i][j] += ((mx + index1)->arr)[i][k] * ((mx + index2)->arr)[k][j];
        }
        printf("Multiplied successfully\n");
    }
    else
    {
        printf("No match in dimensions :'( \n");
    }
}

void showSM(SM *mx)
{
    printf("The no. of rows of the matrix = %d\n", mx->r);
    printf("The no. of cols of the matrix = %d\n", mx->c);
    for (int i = 0; i < mx->r; i++)
    {
        for (int j = 0; j < mx->c; j++)
        {
            printf("%.2f\t", (mx->arr)[i][j]);
        }
        printf("\n");
    }
}