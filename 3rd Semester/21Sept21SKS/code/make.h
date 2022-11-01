void makeRecord(strecord *s) // making record
{
    printf("Enter roll no. of student = ");
    scanf(" %d", &s->roll);
    printf("Enter name no. of student = ");
    scanf(" %[^\n]s", s->name);
    printf("Enter marks of 5 subjects: ");
    for (int i = 0; i < 5; i++)
        scanf(" %f", s->marks + i);
}