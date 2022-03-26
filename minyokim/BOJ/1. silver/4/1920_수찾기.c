#include <stdio.h>
#include <stdlib.h>

int bin_search(int *A, int N, int a)
{
    int pl = 0;
    int pr = N - 1;
    int pc;

    while (pl <= pr)
    {
        pc = (pl + pr) / 2;
        if (A[pc] == a)
            return 1;
        else if (A[pc] < a)
            pl = pc + 1;
        else
            pr = pc - 1;
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b);
}

int main(void)
{
    int N;
    int M;
    int A[100000];
    int arr[100000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &arr[i]);

    qsort(A, N, sizeof(arr[0]), compare);

    for (int i = 0; i < M; i++)
        printf("%d\n", bin_search(A, N, arr[i]));

    return 0;
}