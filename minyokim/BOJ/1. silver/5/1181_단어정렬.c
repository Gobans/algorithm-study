#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;

    if (strlen(str1) == strlen(str2))
        return strcmp(str1, str2);
    else
        return (strlen(str1) > strlen(str2));
}

int main()
{
    int n;
    char **word;

    scanf("%d", &n);
    word = (char **)malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++)
    {
        word[i] = (char *)malloc(51);
        scanf("%s", word[i]);
    }

    qsort(word, n, sizeof(char *), compare);

    printf("%s\n", word[0]);
    for (int i = 1; i < n; i++)
    {
        if (strcmp(word[i - 1], word[i]) != 0)
            printf("%s\n", word[i]);
    }
}