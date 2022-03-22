#include <stdio.h>

int main(void)
{
    char word[16];
    int result = 0;
    int i = 0;
    scanf("%s", word);
    while (word[i])
    {
        if (word[i] >= 'A' && word[i] <= 'C')
            result += 3;
        if (word[i] >= 'D' && word[i] <= 'F')
            result += 4;
        if (word[i] >= 'G' && word[i] <= 'I')
            result += 5;
        if (word[i] >= 'J' && word[i] <= 'L')
            result += 6;
        if (word[i] >= 'M' && word[i] <= 'O')
            result += 7;
        if (word[i] >= 'P' && word[i] <= 'S')
            result += 8;
        if (word[i] >= 'T' && word[i] <= 'V')
            result += 9;
        if (word[i] >= 'W' && word[i] <= 'Z')
            result += 10;
        i++;
    }
    printf("%d", result);

    return 0;
}