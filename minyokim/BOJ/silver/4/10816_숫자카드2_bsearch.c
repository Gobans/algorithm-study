#include <stdio.h>
#include <stdlib.h>

int bin_search(int *A, int N, int a)
{
    int pl = 0;
    int pr = N - 1;
    int pc;
    int count = 0;

    while (pl <= pr)
    {
        pc = (pl + pr) / 2;
        if (A[pc] == a)
        {
            if (pc - 1 >= 0 && A[pc - 1] == a)
            {
                while (A[pc] == a)
                    pc--;
                pc += 1;
            }
            while (A[pc] == a)
            {
                pc++;
                count++;
            }
            return count;
        }
        else if (A[pc] < a)
            pl = pc + 1;
        else
            pr = pc - 1;
    }
    return 0;
}

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

    scanf("%d", &N);
    A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d", &M);
    arr = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
        scanf("%d", &arr[i]);

    qsort(A, N, sizeof(arr[0]), compare);

    for (int i = 0; i < M; i++)
        printf("%d\n", bin_search(A, N, arr[i]));

    return 0;
}