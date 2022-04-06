#include <stdio.h>

int arr[8];
int N, M;

void func(int index, int k)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = k; i <= N; i++)
    {
        arr[index] = i;
        func(index + 1, i + 1);
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    func(0, 1);
}