#include <stdio.h>

int N, M, K, A[10][10];

int main(void)
{
    scanf("%d %d %d", &N, &M, &K);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            scanf("%d", A[r][c]);

    return 0;
}