#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[101];
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int flag;

    scanf("%s", word);

    for (int i = 0; i < 26; i++)
    {
        flag = 0;
        for (int j = 0; j < strlen(word); j++)
        {
            if (alphabet[i] == word[j])
            {
                printf("%d ", j);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("-1 ");
    }
    return 0;
}