#include <stdio.h>

void func(int index, int *arr, int N, int M)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (index != 0 && arr[index - 1] > i)
            continue;
        arr[index] = i;
        func(index + 1, arr, N, M);
    }
}

int main(void)
{
    int N, M;
    int arr[8];

    scanf("%d %d", &N, &M);

    func(0, arr, N, M);
}