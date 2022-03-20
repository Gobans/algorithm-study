#include <stdio.h>

int main(void)
{
    char num1[4];
    char num2[4];

    scanf("%s%s", num1, num2);
    for (int i = 2; i >= 0; i--)
    {
        if (num1[i] == num2[i])
            continue;
        if (num1[i] > num2[i])
        {
            for (int j = 2; j >= 0; j--)
                printf("%d", num1[j] - '0');
            return 0;
        }
        else
        {
            for (int j = 2; j >= 0; j--)
                printf("%d", num2[j] - '0');
            return 0;
        }
    }
}