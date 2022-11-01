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

    char *final = findSum(str1, len1, str2, len2);
    printf("The sum= %s\n\n", final);

    // int halfLen = len1 / 2;
    // char *left = (str1);
    // char *right = (str1 + len1 - halfLen);
    // printf("left= %s\n", left);
    // printf("right= %s\n", right);

    return 0;
}