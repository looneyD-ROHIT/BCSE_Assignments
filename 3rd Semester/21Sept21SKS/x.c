#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int r, c;
    printf("ENTER NUMBER OF ROWS: ");
    scanf(" %d", &r);
    printf("ENTER NUMBER OF COLUMNS: ");
    scanf(" %d", &c);
    int(*arr)[c];                                //CREATING A POINTER TO THE ARRAY
    arr = (int(*)[])malloc(r * c * sizeof(int)); //ALLOCATING MEMORY TO A POINTER TO THE ARRAY
    printf("ENTER THE ELEMENTS OF THE ARRAY ROW WISE : \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            scanf(" %d", (*(arr + i) + j));
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    free(arr); //TO FREE THE SPACE ALLOCATED PREVIOUSLY
    return 0;
}