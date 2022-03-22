#include <stdio.h>

int main(void)
{
    char word[101];
    int i = 0;
    char a;
    char b;
    int count = 0;
    int flag;

    scanf("%s", word);
    while (word[i] && word[i + 1])
    {
        a = word[i];
        b = word[i + 1];
        flag = 0;

        if (a == 'c' && (b == '=' || b == '-'))
        {
            count += 1;
            i += 2;
            flag = 1;
        }
        else if (a == 'd')
        {
            if (b == 'z' && word[i + 2] == '=')
            {
                count += 1;
                i += 3;
                flag = 1;
            }
            else if (b == '-')
            {
                count += 1;
                i += 2;
                flag = 1;
            }
        }
        else if ((a == 'l' || a == 'n') && b == 'j')
        {
            count += 1;
            i += 2;
            flag = 1;
        }
        else if ((a == 's' || a == 'z') && b == '=')
        {
            count += 1;
            i += 2;
            flag = 1;
        }
        if (flag == 0)
        {
            count += 1;
            i += 1;
        }
    }
    if (word[i] != 0)
        count++;
    printf("%d", count);
}