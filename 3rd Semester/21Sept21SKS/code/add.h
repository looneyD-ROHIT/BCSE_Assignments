int addRecord(char *fname) // adding records
{
    int flag, pos;
    strecord s;
    FILE *fp = fopen(fname, "rb+");
    if (fp == NULL)
    {
        printf("File couldn't be opened :'(\n");
        exit(0);
    }
    printf("\n=>Enter student details: \n");

    flag = searchRecord(fp, s.roll);
    if (flag == -1)
    {
        makeRecord(&s);
        strecord temp;
        temp.roll = -1;
        fseek(fp, 0L, 2);
        int total = ftell(fp) / sizeof(strecord);
        if (total < s.roll)
        {
            for (int i = 0; i < s.roll - total - 1; i++)
            {
                fwrite(&temp, sizeof(strecord), 1, fp);
            }
            fwrite(&s, sizeof(strecord), 1, fp);
        }
        else
        {
            fseek(fp, (s.roll - 1) * sizeof(strecord), 0);
            fwrite(&s, sizeof(strecord), 1, fp);
        }
        fclose(fp);
        return 1;
    }
    else
    {

        printf("Record against roll already exists!!!\n");
        fseek(fp, flag * sizeof(strecord), SEEK_SET);
        fread(&s, sizeof(strecord), 1, fp);
        if (s.roll == flag + 1)
        {
            editRecord(fp, flag + 1);
        }
        fclose(fp);
        return 0;
    }
}