#include <stdio.h>
#define MAX(a, b) (a >= b ? a : b)

int main(void)
{
    int N;
    int M;
    int card[100];
    int comb[161700];
    int n = 0;
    int count = 0;
    int max;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    for (int i = 0; i < N - 2; i++)
        for (int j = i + 1; j < N - 1; j++)
            for (int k = j + 1; k < N; k++)
                if (card[i] + card[j] + card[k] <= M)
                {
                    comb[n] = card[i] + card[j] + card[k];
                    count++;
                    n++;
                }

    max = comb[0];
    for (int i = 1; i < count; i++)
        max = MAX(max, comb[i]);
    printf("%d", max);
    return 0;
}