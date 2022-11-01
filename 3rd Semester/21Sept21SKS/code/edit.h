void editRecord(FILE *fp, int roll) // modifying records
{
    fseek(fp, (roll - 1) * sizeof(strecord), SEEK_SET);
    strecord data;
    printf("\n=>Enter new details:\n");
    makeRecord(&data);
    fwrite(&data, sizeof(strecord), 1, fp);
}