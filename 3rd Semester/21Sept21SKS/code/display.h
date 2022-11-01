int displayRecord(char *fname) // displaying records
{
    strecord temp;
    // int c = 0;
    FILE *fp = fopen(fname, "rb+");
    if (fp == NULL)
    {
        printf("File couldn't be opened :'(\n");
        exit(0);
    }
    while (fread(&temp, sizeof(strecord), 1, fp))
    {
        // c++;
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