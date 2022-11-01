void deleteRecord(char *fname, int roll) // deleting records
{
    int mode, flag;
    FILE *fp = fopen(fname, "rb+");
    if (fp == NULL)
    {
        printf("File couldn't be opened :'(\n");
        return;
    }
    flag = searchRecord(fp, roll);
    if (flag == -1)
    {
        printf("\n=> Entry does not exist!!! Cannot delete :'(\n");
        return;
    }
    strecord s;
    printf("Enter mode of deletion 0 for logical and 1 for physical = ");
    scanf(" %d", &mode);
    if (mode == 0)
    {
        fseek(fp, (roll - 1) * sizeof(strecord), 0);
        fread(&s, sizeof(strecord), 1, fp);
        strcpy(s.name, "$&#@");
        fseek(fp, -1 * (int)sizeof(strecord), 1);
        fwrite(&s, sizeof(strecord), 1, fp);
        fclose(fp);
    }
    else
    {
        FILE *new = fopen("new.dat", "wb+");
        fseek(fp, 0L, 0);
        while (fread(&s, sizeof(strecord), 1, fp))
        {
            if (s.roll != roll)
                fwrite(&s, sizeof(strecord), 1, new);
        }
        // fputc(EOF, new);
        fclose(fp);
        fclose(new);
        remove(fname);
        rename("new.dat", fname);
    }
    printf("\n\t --Deleted successfully\n");
}