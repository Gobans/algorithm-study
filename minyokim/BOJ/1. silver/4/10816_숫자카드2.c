#include <stdio.h>

int bucket[20000001];

int main(void)
{
    int N;
    int M;
    int A;
    int a;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A);
        bucket[10000000 + A]++;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        printf("%d\n", bucket[10000000 + a]);
    }

    return 0;
}