#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    char word[1000000];
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char Alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count[26] = {0};
    int max;
    int max_index;
    int check = 0;
    int str_len;

    scanf("%s", word);
    str_len = strlen(word);
    for (int i = 0; i < str_len; i++)
        for (int j = 0; j < 26; j++)
            if (word[i] == alpha[j] || word[i] == Alpha[j])
                count[j]++;

    max = count[0];
    max_index = 0;
    for (int i = 1; i < 26; i++)
        max = MAX(max, count[i]);

    for (int i = 0; i < 26; i++)
    {
        if (max == count[i])
        {
            check++;
            max_index = i;
        }
    }

    if (check != 1)
    {
        printf("?");
        return 0;
    }

    printf("%c", Alpha[max_index]);
    return 0;
}