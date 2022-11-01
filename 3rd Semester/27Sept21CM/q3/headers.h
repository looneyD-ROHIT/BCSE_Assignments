#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define __dline__ "----------------------------------------------------------------------------------------------\n"
#define MAX 100
int t = 0;
int head = 0;

typedef struct ListArray
{
    float val;
    int index;
} LA;

void addEntry(LA *ptr, int pos)
{
    if (ptr[head].index == -1 || pos == -1)
    {
        if (ptr[head].index == -1)
        {
            printf("List was empty\n");
            printf("Val = ");
            scanf(" %f", &(ptr[t].val));
            ptr[t].index = t + 1;
            t++;
            ptr[t].index = -1;
        }
        else
        {
            int i = head;
            while (ptr[ptr[i].index].index != -1)
            {
                i = ptr[i].index;
            }
            ptr[i].index = t;
            printf("Val = ");
            scanf(" %f", &(ptr[t].val));
            ptr[t].index = t + 1;
            t++;
            ptr[t].index = -1;
        }
    }
    else if (pos == 0)
    {
        t++;
        printf("Val = ");
        scanf(" %f", &(ptr[t].val));
        ptr[t].index = head;
        head = t;
        t++;
        ptr[t].index = -1;
    }
    else
    {
        if (ptr[t].index != 0)
            t++;
        printf("Val = ");
        scanf(" %f", &(ptr[t].val));
        // ptr[t - 1].index = -1;
        if (pos == 1)
        {
            ptr[t].index = ptr[head].index;
            ptr[head].index = t;
            t++;
            return;
        }
        int i = head, temp = 0;
        while ((pos - 2) >= 0 && ptr[i].index != -1)
        {
            // temp = ptr[temp].index;
            i = ptr[i].index;
            pos--;
        }

        ptr[t].index = ptr[i].index;
        ptr[i].index = t;
        t++;
    }
}

void delEntry(LA *ptr, int pos)
{
    if (ptr[head].index == -1)
    {
        printf("List is empty\n");
        return;
    }
    if (pos == 0)
    {
        head = ptr[0].index;
        ptr[0].index = 0;
        ptr[0].val = 0;
    }
    else if (pos == 1)
    {
        int temp = ptr[ptr[head].index].index;
        ptr[ptr[head].index].index = 0;
        ptr[ptr[head].index].val = 0;
        ptr[head].index = temp;
    }
    else if (pos == -1)
    {
        int i = head;
        while (ptr[ptr[i].index].index != -1)
        {
            i = ptr[i].index;
        }
        ptr[ptr[i].index].index = 0;
        ptr[i].index = -1;
        ptr[i].val = 0;
    }
    else
    {
        int i = head;
        pos = pos - 2;
        while (pos >= 0)
        {
            pos--;
            i = ptr[i].index;
        }
        int temp = ptr[ptr[i].index].index;
        ptr[ptr[i].index].val = 0;
        ptr[ptr[i].index].index = 0;
        ptr[i].index = temp;
    }
}

void searchList(LA *ptr, float val)
{
    int i = head, count = 0;
    while (ptr[i].val != val && ptr[i].index != -1)
    {
        i = ptr[i].index;
        count++;
    }
    if (ptr[i].index == -1)
    {
        printf("Element not found in the list!!!\n");
    }
    else
    {
        printf("Element found at index and position = %d and %d respectively\n", i, count);
    }
}

void showList(LA *ptr)
{
    // printf("head = %d\n", head);
    int i = head, pos = 0;
    printf("The entered list is as follows:\n");
    printf(__dline__);
    if (ptr[i].index != -1)
        printf("%.2f -> ", ptr[i].val);
    else
        printf("(end)");
    ;
    // printf("%.2f", ptr[i].val);
    while (ptr[i].index != -1)
    {
        i = ptr[i].index;
        pos++;

        if (ptr[i].index != -1)
            printf("%.2f -> ", ptr[i].val);
        else
            printf("(end)");
        ;
        // printf("%.2f", ptr[i].val);
    }
    printf("\n");
}