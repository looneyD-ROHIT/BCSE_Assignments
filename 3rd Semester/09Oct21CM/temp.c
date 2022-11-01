#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

char *takeInput()
{
    char *str = (char *)malloc(1 * sizeof(char));
    char c;
    int i = 0;
    while (true)
    {
        c = getchar();
        // printf("c = %c\n", c);
        if (c != '\n' && c != ' ')
        {
            str = (char *)realloc(str, (i + 1) * sizeof(char));
            *(str + i) = c;
            i++;
        }
        else
            break;
    }
    str = (char *)realloc(str, (i + 1) * sizeof(char));
    *(str + i) = '\0';
    // printf("The entered number is = %s\n", str);
    return str;
}

int length(char *s)
{
    int i = 0;
    for (; s[i] != '\0'; i++)
        ;
    return i;
}

void addLeadingZeroes(char **s, int len, int t)
{
    char *str = (char *)malloc((len + t + 1) * sizeof(char));
    str[len + t] = '\0';
    for (int i = 0; i < t; i++)
    {
        str[i] = '0';
    }
    for (int i = t; i < len + t; i++)
    {
        str[i] = (*s)[i - t];
    }
    free(*s);
    *s = str;
}
char *removeLeadingZeroes(char *s, int len)
{
    int i = 0, j = 0;
    if ((*s) == '0')
    {
        i++;
        char *temp = (char *)malloc((len) * sizeof(char));
        for (j = 0; i < len; i++, j++)
        {
            temp[j] = (s)[i];
            // printf("temp= %c -- ", temp[j]);
        }
        temp[j] = '\0';
        return temp;
    }
    return s;
}
char *findSum(char *str1, int len1, char *str2, int len2)
{
    int maxLen = max(len1, len2);
    if (len1 != len2)
    {
        if (maxLen == len1)
        {
            addLeadingZeroes(&str2, len2, len1 - len2);
            // printf("newstrings = %s\n", str2);
        }
        else
        {
            addLeadingZeroes(&str1, len1, len2 - len1);
            // printf("newstrings = %s\n", str1);
        }
    }
    char *final = (char *)calloc((maxLen + 2), sizeof(char));
    *(final + maxLen + 1) = '\0';
    int temp = 0;
    for (int i = 0; i < maxLen; i++)
    {
        temp += ((int)(str1[maxLen - 1 - i]) - 48) + ((int)(str2[maxLen - 1 - i]) - 48);
        final[maxLen - i] = (char)((temp % 10) + 48);
        temp /= 10;
    }
    *final = (char)(temp + 48);
    final = removeLeadingZeroes(final, length(final));
    return final;
}

char *multiplyNum(char *a, int len1, char *b, int len2)
{
    if (len2 > len1)
    {
        char *temp = a;
        a = b;
        b = temp;
        int t = len1;
        len1 = len2;
        len2 = t;
    }
    if (len1 == 1)
    {
        int x = atoi(a) * atoi(b);
        char *tt = (char *)malloc(2 * sizeof(char));
        itoa(x, tt, 10);
        return tt;
    }
    int half1 = len1 / 2;
    int half2 = len2 / 2;
    char *a_left = (char *)malloc((len1 - half1) * sizeof(char));
    char *a_right = (char *)malloc((half1) * sizeof(char));
    char *b_left = (char *)malloc((len2 - half2) * sizeof(char));
    char *b_right = (char *)malloc((half2) * sizeof(char));
    for (int i = 0; i < len1 - half1; i++)
        a_left[i] = a[i];
    for (int i = len1 - half1; i < len1; i++)
        a_right[i] = a[i];
    for (int i = 0; i < len2 - half2; i++)
        b_left[i] = b[i];
    for (int i = len2 - half2; i < len2; i++)
        b_right[i] = b[i];
    char *p = multiplyNum(a_left, length(a_left), b_left, length(b_left));
    char *temp_var1 = multiplyNum(a_left, length(a_left), b_right, length(b_right));
    int var_1 = length(temp_var1), k;
    temp_var1 = (char *)realloc(temp_var1, (var_1 + 1 + half1) * sizeof(char));
    for (k = var_1; k < var_1 + half1; k++)
    {
        temp_var1[k] = '0';
    }
    temp_var1[k] = '\0';
    char *temp_var2 = multiplyNum(a_right, length(a_right), b_left, length(b_left));
    int var_2 = length(temp_var2);
    temp_var2 = (char *)realloc(temp_var2, (var_2 + 1 + half2) * sizeof(char));
    for (k = var_2; k < var_2 + half2; k++)
    {
        temp_var2[k] = '0';
    }
    temp_var2[k] = '\0';
    char *intr = findSum(temp_var1, length(temp_var1), temp_var2, length(temp_var2));
    char *q = multiplyNum(a_right, length(a_right), b_right, length(b_right));

    int var_p = length(p);
    p = (char *)realloc(p, (var_p + 1 + half1 + half2) * sizeof(char));
    for (k = var_p; k < var_p + half1 + half2; k++)
    {
        p[k] = '0';
    }
    p[k] = '\0';

    char *final_pdt = findSum(p, length(p), findSum(intr, length(intr), q, length(q)), length(findSum(intr, length(intr), q, length(q))));
    return final_pdt;
}

int main(int argc, char **argv)
{
    char *str1 = takeInput();
    char *str2 = takeInput();
    int len1 = length(str1);
    int len2 = length(str2);
    // int i = 0;
    printf("length = %d\n", length(str1));
    printf("length = %d\n", length(str2));
    // do
    // {
    //     printf("%c <> ", str1[i]);
    //     i++;
    // } while (str1[1] != '\0');

    // char *final = findSum(str1, len1, str2, len2);
    // printf("The sum= %s\n\n", final);
    char *final = multiplyNum(str1, len1, str2, len2);
    printf("The sum= %s\n\n", final);

    return 0;
}