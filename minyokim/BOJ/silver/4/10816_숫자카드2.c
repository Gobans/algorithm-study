#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    if (n1 == n2)
        return 0;
    return (n1 - n2);
}

int main(void)
{
    int N;
    int M;
    int *A;
    int *arr;
    int bucket[20000001];

    scanf("%d", &N);
    A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        bucket[10000000 + i]++;

    arr = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
        scanf("%d", &arr[i]);

    qsort(A, N, sizeof(arr[0]), compare);

    for (int i = 0; i < M; i++)
        printf("%d\n", bin_search(A, N, arr[i]));

    return 0;
}