#include <stdio.h>
#include <string.h>

int N, strLen, t, count, flag;
char words[100][100], tmp;

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", words[i]);
        strLen = strlen(words[i]);
        flag = 0;
        for (int j = 0; j < strLen; j++)
        {
            t = j;
            while (words[i][t] == words[i][t + 1])
                t++;
            for (int k = t + 1; k < strLen; k++)
            {
                if (words[i][j] == words[i][k])
                {
                    count++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
    }
    printf("%d", N - count);
}