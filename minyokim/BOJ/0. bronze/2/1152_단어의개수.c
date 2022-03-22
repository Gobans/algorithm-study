#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000000];
    int count = 1;
    int i = 0;

    scanf("%[^\n]s", str);
    if (str[0] == ' ')
        count--;
    if (str[strlen(str) - 1] == ' ')
        count--;
    while (str[i])
    {
        if (str[i] == ' ')
            count++;
        i++;
    }
    printf("%d", count);

    return 0;
}