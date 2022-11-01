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