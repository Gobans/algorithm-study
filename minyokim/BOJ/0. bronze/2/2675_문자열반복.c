#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;
    int R;
    char str[20];

    scanf("%d", &T);
    for (int n = 0; n < T; n++)
    {
        scanf("%d %s", &R, &str);
        for (int i = 0; i < strlen(str); i++)
        {
            for (int j = 0; j < R; j++)
                printf("%c", str[i]);
        }
        printf("\n");
    }
}